#include <cstdio>
#include <cstring>
#include <vector>
#define maxn 10000
using namespace std;
int flag[maxn],pim[maxn],tol;
int p[1229][9973];
int ni[1229][9973];
int mp[10000];
void init()
{
    tol=0;
    for(int i=2; i<maxn; i++) 
    {
        if(!flag[i])  pim[tol++]=i;
        for(int j=0; j<tol&&i*pim[j]<maxn; j++)
        {
            flag[i*pim[j]]=1;
            if(i%pim[j]==0) break;
        }
    }
    for(int i=0; i<tol; i++)
    {
        int k=pim[i];
        mp[k]=i;
        p[i][0]=1, p[i][1]=1;
        ni[i][0]=1,ni[i][1]=1;
        for(int j=2; j<k; j++) 
        {
            p[i][j]=j*p[i][j-1]%pim[i];
            ni[i][j]=-k/j*ni[i][k%j]%k;
            if(ni[i][j]<0) ni[i][j]+=k;
        }
    }
    for(int i=0; i<tol; i++) 
    {
        int k=pim[i];
        for(int j=1; j<k; j++)
        {
            ni[i][j]=ni[i][j]*ni[i][j-1]%k;
        }
    }
}
int cal(int n,int m,int v)
{
    if(n<m) return 0;
    int x=mp[v];
    return p[x][n] * ni[x][m]%v * ni[x][n-m]%v;
}
int main()
{
    int n,k,p,ca=0;
    init();
    while(scanf("%d %d %d",&n,&k,&p)==3)
    {
        if(k>n/2) k=n-k;
        int res=1,u_u=n-k;
        n++;
        while(n&&k)
        {
            res=res*cal(n%p,k%p,p)%p;
            if(res==0) break;
            n/=p;
            k/=p;
        }
        printf("Case #%d: %d\n",++ca,(res+u_u)%p);
    }
    return 0;
}
