#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int map[110][110];
int maxofmap;
int findinmap(int l,int h,int max)
{
    int i,j,p,q;
    int state=-1;
    int maxans;
    int tmp;
    for(i=0;i<max-l+1;i++)
    {
        for(j=0;j<max-h+1;j++)
        {
            tmp=0;
            for(p=0;p<l;p++)
            {
                for(q=0;q<h;q++)
                {
                    tmp+=map[1+p+i][1+q+j];
                }
            }
            if(state<0)
            {
                state++;
                maxans=tmp;
            }
            else if(tmp>maxans)
            {
                maxans=tmp;
            }
        }
    }
    return maxans;
}
void deal(int max)
{
    int l,h,tmp;
    for(l=1;l<=max;l++)
    {
        for(h=1;h<max;h++)
        {
            if((tmp=findinmap(l,h,max))>maxofmap)
            {
                maxofmap=tmp;
            }
        }
    }
    printf("%d\n",maxofmap);
}
 
 
int main()
{
    int all,n,i,j;
    scanf("%d",&all);
    for(;all>0;all--)
    {
        scanf("%d",&n);
        memset(map,0,sizeof(int)*110*110);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                scanf("%d",&map[i][j]);
            }
        }
        maxofmap=map[1][1];
        deal(n);
    }
    return 0;
}
