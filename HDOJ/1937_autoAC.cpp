#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int INF=1<<31-1;
char a[310][310];
int mmap[310][310];
int r,c,k;
void chuli()
{
    int i,j;
    for(i=1;i<=r;i++)
        mmap[i][1]=(a[i][1]=='.');
    for(j=1;j<=c;j++)
        mmap[1][j]=(a[1][j]=='.');
    for(i=1;i<=r;i++)
    {
        for(j=1;j<=c;j++)
        {
            mmap[i][j]=(mmap[i-1][j]+mmap[i][j-1]-mmap[i-1][j-1]+(a[i][j]=='.'));
        }
    }
}
int check(int x1,int y1,int x2,int y2)
{
    if(mmap[x2][y2]+mmap[x1-1][y1-1]-mmap[x1-1][y2]-mmap[x2][y1-1]>=k)
        return 0;
    else
        return 1;
}
int main()
{
    while(scanf("%d%d%d",&r,&c,&k)!=EOF)
    {
        memset(mmap,0,sizeof(mmap));
        if(r==c&&r==k&&k==0)
        {
            break;
        }
        int i,j;
        for(i=1;i<=r;i++)
             scanf("%s",a[i]+1);
        chuli();
        int t1,t2;
        int min=INF;
        for(i=1;i<=r;i++)
        {
            for(j=i;j<=r;j++)
            {
                for(t1=1,t2=1;t1<=c;t1++)
                {
                    while(check(i,t1,j,t2)==1&&t2<c)
                       {
                           t2++;
                       }
                    if(check(i,t1,j,t2)==0)
                    {
                        if(min>(j-i+1)*(t2-t1+1))
                        min=(j-i+1)*(t2-t1+1);
                    }
                }
            }
        }
        printf("%d\n",min);
    }
    return 0;
}
