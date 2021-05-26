//双链表及反置双链表的基本操作
#include<stdio.h>
#include<stdlib.h>

typedef struct LNODE {
	int data;
	struct LNODE* next;
}LNODE, * LINKLIST;

LINKLIST createlinklist(LINKLIST& L)
{
	int x;
	LNODE* p, * s;
	L = (LNODE*)malloc(sizeof(LNODE));
	L->next = NULL;
	p = L;
	printf("输入链表保存的数值: \n");
	scanf_s("%d", &x);
	while (x != 00)
	{
		s = (LNODE*)malloc(sizeof(LNODE));
		s->data = x;
		s->next = NULL;
		p->next = s;
		p = s;
		scanf_s("%d", &x);
	}
	p->next = NULL;
	return L;
}
int turnlinklist(LINKLIST L)
{
	LNODE* s, * p, * snext;
	p = L;
	s = p->next;
	p->next = NULL;
	while (s != NULL)
	{
		snext = s->next;
		s->next = p->next;
		p->next = s;
		s = snext;
	}
	return 1;
}
int* listlength(LINKLIST L)
{
	int* a;
	a = (int*)malloc(sizeof(int));
	int t = 0;
	LNODE* p;
	p = L;
	while (p != NULL)
	{
		p = p->next;
		t++;
	}
	printf("链表长度length = %d", t);
	(*a) = t;
	printf("\n");
	return a;
}
LNODE* querylist(LINKLIST L, int* a)
{
	int i;
	printf("请输入需要查询的位置:");
	scanf_s("%d", &i);
	while (i < 1 || i >(*a))
	{
		printf("查询不在范围内,请从新输入查询位置;");
		scanf_s("%d", &i);
	}
	int j = 0;
	LNODE* p;
	p = L;
	while (p != NULL && j < i - 1)
	{
		p = p->next;
		j++;
	}
	printf("该值为:%d", p->data);
	printf("\n");
	return p;
}
void insertlist(LINKLIST& L, int* a)
{
	int i, e, j = 0;
	printf("请输入插入的位置：");
	scanf_s("%d", &i);
	while (i<1 || i>(*a))
	{
		printf("当前插入的位置不在范围内，请重新输入:");
		scanf_s("%d", &i);
	}
	LNODE* p;
	p = L;
	printf("请输入插入的值: ");
	scanf_s("%d", &e);
	while (p != NULL && j < i - 1)
	{
		p = p->next;
		j++;
	}
	if (p == NULL)
		printf("错误");
	LNODE* s;
	s = (LINKLIST)malloc(sizeof(LNODE));
	s->data = e;
	s->next = NULL;
	s->next = p->next;
	p->next = s;
}
void deletelist(LINKLIST& L, int* a)
{
	int i;
	printf("请输入需要删除的结点:");
	scanf_s("%d", &i);
	while (i < 1 || i>(*a))
	{
		printf("删除的结点不在范围内，请重新输入");
		scanf_s("%d", &i);
	}
	LNODE* p;
	p = L;
	int j = 0;
	while (p != NULL && j < i - 1)
	{
		p = p->next;
		j++;
	}
	LNODE* q;
	q = p->next;
	int e = p->data;
	p->next = q->next;
	free(q);
	q->next = NULL;
}
void print(LINKLIST L)
{
	LNODE* p;
	p = L->next;
	printf("打印出：");
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
int main(void)
{
	LINKLIST L;
	createlinklist(L);
	print(L);
	turnlinklist(L);
	printf("反转后");
	print(L);
	int* a;
	a = listlength(L);
	querylist(L, a);
	insertlist(L, a);
	print(L);
	deletelist(L, a);
	print(L);
	return 1;
}