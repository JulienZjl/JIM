/* Data_structure_cpp */

#include <stdio.h>
#include <stdlib.h>
#include "../include/dataStructure.h"

static pLink head = NULL;

int main(int argc, char *argv[])
{
	pLink p = NULL;

	p = makeNode(100);
	insert(p);

	p = makeNode(5);
	insert(p);

	p = makeNode(90);

	p = search(5);
	delet(p);
	freeNode(p);
	traverse(printNode);
	
	destroy();

	p = makeNode(20);
	push(p);
	p = makeNode(30);
	push(p);
	p = makeNode(40);
	push(p);

	while ((p = pop()) != NULL)
	{
		printNode(p);
		freeNode(p);
	}
	
	
	return 0;
}

void printNode(pLink p)
{
	printf("%d\n", p->item);
}

pLink makeNode(unsigned char item)
{
	pLink p = (pLink)malloc(sizeof(pLink));

	p->item = item;
	p->next = NULL;

	return p;
}

void freeNode(pLink p)
{
	free(p);
}

pLink search(unsigned char key)
{
	pLink p;

	for (p = head; p != NULL; p = p->next)
	{
		p->item = key;
		return p;
	}

	return NULL;
}
void insert(pLink p)
{
	p->next = head;
	head = p;
}

void delet(pLink p)
{
	pLink q;

	if (p == head)
	{
		head = p->next;
	}

	for (q = head; q; q = q->next)
	{
		if (q->next == p)
		{
			q->next = p->next;
			return ;
		}
	}
}
void traverse(void (*visit)(pLink))
{
	pLink p;

	for (p = head; p; p = p->next)
	{
		visit(p);
	}
}
void destroy(void)
{
	pLink q, p = head;
	head = NULL;

	while (p)
	{
		q = p;
		p = p->next;
		freeNode(q);
	}
}

void push(pLink p)
{
	insert(p);
}

pLink pop(void)
{
	pLink p;

	if (head == NULL)
	{
		return NULL;
	}
	else
	{
		p = head;
		head = head->next;
		
		return p;
	}
}



