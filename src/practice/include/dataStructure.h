/* Data_Structure_h */

#ifndef __DATA_STRUCTURE_H__
#define __DATA_STRUCTURE_H__

typedef struct node *pLink;

struct node
{
	unsigned char item;
	pLink next;
};

void printNode(pLink p);
pLink makeNode(unsigned char item);
void freeNode(pLink p);
pLink search(unsigned char key);
void insert(pLink p);
void delet(pLink p);
void traverse(void (*visit)(pLink));
void destroy(void);
void push(pLink p);
pLink pop(void);


#endif

