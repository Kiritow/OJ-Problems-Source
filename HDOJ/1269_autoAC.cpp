#include<stdio.h>
#include<string.h>
int pre[2][100010];
int n,m;
int find(int a,int i)
{
    int r=a;
    while(r!=pre[i][r])
    {
        r=pre[i][r];
    }
    return r;
}
void fun(int a,int b)
{    
    if(a!=n)
    {
        int fa=find(a,0),fb=find(b,0);
        if(fa!=fb)
            pre[0][a]=b;
    }
    if(b!=n)
    {
        int fa=find(a,1),fb=find(b,1);
        if(fa!=fb)
            pre[1][b]=a;
    }
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF,n||m)
    {
        int i,w=1;
        for(i=0;i<=n;i++)
        {
            pre[0][i]=pre[1][i]=i;
        }
        while(m--)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            fun(a,b);
        }
        for(i=1;i<=n;i++)
        {
            if(find(i,0)!=n||find(i,1)!=n)
            {
                w=0;
                break;
            }
        }
        if(w)
            printf("Yes\n");
        else
            printf("No\n");
    }
}
