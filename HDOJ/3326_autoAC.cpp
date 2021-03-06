#include<cstdio> 
#include<iostream>
#include<cstring>
using namespace std;
int n,m[5],l[5],len;
double p[5],dp[6][3125][32];
bool f[6][3125][32];
char ans[100];
double solve(int g,int r,int mask)
{
    if(mask==0) return 1.0;
    if(f[g][r][mask]) return dp[g][r][mask];
    int a[5],c=r;
    double b[2][5],t1,t2;
    for(int i=n-1;i>=0;--i)
    {
        a[i]=c%5;
        c/=5;
    }
    for(int i=0;i<n;++i)
    {
        if(l[i]) t1=p[i]/l[i]*(l[i]-a[i]);
        else t1=0.0;
        t2=(1-p[i])/(m[i]-l[i])*(m[i]-l[i]-g+a[i]); 
        if(t1+t2<1e-8) b[0][i]=b[1][i]=0.0;
        else
        {
            b[0][i]=(1-p[i])/(m[i]-l[i])/(t1+t2);
            b[1][i]=p[i]/l[i]/(t1+t2);
        }
    }
    dp[g][r][mask]=0.0;
    for(int i=mask;;i=((i-1)&mask))
    {
        double tmp=0.0;
        int choose[5],chs=0;
        for(int j=0;j<n;++j)
        {
            if(i&(1<<j)) choose[j]=1;
            else choose[j]=0;
            if((mask&(1<<j))&&choose[j]+a[j]>l[j]) goto fuck;
            if((mask&(1<<j))&&choose[j]==0&&m[j]-l[j]-g+a[j]<=0) goto fuck;
            chs=chs*5+choose[j]+a[j];
        }
        for(int j=mask;j;j=((j-1)&mask))
        {
            double pp=1.0;
            for(int k=0;k<n;++k)
                if(j&(1<<k)) pp*=b[choose[k]][k];
                else if(mask&(1<<k)) pp*=1-b[choose[k]][k];
            tmp+=pp*solve(g+1,chs,mask-j);
        }
        dp[g][r][mask]=max(dp[g][r][mask],tmp);
        fuck:if(i==0) break;
    }
    f[g][r][mask]=1;
    return dp[g][r][mask];
}
int main()
{
    while(scanf("%d",&n)&&n)
    {
        for(int i=0;i<n;++i) scanf("%d%d%lf",m+i,l+i,p+i);
        memset(f,0,sizeof(f));
        memset(ans,0,sizeof(ans));
        sprintf(ans,"%.3lf",solve(0,0,(1<<n)-1));
        len=strlen(ans);
        while(ans[len-1]=='0')
            ans[--len]='\0';
        if(ans[len-1]=='.') ans[len-1]='\0';
        printf("%s\n",ans);
    }
}
