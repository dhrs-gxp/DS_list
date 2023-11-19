#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int Creat_List(Linklist* L, int n)
{
	int i;
	Linklist p;
	*L = (Linklist)malloc(sizeof(Node));
	if (*L == NULL) 
	{
		printf("ÄÚ´æ·ÖÅäÊ§°Ü\n");
		return -1;
	}
	(*L)->next = NULL;
	for (i = 0; i < n; i++)
	{
		p = (Linklist)malloc(sizeof(Node));
		if (p == NULL) 
		{
			printf("ÄÚ´æ·ÖÅäÊ§°Ü\n");
			return -1;
		}
		p->data.age = i + 10;
		p->next = (*L)->next;
		(*L)->next = p;
	}
	return 0;
}


void Print_List(Linklist L)
{
	Linklist p;
	p = L;
	while(p->next != NULL)
	{
		p = p->next;
		printf("%d\n",p->data.age);
	}
}

int Add_Node(Linklist L, int i, Data data)
{
	int j = 1;
	Linklist p, s;
	p = L;
	while (p != NULL && j < i)
	{
		p = p->next;
		j++;
	}
	if (p == NULL || i < j) return -1;

	s = (Linklist)malloc(sizeof(Node));
	if (s == NULL)
	{
		return -1;
	}
	s->data = data;
	s->next = p->next;
	p->next = s;
	return 0;
}

int Delete_Node(Linklist L, int i)
{
	int j = 1;
	Linklist p, q;
	p = L;
	while (p != NULL && j < i)
	{
		p = p->next;
		j++;
	}
	if (p == NULL) return -1;
	if (p->next == NULL || i < j) return -1;

	q = p->next;
	p->next = q->next;
	free(q);
	return 0;
}

int Delete_List(Linklist *L)
{
	Linklist p, q;
	p = (*L)->next;
	while (p != NULL)
	{
		q = p->next;
		free(p);
		p = q;
	}
	(*L)->next = NULL;
	return 0;
}