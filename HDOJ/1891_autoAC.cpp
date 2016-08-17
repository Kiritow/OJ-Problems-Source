#include<iostream>
using namespace std;
int a[1010][1010],c[1010][1010],n=1005;
int lowbit(int x)
{
    return x&(-x);
}
int sum(int x,int y)
{
    int i,j,sum=0;
    for(i=x;i>0;i-=lowbit(i))
    {
        for(j=y;j>0;j-=lowbit(j))
        {
            sum+=c[i][j];
        }
    }
    return sum;
}
void inster(int x,int y,int z)
{
    int i,j;
    for(i=x;i<=n;i+=lowbit(i))
    {
        for(j=y;j<=n;j+=lowbit(j))
        {
            c[i][j]+=z;
        }
    }
}
int main()
{
    int x1,y1,x2,y2,t,m,i,j,n1,f=0;
    scanf("%d",&t);
    while(t--)
    {
        printf("Case %d:\n",++f);
        memset(a,0,sizeof(a));
        memset(c,0,sizeof(c));
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
            {
                a[i][j]=1;
                inster(i,j,1);
            }
        scanf("%d",&m);
        while(m--)
        {
            char s;
            getchar();
            s=getchar();
            if(s=='S')
            {
                scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
                x1++;x2++;y1++;y2++;
                if(x1>x2)
                    swap(x1,x2);
                if(y1>y2)
                    swap(y1,y2);
                printf("%d\n",sum(x2,y2)-sum(x2,y1-1)-sum(x1-1,y2)+sum(x1-1,y1-1));
            }
            else
                if(s=='A')
                {
                    scanf("%d%d%d",&x1,&y1,&n1);
                    x1++;y1++;
                    inster(x1,y1,n1);
                    a[x1][y1]+=n1;
                }
                else
                    if(s=='D')
                    {
                        scanf("%d%d%d",&x1,&y1,&n1);
                        x1++;y1++;
                        if(n1>a[x1][y1])
                            n1=a[x1][y1];
                        inster(x1,y1,-n1);
                        a[x1][y1]-=n1;
                    }
                    else
                        if(s=='M')
                        {
                            scanf("%d %d %d %d %d",&x1,&y1,&x2,&y2,&n1);
                            x1++;y1++;x2++;y2++;
                            if(a[x1][y1]>=n1)
                            {
                                a[x1][y1]-=n1;
                                inster(x1,y1,-n1);
                                inster(x2,y2,n1);
                                a[x2][y2]+=n1;
                            }
                            else
                            {
                                inster(x1,y1,-a[x1][y1]);
                                inster(x2,y2,a[x1][y1]);
                                a[x2][y2]+=a[x1][y1];
                                a[x1][y1]=0;
                            }
                        }
        }
    }
    return 0;
}
