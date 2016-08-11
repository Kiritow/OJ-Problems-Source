#include <stdio.h>  
#define  MAXN 1010  
int seq[MAXN];  
int seqlen[MAXN];  
int main()  
{  
    int N;  
    while(scanf("%d",&N)==1)  
    {  
        int i,j,k,max,maxlen=1;  
        for(i=1; i<=N; i++)  
            seqlen[i]=1;               //seqlen数组存以第i个数为终点的最长上升序列  
        for(i=1; i<=N; i++)  
            scanf("%d",&seq[i]);       //seq数组保存序列数组  
        for (i=2; i<=N; i++)  
        {  
            max=0;  
            for (j=1; j<=i-1; j++)  
            {  
                if(seq[j]<seq[i]&&seqlen[j]>max)  //在前i-1个序列中，寻找以终点小于seq[i]的最长的子序列，即最优子状态  
                    max=seqlen[j];  
            }  
            seqlen[i]=max+1;  
            if(seqlen[i]>maxlen)           //seqlen中保存的是第i个数为终点的最长上升序列，找出这个数组中最大的值即为最优序列长度  
                maxlen=seqlen[i];  
        }  
        printf("%d\n",maxlen);  
    }  
    return 0;  
}  
