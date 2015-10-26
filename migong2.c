#include<stdio.h>
#include<conio.h> 
#include "stdlib.h" 
#include "time.h" 

 int migong[10][10]={     //设置迷宫，最外围1为墙 里边0为可走路径 1为障碍
    
	{1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,1,1,1},
    {1,0,1,1,1,1,1,0,0,1},
    {1,0,1,0,0,0,0,0,0,1},
    {1,0,0,0,1,0,1,1,1,1},
    {1,1,1,1,0,0,1,1,1,1},
    {1,0,0,0,0,1,1,1,1,1},
    {1,0,1,1,0,0,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1} 
};

   struct type
   {
     int x;
	 int y;
	 int d;
   }lj[100];  //x,y分别为垂直和水平方向

  void start()
  {
     int top=0,i,j,dir,find;//dir为设置方向(上下左右)。find为设置找不找得到路
     lj[top].x=1;
     lj[top].y=1;
     migong[1][1]=-1;
     find=0;dir=-1;

    while(top>-1)
	{
	 if(lj[top].x==8&&lj[top].y==8) 
	 { int num=0;
       printf("迷宫路径如下：\n");
       printf("start->");
       for(i=0;i<=top;i++)
	   {
        printf("(%d,%d)-> ",lj[i].x,lj[i].y);//把找到的路径输出
        num++;
        if(num%8==0)
        printf("\n");
	   } 
      printf("end!\n");
	 }

     while(dir<4&&find==0)
	 {
        dir++;
      switch(dir)
	  {
        case 0:i=lj[top].x-1; j=lj[top].y;  break;//方向为上
        case 1:i=lj[top].x;   j=lj[top].y+1;break;//方向为右
        case 2:i=lj[top].x+1; j=lj[top].y;  break;//方向为下
        case 3:i=lj[top].x;   j=lj[top].y-1;  //方向为左
	  }
        if(migong[i][j]==0)                   //如果走过之后此时0变为-1
        find=1;  //找到路可走
	 }

     if(find==1)    //判断是否找得到
	 {     
       lj[top].d=dir;  //记录移动方向
       top++;   //记录走了多少
       lj[top].x=i;
       lj[top].y=j;
       dir=-1;find=0;     //重新调整方向
       migong[i][j]=-1;
	 }
     else
	 {
       migong[lj[top].x][lj[top].y]=0;
        top--;dir=lj[top].d; //找不到的话向后退，减小步数
	 }
	}
  }

void main()
{
	int i,j;
	/*srand((unsigned)time(NULL));
  for(i=1;i<9;i++)
    for(j=1;j<9;j++)
	  {
		   
		   migong[i][j]=rand()%2;
	  }
	   for(i=0;i<10;i++)
	   {
		   migong[i][0]=1;migong[0][i]=1;migong[i][9]=1;migong[9][i]=1;
	   }*/
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
			printf("%3d",migong[i][j]);
		  printf("\n");
	}
 start();
 getch();
}
