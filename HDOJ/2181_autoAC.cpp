#include<iostream>
using namespace std; 
int i,j ,n,m,t,times,p;
char map[21][21];
char road[21],flag[21];
void DFS(int n)
{
    int k;
    times++;
    flag[n]=0;
    road[times]=n;
    if(times==20&&map[n][t])
    {  
        printf("%d:  ",p++);
        for(int kk=1;kk<=20;kk++ )       
            printf("%d ",road[kk]);
        printf("%d\n",t);
    }
    for(k=1;k<=20;k++)
    {
        if(map[n][k]==1&&flag[k])
        {
            DFS(k);
            flag[k]=k;
            times--;
        }
    }
}    
void shuru()
{for(i=1;i<=20;i++)
        for(j=1;j<=3;j++)
        {
            scanf("%d",&t);
            map[i][t]=1;
        }
}
int main()
{ 
      shuru();
        while(scanf("%d",&t),t)
        {p=1;
            times=0; 
            for(j=1;j<=20;j++)
                flag[j]=j;
            DFS(t);
        }
}
