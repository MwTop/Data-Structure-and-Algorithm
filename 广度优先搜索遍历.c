   /*广度优先搜素遍历*/
   /*给出邻接矩阵输出邻接表和广度搜索*/
#include "stdio.h"
#include "stdlib.h"
#define Maxvue 50
typedef int DataType;

typedef struct arc   //边表结点类型 
{
	int adjvex;
	struct arc* next;
}ArcNode,*ParcNode;  
typedef struct{      //顶点表结点类型 
	DataType data;
	ArcNode* head;
}VexNode;
typedef struct{     //邻接表类型  
	VexNode lists[Maxvue];
	int edges,vexs;  
}VGraph,*Adjlist;

void CreateGraph(Adjlist *g,int m[][Maxvue],int n);
void DisplayGraph(Adjlist g);
void BFSTraverse(Adjlist g);
void BFS(Adjlist g,int v,int visited[]);
int GetFirst(Adjlist g,int k);
int GetNext(Adjlist g,int k,int u);
void DFS(Adjlist g,int v,int visited[]);

void CreateGraph(Adjlist *g,int m[][Maxvue],int n)
{
	int i,j;
	ParcNode p;
	*g=(Adjlist)malloc(sizeof(VGraph));   //初始化邻接表 
	(*g)->edges=0;
	(*g)->vexs=n;
	for(i=0;i<n;i++)
     {
     	(*g)->lists[i].head=NULL;    //初始化边表头指针 
     	for(j=n-1;j>=0;j--)
     	  if(m[i][j]!=0)
     	  {
  	     	p=(ParcNode)malloc(sizeof(ArcNode));
  	     	p->adjvex=j;
  	     	p->next=(*g)->lists[i].head;
  	     	(*g)->lists[i].head=p;
  	     	(*g)->edges++;
  	     }
     }
} 

/*显示邻接表*/
void DisplayGraph(Adjlist g)
{
	int i;
	ParcNode p;
	for(i=0;i < g->vexs;i++)
	{
		printf("\n Line %d:\t",i);
		p=g->lists[i].head;
		while(p!=NULL)
		{
			printf("[%d]\t",p->adjvex);
			p=p->next;
		}
	}
} 

void BFSTraverse(Adjlist g)
{
	int i;
	int visited[Maxvue];
	for(i=0;i<g->vexs;i++)
	   visited[i]=0;
    for(i=0;i<g->vexs;i++)
       if(!visited[i])
       BFS(g,i,visited);
}

void BFS(Adjlist g,int v,int visited[])
{/*g为邻接矩阵，v为起始点，visited为标识数组*/ 
   int u;
   int queue[Maxvue];
   int front=0,rear=0;
   int w;
   printf("%d ",g->lists[v].data);
   visited[v]=1;
   queue[rear]=v;
   rear=(rear+1)%Maxvue;
   while(front<rear)
   {
   	u=queue[front];
   	front=(front+1)%Maxvue;
   	w=GetFirst(g,u);      //取第一个邻接点 
   	while(w !=-1){
   	  if(visited[w]==0)
		 {
 			printf("%d ",g->lists[w].data);
 			visited[w]=1;
 			queue[rear]=w;
 			rear=(rear+1)%Maxvue;
 		}  	
 		w=GetNext(g,u,w);   //取下一个邻接点 
      }
   }   	
}

int GetFirst(Adjlist g,int k)
{
	if(k<0||k>g->vexs)
	  {printf("k超出范围！\n");return -1;}
    if(g->lists[k].head==NULL) return -1;
    else return g->lists[k].head->adjvex;
} 

int GetNext(Adjlist g,int k,int u)
{
	ParcNode p;
	if(k<0 || k>g->vexs || u>g->vexs)
	{printf("k超出范围！\n");return -1;}
	p=g->lists[k].head;
	while(p->next!=NULL && p->adjvex!=u) 
	   p=p->next;
	   if(p->next==NULL) return -1;
	   else return p->next->adjvex; //指向下一个邻接点 
}

void DFS(Adjlist g,int v,int visited[])
{
   	
}

int main()
{
	Adjlist g;
	int i,n;
	int m[][Maxvue]={
		             {0,1,1,0,0,0},
					 {0,0,1,0,1,0},
					 {0,0,0,0,0,0},
					 {0,0,1,0,0,1},
					 {0,0,0,0,0,0},
					 {0,0,0,0,0,0}};
					 
    printf("input node 'n':");
    scanf("%d",&n);
    CreateGraph(&g,m,n);
	for(i=0;i<g->vexs;i++)  g->lists[i].data=i;
	DisplayGraph(g);
	printf("\n广度优先搜索序列：\n");
	BFSTraverse(g);
	printf("\n\n");
	printf("\n深度优先搜索序列：\n");
	DFS(g,) 
	return 0;	
} 
