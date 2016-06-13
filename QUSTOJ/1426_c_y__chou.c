#include <stdio.h>
#include <string.h>
int train[361];
int machine[19][19];
int time[19][19];
int used[19];
int finished[19];
char cpu[19][361];
int main(void)
{
    int i,j,k;
    int m,n;
    int t;
    int ans;
    scanf("%d%d",&m,&n);
    for(i=0;i<m*n;i++)
    {
        scanf("%d",&train[i]);
        train[i]--;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
    {
            scanf("%d",&machine[i][j]);
            machine[i][j]--;
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
    {
            scanf("%d",&time[i][j]);
        }
    }
    ans = 0;
    for(i=0;i<m*n;i++)
    {
        t=train[i];
        j=finished[t]-1;        //　　因为当查找失败时，j的值需要向前增一，
        do{                //所以在赋值的时候就减了一，然后用do-while
            j++;            //的形式，一进来就对j递增。
            for(k=0;k<time[t][used[t]];k++)
               {
                if(cpu[machine[t][used[t]]][j+k]){
                    j=k+j;    //　　在最开始我就错在这行代码j = k + j
                    break;        //的位置上，我把位置放在while(..)的上面，
                }            //也就导致了在有时候选择了处理器新的位置
            }                //时在底下的memset功能工作不正常。因为我
                            //是使用的finished而不是j，则在选择了位置
                            //之后会导致一些预想不到的问题。
        }while(cpu[machine[t][used[t]]][j]);
        memset(cpu[machine[t][used[t]]]+j,t+1,time[t][used[t]]);
        if(ans<j+time[t][used[t]])
         {
            ans=j+time[t][used[t]];
        }
        finished[t]=j+k;
        used[t]++;
    }
                            //　　最后还来一点注释，我把求ans集成
                            //到了主循环里面，牺牲了一些可读性，对
                            //各位朋友说声Sorry..
    printf("%d\n",ans);
    return 0;
}
