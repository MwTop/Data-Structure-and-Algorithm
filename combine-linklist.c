#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int date;
	struct Node *next;
}linklist;

linklist *creat_link( void );
linklist *combine( linklist *, linklist * );
void print( linklist * );

int main ( void )
{
	linklist *A,*B,*C;
	A=creat_link();
	B=creat_link();
	C=combine(A,B);
	print(C);
	return 0;
}

linklist *creat_link( void )
{
	int i,n;
	linklist *head;
	linklist *p;
	printf("请输入一个链表长度:");
	scanf("%d",&n);
	head=(linklist *)malloc(sizeof(linklist));
	head->date=n;
	head->next=NULL;
	for(i=1;i<=n;i++)
	{
		p=(linklist *)malloc(sizeof(linklist));
		p->next=head->next;
		head->next=p;
		p->date=i;
	}
	return head;
}
linklist *combine( linklist *A , linklist *B )
{
	linklist *head,*p,*q,*change;
	if(A->date<B->date)
	{	head=B;
	    p=B->next;
	    q=A->next;
	}
	else
	{
       head=A;
       p=A->next;
       q=B->next;
	}
	while(p->next)
	{
		change=q;
		q=q->next;
		change->next=p->next;
		p->next=change;
		p=p->next->next;
	}
	p->next=q;
	return head;
}
void print( linklist *head )
{
	linklist *p;
	printf("\n\n输出之后为：\n");
	for(p=head->next;p;p=p->next)
		printf("%4d",p->date);
		printf("\n");
}
