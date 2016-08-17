#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<iostream>
#include<queue>
#include<map>
#include<vector>
using namespace std;
#define N 1005*1005
#define RN 1005
#define M 1005
struct DLX
{
    int n,m,C;
    int U[N],D[N],L[N],R[N],Row[N],Col[N];
    int H[M],S[M],cnt,ans[M];
    void init(int _n,int _m)
    {
        n=_n;
        m=_m;
        for(int i=0; i<=m; i++)
        {
            U[i]=D[i]=i;
            L[i]=(i==0?m:i-1);
            R[i]=(i==m?0:i+1);
            S[i]=0;
        }
        C=m;
        for(int i=1; i<=n; i++) H[i]=-1;
    }
    void link(int x,int y)
    {
        C++;
        Row[C]=x;
        Col[C]=y;
        S[y]++;
        U[C]=U[y];
        D[C]=y;
        D[U[y]]=C;
        U[y]=C;
        if(H[x]==-1) H[x]=L[C]=R[C]=C;
        else
        {
            L[C]=L[H[x]];
            R[C]=H[x];
            R[L[H[x]]]=C;
            L[H[x]]=C;
        }
    }
    void del(int x)
    {
        R[L[x]]=R[x];
        L[R[x]]=L[x];
        for(int i=D[x]; i!=x; i=D[i])
        {
            for(int j=R[i]; j!=i; j=R[j])
            {
                U[D[j]]=U[j];
                D[U[j]]=D[j];
                S[Col[j]]--;
            }
        }
    }
    void rec(int x)
    {
        for(int i=U[x]; i!=x; i=U[i])
        {
            for(int j=L[i]; j!=i; j=L[j])
            {
                U[D[j]]=j;
                D[U[j]]=j;
                S[Col[j]]++;
            }
        }
        R[L[x]]=x;
        L[R[x]]=x;
    }
    int dance(int x)
    {
        if(R[0]==0 || R[0]>16)
        {
            cnt=x;
            return 1;
        }
        int now=R[0];
        for(int i=R[0]; i!=0 && i<=16; i=R[i])
        {
            if(S[i]<S[now]) now=i;
        }
        del(now);
        for(int i=D[now]; i!=now; i=D[i])
        {
            ans[x]=Row[i];
            for(int j=R[i]; j!=i; j=R[j]) del(Col[j]);
            if(dance(x+1)) return 1;
            for(int j=L[i]; j!=i; j=L[j]) rec(Col[j]);
        }
        rec(now);
        return 0;
    }
} dlx;
struct node
{
    int m,id;
    int w[44];
} kx[1234];
int main()
{
    int n;
    while(scanf("%d",&n),n)
    {
        int cnt=0;
        dlx.init(n*16,16+n);
        for(int i=1; i<=n; i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            char v[12][12];
            for(int j=0; j<a; j++) scanf("%s",v[j]);
            for(int xx=1; xx+a<=5; xx++)
            {
                for(int yy=1; yy+b<=5; yy++)
                {
                    cnt++;
                    kx[cnt].m=0;
                    kx[cnt].id=i;
                    for(int x=0; x<a; x++)
                    {
                        for(int y=0; y<b; y++)
                        {
                            if(v[x][y]=='1')
                            {
                                int tep=(xx+x-1)*4+(yy+y);
                                dlx.link(cnt,tep);
                                kx[cnt].w[kx[cnt].m++]=tep;
                            }
                        }
                    }
                    dlx.link(cnt,16+i);
                }
            }
        }
        int f=dlx.dance(0);
        if(f==0) puts("No solution possible");
        else
        {
            char mp[10][10];
            for(int i=0;i<dlx.cnt;i++)
            {
                for(int j=0;j<kx[dlx.ans[i]].m;j++)
                {
                    int x,y;
                    x=(kx[dlx.ans[i]].w[j]-1)/4;
                    y=kx[dlx.ans[i]].w[j]%4-1;
                    if(y==-1) y=3;
                    mp[x][y]=kx[dlx.ans[i]].id+'0';
                }
            }
            for(int i=0;i<4;i++)
            {
                mp[i][4]='\0';
                puts(mp[i]);
            }
        }
        puts("");
    }
    return 0;
}
