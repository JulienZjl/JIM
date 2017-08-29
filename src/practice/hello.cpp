#include <stdio.h>

int main()
{
	printf("Hello world!\n");
	printf("This is a test!\n");

	return 0;
}



unsigned char drvif_inprocvideo_setup(void)
{
	unsigned short display = Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY);
//	unsigned short type = Scaler_InputSrcGetMainChType();

#ifdef BUILD_TV033_1_ATV
	
		unsigned short uwColorStd = _MODE_576I;
		unsigned int ulIVCount = 0;
		unsigned int ulLoopCount = 20;
		unsigned int i = 0;
		
	
		// Get color std		
		uwColorStd = Scaler_DispGetInputInfo(SLR_INPUT_MODE_CURR);
		printf("oliver+ colorstd=%d, aspect ratio=%d\n", Scaler_DispGetInputInfo(SLR_INPUT_MODE_CURR), Scaler_DispGetInputInfo(SLR_INPUT_ASPECT_RATIO));
#endif

	drvif_mode_offlinemeasure(_OFFLINE_MS_SRC_VDC, ANALOG_MODE_MEASUREMENT);

#ifdef BUILD_TV033_1_ATV
	if(drvif_module_vdc_ReadMode(VDC_DETECT) == drvif_module_vdc_ReadMode(VDC_SET))
	{
		// If offline measure fail, measure again.(max 20 times, for 576i)
		ulIVCount = Scaler_ModeGetModeInfo(SLR_MODE_IVCOUNT);

		// Offline measure value doesn't match color standard
		if (_MODE_576I == uwColorStd && (ulIVCount < 300 || ulIVCount > 330) )
		{
			for ( i = 0; i < ulLoopCount; i++)
			{
				//ScalerTimer_DelayXms(100);
				Rt_Sleep(100);
				drvif_mode_offlinemeasure(_OFFLINE_MS_SRC_VDC, ANALOG_MODE_MEASUREMENT);

				ulIVCount = Scaler_ModeGetModeInfo(SLR_MODE_IVCOUNT);

				printf("Oliver+ offline measure times=%d, IVCount=%d\n", i, ulIVCount);

				if (ulIVCount > 300 && ulIVCount < 330)
					break;

			}
			
		}		
	}
#endif		

	Scaler_DispSetInputInfo(SLR_INPUT_V_LEN,Scaler_ModeGetModeInfo(SLR_MODE_IVLEN));	// hsliao 20090519, pass IVTotal to calculate dclk
	Scaler_DispSetInputInfo(SLR_INPUT_H_FREQ,Scaler_ModeGetModeInfo(SLR_MODE_IHFREQ));
	Scaler_DispSetInputInfo(SLR_INPUT_V_FREQ,Scaler_ModeGetModeInfo(SLR_MODE_IVFREQ));

  //forster modified 061228
	drvif_inprocvideo_config_capture(display, Scaler_DispGetInputInfo(SLR_INPUT_MODE_CURR));

	//enable interlace flag
	Scaler_DispSetStatus((SCALER_DISP_CHANNEL)display,SLR_DISP_INTERLACE, TRUE);
	Scaler_DispSetStatus((SCALER_DISP_CHANNEL)display, SLR_DISP_422, FALSE);
	

     //shangmeng_xu_ADD at 20120807

#ifdef CONFIG_ENABLE_3BUFFER_NEW_RULE
	if(_ENABLE == Scaler_Get_Vflip_Enable())
	{
		Scaler_DispSetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_VFLIP3, TRUE);
	}
	else// if(_DISABLE == Scaler_Get_Vflip_Enable())
	{
		if(_ENABLE == Scaler_Set_Enable_3Buffer_NewRuleCondition((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), Scaler_InputSrcGetMainChType()))
			Scaler_DispSetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_VFLIP3, TRUE);
		else// if(_DISABLE == Scaler_Set_Enable_3Buffer_NewRuleCondition((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), Scaler_InputSrcGetMainChType()))
			Scaler_DispSetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_VFLIP3, FALSE);
	}
#else //#ifdef CONFIG_ENABLE_3BUFFER_NEW_RULE
	if (Scaler_Get_Vflip_Enable())
		Scaler_DispSetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_VFLIP3, TRUE);
#endif //#ifdef CONFIG_ENABLE_3BUFFER_NEW_RULE

	return TRUE;
}


