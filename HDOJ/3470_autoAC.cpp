#include <stdio.h>
#include <cstring>
#include <algorithm>
#define maxn 1000010
using namespace std;
typedef long long LL;
int width,height,n;
int L,R,U,D,v;
bool diffx,diffy;
int idx[maxn],idy[maxn];
char ch[10];
void init(int id[],int n)
{
    id[0]=id[n]=0;
    for (int i=1;i<n;i++)
        id[i]=1;
}
int fold(int id[], int &L, int &R, int v, bool &diff)
{
    bool dir=false;
    int ret;
    v+=L;
    ret=id[v];
    if (abs(L-v)>abs(R-v)) diff=!diff,dir=true;
    for (int x=v,y=v;x!=L&&y!=R;x--,y++)
    {
        if (!dir)
        {
            id[y]+=id[x];
            id[x]=0;
        }
        else
        {
            id[x]+=id[y];
            id[y]=0;
        }
    }
    if (!dir) L=v;
    else R=v;
    return ret;
}
int main()
{
    int test;
    scanf("%d",&test);
    for (int ii=1;ii<=test;ii++)
    {
        scanf("%d%d",&width,&height);
        scanf("%d",&n);
        diffx=diffy=0;
        L=D=0;U=height;R=width;
        init(idx,width);
        init(idy,height);
        LL ans=0;
        for (int i=1;i<=n;i++)
        {
            scanf("%s%d",ch,&v);
            if (ch[0]=='L'||ch[0]=='R')
            {
                if (diffx) v=R-L-v;
                if (!diffx && ch[0]=='R') diffx=!diffx;
                if (diffx && ch[0]=='L') diffx=!diffx;
                ans+=(LL)height*fold(idx, L, R, v, diffx);
            }
            else
            {
                if (diffy) v=U-D-v;
                if (!diffy && ch[0]=='U') diffy=!diffy;
                if (diffy && ch[0]=='D') diffy=!diffy;
                ans+=(LL)width*fold(idy, D, U, v, diffy);
            }
        }
        printf("Case %d: %I64d\n",ii,ans);
    }
    return 0;
}
