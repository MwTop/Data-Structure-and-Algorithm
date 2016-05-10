#include <stdio.h>
#include<stdlib.h>

int main(void)
 {
	int num,**array,i,j,k,m;
	printf("请输入站点数:");
	scanf("%d",&num);
    array=(int **)malloc((num+1)*sizeof(int *));

	for(i=1;i<=num;i++)
		array[i]=(int *)malloc((num+1)*sizeof(int *));
    	for(i=1;i<=num;i++)
			array[i][i] = 0;

		//输入数据循环

		for(i=1;i<num;i++)
			for(j=i+1;j<=num;j++)
			{
			    printf("请输入从站点%d到站点%d的金额:",i,j);
				scanf("%d",&array[i][j]);
			}

	    for(i=2;i<=num;i++)
			 for(j=i+1;j <= num; j++)
			 {
			     k=j-i;
				 for(m =k;m<j;m++)
					 if((array[k][m]+array[m][j])<array[k][j])
						 array[k][j] =array[k][m]+array[m][j];
			 }
			 printf("%d\n",array[1][num]);    //输出始终是数组（1，num）的值
			 return 0;
		 }
