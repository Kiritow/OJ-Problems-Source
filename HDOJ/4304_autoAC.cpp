#include <cstdio>
#include <cstring>
int coef[20],delt[20],inx[20],base[20];
int mark[1000010],pri[1000010],priN;
__int64 dp[2000][20];
void init()
{
    int i,j;
    for(i=2; i<=1000000; i++) mark[i]=i;
    for(i=2; i<=1000000; i++)
    {
        if(mark[i]==i) pri[priN++]=i;
        for(j=0; j<priN&&i*pri[j]<=1000000; j++)
        {
            mark[i*pri[j]]=pri[j];
            if(i%pri[j]==0) break;
        }
    }
}
void deal()
{
    __int64 u,ans,num,t,tmpv;
    int cnt,i,j,k,l,prod,tot,amn,m;
    scanf("%I64d", &u);
    for(cnt=0,num=u; num-1;)
    {
        if(num>1000000)
        {
            t=num;
            for(j=0; j<priN; j++)
            {
                if(num%pri[j]==0)
                {
                    t=pri[j];
                    break;
                }
            }
        }
        else t=mark[num];
        inx[cnt]=0;
        while(num%t==0) num/=t,inx[cnt]++;
        cnt++;
    }
    for(tot=0,prod=1,i=cnt-1; i>=0; i--)
    {
        tot+=inx[i],base[i]=prod,prod*=(inx[i]+1);
    }
    for(i=0; i<=tot; i++) for(j=0; j<prod; j++) dp[j][i]=0;
    dp[0][0]=1;
    for(i=1; i<prod; i++)
    {
        for(j=0; j<cnt; j++) delt[j]=i/base[j]%(inx[j]+1);
        for(j=prod-1; j>=0; j--)
        {
            amn=0x3fffffff;
            for(k=0; k<cnt; k++)
            {
                coef[k]=j/base[k]%(inx[k]+1);
                if(delt[k])
                {
                    tmpv=(inx[k]-coef[k])/delt[k];
                    if(tmpv<amn) amn=tmpv;
                }
            }
            for(l=1; l<=amn; l++)
            {
                for(k=0; k+l<=tot; k++)
                {
                    tmpv=dp[j][k];
                    for(m=1; m<=l; m++) tmpv*=m+k,tmpv/=m;
                    dp[j+i*l][k+l]+=tmpv;
                }
            }
        }
    }
    for(ans=dp[prod-1][tot]*dp[prod-1][tot],i=0; i<tot; i++)
    {
        ans+=(dp[prod-1][i]+dp[prod-1][i+1])*(dp[prod-1][i]+dp[prod-1][i+1]);
    }
    printf("%I64d\n", ans);
}
int main()
{
    init();
    int t;
    scanf("%d", &t);
    while(t--) deal();
    return 0;
}
