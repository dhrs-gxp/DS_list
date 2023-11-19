#pragma once

typedef struct {
	int age;
} Data;

typedef struct node {
	Data data;
	struct node* next;
} Node, * Linklist;


int Creat_List(Linklist* L, int n);
void Print_List(Linklist L);
int Add_Node(Linklist L, int i, Data data);
int Delete_Node(Linklist L, int i);
int Delete_List(Linklist* L);
int Delete_List(Linklist* L);