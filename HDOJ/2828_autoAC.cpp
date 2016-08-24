#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=1010,maxm=510;
const int maxnode=maxn*maxm;
const int INF=0x3f3f3f3f;
int n,m;
bool flag;
struct DLX
{
    int n,m,size;
    int U[maxnode],D[maxnode],R[maxnode],L[maxnode],Row[maxnode],Col[maxnode];
    int H[maxn],S[maxm];
    int ansd,ans[maxn];
    int LAMP[maxn];
    bool vis[maxn];
    void init(int _n,int _m)
    {
        n=_n; m=_m;
        for(int i=0;i<=m;i++)
        {
            S[i]=0; U[i]=D[i]=i;
            L[i]=i-1; R[i]=i+1;
        }
        R[m]=0; L[0]=m;
        size=m;
        for(int i=1;i<=n;i++)
        {
            vis[i]=false;
            LAMP[i]=0;
            H[i]=-1;
        }
        flag=false;
    }
    void Link(int r,int c)
    {
        ++S[Col[++size]=c];
        Row[size]=r;
        D[size]=D[c];
        U[D[c]]=size;
        U[size]=c;
        D[c]=size;
        if(H[r]<0) H[r]=L[size]=R[size]=size;
        else
        {
            R[size]=R[H[r]];
            L[R[H[r]]]=size;
            L[size]=H[r];
            R[H[r]]=size;
        }
    }
    void remove(int c)
    {
        for(int i=D[c];i!=c;i=D[i])
            L[R[i]]=L[i],R[L[i]]=R[i];
    }
    void resume(int c)
    {
        for(int i=U[c];i!=c;i=U[i])
            L[R[i]]=R[L[i]]=i;
    }
    void Dance(int d)
    {
        if(flag) return ;
        if(R[0]==0)
        {
            for(int i=0;i<d;i++)
            {
               int lamp=(ans[i]+1)/2;
               if(ans[i]%2) LAMP[lamp]=1;
            }
            for(int i=1;i<=n/2;i++)
            {
                if(LAMP[i]==1) printf("ON");
                else printf("OFF");
                if(i!=n/2) putchar(32); else putchar(10);
            }
            flag=true;
            return ;
        }
        int c=R[0];
        for(int i=R[0];i!=0;i=R[i])
        {
            if(S[i]<S[c]) c=i;
        }
        for(int i=D[c];i!=c;i=D[i])
        {
            if(vis[Row[i]]) continue;
            int r1=Row[i],r2=Row[i];
            if(r1%2==0) r2--;else r2++;
            vis[r1]=true; vis[r2]=true;
            remove(i);
            for(int j=R[i];j!=i;j=R[j]) remove(j);
            ans[d]=Row[i];
            Dance(d+1);
            for(int j=L[i];j!=i;j=L[j]) resume(j);
            resume(i);
            vis[r1]=false; vis[r2]=false;
        }
    }
};
DLX dlx;
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        dlx.init(2*m,n);
        for(int i=1;i<=n;i++)
        {
            int k;
            scanf("%d",&k);
            for(int j=0;j<k;j++)
            {
                int p; char sw[20];
                scanf("%d%s",&p,sw);
                if(sw[1]=='N') dlx.Link(2*p-1,i);
                else if(sw[1]=='F') dlx.Link(2*p,i);
            }
        }
        dlx.Dance(0);
        if(flag==false) puts("-1");
    }
    return 0;
}
