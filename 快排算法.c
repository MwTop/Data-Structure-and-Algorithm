#include <stdio.h>
#include "math.h"
#include "stdlib.h"
#include "time.h"
#define M 900
#define N 900

void sort(int *a, int left, int right)
{
	int i=left;
    int j=right;
    int key=a[left];
    if(left >= right)/*如果左边索引大于或者等于右边的索引就代表已经整理完成一个组了*/
    {
        return ;
    }
     
    while(i < j)                               /*控制在当组内寻找一遍*/
    {
        while(i < j && key <= a[j])
        /*而寻找结束的条件就是，1，找到一个小于或者大于key的数（大于或小于取决于你想升
        序还是降序）2，没有符合条件1的，并且i与j的大小没有反转*/ 
        {
            j--;/*向前寻找*/
        }
         
        a[i] = a[j];
        /*找到一个这样的数后就把它赋给前面的被拿走的i的值（如果第一次循环且key是
        a[left]，那么就是给key）*/
         
        while(i < j && key >= a[i])
        /*这是i在当组内向前寻找，同上，不过注意与key的大小关系停止循环和上面相反，
        因为排序思想是把数往两边扔，所以左右两边的数大小与key的关系相反*/
        {
            i++;
        }
         
        a[j] = a[i];
    }
     
    a[i] = key;/*当在当组内找完一遍以后就把中间数key回归*/
    sort(a, left, i - 1);/*最后用同样的方式对分出来的左边的小组进行同上的做法*/
    sort(a, i + 1, right);/*用同样的方式对分出来的右边的小组进行同上的做法*/
                       /*当然最后可能会出现很多分左右，直到每一组的i = j 为止*/
}

void main()
{
    int a[M]={0};
	int n,i;
	printf("请输入需要进行排序的数字数目：");
	scanf("%d",&n);
	srand((unsigned)time(NULL));

	printf("\n原来的数字顺序为：\n");
	for(i=0;i<n;i++)
	{
	   	a[i]=rand()%1000+1;
		printf("%4d",a[i]);
	}
	printf("\n");
    sort(a,0,n-1);
	printf("经过排序后的结果为：\n");
    for(i=0;i<n;i++)
	{
		printf("%4d",a[i]);
	}
    	printf("\n");

}
