 #include <stdio.h>     
        
  void greedy(int d[],int n,int k) {     
       int num = 0;  
	   int s = 0;
	   int i;
        for(i= 0;i <= k;i++) {     
            if(d[i] > n) {     
                printf("no solution\n");     
                return;     
            }     
        }
		
        for(i = 0;i <= k;i++) {     
            s += d[i];     
            if(s > n) {     
               num++;     
               s = d[i];     
            }     
        }     
        printf("%d\n",num);     
    }     
             
             
    int main() {     
        int i,n,k;     
        int d[1000];     
        scanf("%d %d",&n,&k);     
        for(i = 0;i <= k;i++)     
            scanf("%d",&d[i]);     
        greedy(d,n,k);     
    }    
