#include<stdio.h>
int H[2][2]={{1,1},{1,-1}};
long long dfs(long long x,long long y)
{
    if(x<2&&y<2)return H[x][y];
    int i=0,j=0;
    if(x>=2)
    {
        i=1;
        while(i*2<=x)
            i*=2;
        x-=i;
    }
    if(y>=2)
    {
        j=1;
        while(j*2<=y)
            j*=2;
        y-=j;
    }
    if(i==j)return -dfs(x,y);
    else if(i>j)return dfs(x,y+j);
    else return dfs(x+i,y);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long n,x,y,w,h,i,j;
        scanf("%I64d%I64d%I64d%I64d%I64d",&n,&x,&y,&w,&h);
        for(i=y;i<y+h;i++)
        {
            for(j=x;j<x+w-1;j++)
                printf("%d ",dfs(i,j));
            printf("%d\n",dfs(i,j));
        }
        printf("\n");
    }
    return 0;
}
