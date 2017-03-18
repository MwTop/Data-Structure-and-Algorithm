#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct polyn
{
    int coef;
	int expn;
	struct polyn *next;
}polynomial;

polynomial *create();
void printpolyn(polynomial *);
 addpolyn(polynomial *,polynomial *);
 subtractpolyn(polynomial *pa,polynomial *pb);
 /*multipolyn(polynomial *pa,polynomial *pb);
polyn daopolyn(polyn pa);*/
 int flag=1;
int main(void)
{
   polynomial *pa,*pb,*pc,*pd;
   int m;
  pa=create();
  pb=create();
  printf("pa=");
  printpolyn(pa);
  printf("pb=");
  printpolyn(pb);
  do
  {
  	printf("1.两个多项式相加\n");
	printf("2.两个多项式相减\n");
//	printf("3.两个多项式相乘\n");
	printf("0.退出\n"); 
	printf("\n输出选择m：");
	scanf("%d",&m);
	switch(m)
	{
		case 1:pc=addpolyn(pa,pb);
		       printpolyn(pc);
			   break;
		case 2:pd=subtractpolyn(pa,pb);
               printpolyn(pd);
		       break;
       // case 3:multipolyn(pa,pb);
	}
  }while(m!=0); 
  	 
   
  
  return 0;
}
 addpolyn(polynomial *pa,polynomial *pb)
{
   polynomial *qa=pa->next;
   polynomial *qb=pb->next;
   polynomial *headc,*pc,*qc;
   pc=(polynomial *)malloc(sizeof(polynomial));
   pc->next=NULL;
   headc=pc;
   while(qa!=NULL&&qb!=NULL)
   {
     qc=(polynomial *)malloc(sizeof(polynomial));
	 if(qa->expn<qb->expn)
   	  {
  	   	qc->coef=qa->coef;
  	   	qc->expn=qa->expn;
  	   	qa=qa->next;
  	   }
  	   else if(qa->expn==qb->expn)
  	   {
   	  	qc->coef=qa->coef+qb->coef;
   	  	qc->expn=qa->expn;
   	  	qa=qa->next;
   	  	qb=qb->next;
   	  }
   	  else
   	  {
  	   	qc->coef=qb->coef;
  	   	qc->expn=qb->expn;
  	   	qb=qb->next;
  	   }
  	   if(qc->coef!=0)
  	   {
   	  	qc->next=pc->next;
   	  	pc->next=qc;
   	  	pc=qc;
   	  }
   	  else free(qc);
   }
   while(qa !=NULL)
   {
   	qc=(polynomial *)malloc(sizeof(polynomial));
   	qc->coef=qa->coef;
   	qc->expn=qa->expn;
   	qa=qa->next;
   	qc->next=pc->next;
  	pc->next=qc;
 	pc=qc;
   }
   while(qb !=NULL)
   {
   	qc=(polynomial *)malloc(sizeof(polynomial));
   	qc->coef=qb->coef;
   	qc->expn=qb->expn;
   	qb=qb->next;
   	qc->next=pc->next;
  	pc->next=qc;
 	pc=qc;
   }
   printf("pc=");
   return headc;
   	
}
 subtractpolyn(polynomial *pa,polynomial *pb)
 {
 	 polynomial *h=pb;
 	  polynomial *p=pb->next;
 	   polynomial *pm;
 	   while(p)
 	   {
   	 	p->coef*=-1;
   	 	p=p->next;	
   	 }
   	 pm=addpolyn(pa,h);
   	 for(p=h->next;p;p=p->next)
   	 p->coef*=-1;
   	 return pm;
   	 
 }
 /*multipolyn(polynomial *pa,polynomial *pb)
 {
 	 polynomial *p,*q,*m,*r,*s,*t;
 	 m=pa->next;
 	 q=pb->next;
 	 p=m;
 	 r=(polynomial *)malloc(sizeof(polynomial));
 	 t=(polynomial *)malloc(sizeof(polynomial));
		 t->coef=0;
		 t->expn=0;
 	 r->next=NULL;
 	 while(p!=NULL&&q!=NULL)
 	 {
 	    s=(polynomial *)malloc(sizeof(polynomial));
		 while(p!=NULL)
		 {
 			s->coef=p->coef*q->coef;
 			s->expn=p->expn+q->expn;
 			p=p->next;
 			if(s->coef!=0)
 			{
			 	s->next=r->next;
			 	r->next=s;
			 	r=s;
			 }
 			
 		 }
 		p=m;
		 q=q->next;
		 t=addpolyn(s,t);
		 /*while(p!=NULL)
		 {
 			t->coef=p->coef*q->coef;
 			t->expn=p->expn+q->expn;
 			p=p->next;
 			if(t->coef!=0)
 			{
			 	t->next=r->next;
			 	r->next=t;
			 	r=t;
			 }
		 	
 	    }
 	    p=m;
 	    q=q->next;
   	 
 	 }
 	 printpolyn(t);
 	 return 0; 
 }*/
polynomial *create()
{
	int c=0,e;
	polynomial *head,*rear,*s;
	head=(polynomial *)malloc(sizeof(polynomial));
	rear=head;/*rear指向链表尾，便于尾插*/
	printf("请输入多项式的系数和指数，系数为零则结束输入：\n");
	scanf("%d %d",&c,&e);
	while(c!=0)
	{
		s=(polynomial *)malloc(sizeof(polynomial));
		s->coef = c;
		s->expn = e;
		rear->next=s;
		rear=s;
		scanf("%d %d",&c,&e);
	} 
	rear->next=NULL;
	return(head);
}
void printpolyn(polynomial *p)
{
	polynomial *q;
	 q=p->next;
	if(!q)
	{
		printf("0");
		printf("\n");
	}
	while(q)
	{  
 	    if(q->coef>0 && flag!=1)  putchar('+');
		if(q->coef!=1&&q->coef!=-1) 
		{
			printf("%d",q->coef);
			if(q->expn==1) putchar('X');
			else if(q->expn) printf("X^%d",q->expn);  
		}
		else
		{
			if(q->coef==1) 
			{
				if(q->expn==0) putchar('1');
			    else if(q->expn==1) putchar('X');
				 else  printf("X^%d",q->expn);
			}
			if(q->coef==-1)
			{
				if(q->expn==0) printf("-1");
				else if(q->expn==1) printf("-X");
				else printf("-X^%d",q->expn);
			}
		}
		q=q->next;
		flag++;
	}
	printf("\n");
}


