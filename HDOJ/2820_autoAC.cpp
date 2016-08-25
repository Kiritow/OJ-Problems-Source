#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long LL;
const LL PP=1000000007;
const int P=10007;
struct Node
{
    int len;
    int va[12];
};
LL dp[2][110000];
Node ST[2][110000];
struct Edge{int ne,id;Node st;}e[110000];
int p[P+10],mod[P+10],Hashnum;
void Hashinit()
{
    memset(p,-1,sizeof(p));
    memset(mod,0,sizeof(mod));
    Hashnum=0;
}
int find(Node st,int re)
{
    if(mod[re])
    {
        for(int i=p[re];i!=-1;i=e[i].ne)
        {
            if(e[i].st.len!=st.len)continue;
            for(int j=0;j<st.len;j++)
            if(e[i].st.va[j]!=st.va[j])continue;
            return e[i].id;
        }
    }
    mod[re]=1;
    e[Hashnum].st.len=st.len;
    for(int i=0;i<st.len;i++)
    e[Hashnum].st.va[i]=st.va[i];
    e[Hashnum].id=Hashnum;e[Hashnum].ne=p[re];
    p[re]=Hashnum++;
    return Hashnum-1;
}
int num[120];
void add(Node st,LL va,int id)
{
    int re=st.len;
    for(int i=0;i<st.len;i++)
    {
        re*=12;
        re+=st.va[i];
        re%=P;
    }
    int tt=find(st,re);
    if(tt+1>num[id])
    {
        ST[id][tt].len=st.len;
        for(int i=0;i<st.len;i++)
        ST[id][tt].va[i]=st.va[i];
        num[id]=tt+1;
    }
    dp[id][tt]+=va;
    dp[id][tt]%=PP;
}
int n,K,i,j,k,l,fl,te,po;
int main()
{
    while(~scanf("%d%d",&n,&K))
    {
        if(K==0){puts("0");continue;}
        num[0]=1;fl=0;num[1]=0;
        ST[0][0].len=1;
        ST[0][0].va[0]=1;
        memset(dp,0,sizeof(dp));dp[0][0]=1;
        for(i=2;i<=n;i++)
        {
            te=1-fl;
            for(j=0;j<num[te];j++)
            dp[te][j]=0;
            num[te]=0;
            Hashinit();
            for(j=0;j<num[fl];j++)
            {
                Node ts=ST[fl][j];
                for(k=0;k<=ts.len;k++)
                {
                    bool can=true;
                    if(k!=0&&ts.va[k-1]==0)can=false;
                    if(k!=ts.len&&ts.va[k]==0)can=false;
                    if(!can)continue;
                    Node tt;
                    for(l=0;l<k;l++)
                    {
                        if(ts.va[l]!=0)tt.va[l]=(ts.va[l]+1)%(K+1);
                        else tt.va[l]=0;
                    }
                    tt.va[k]=1;
                    for(l=ts.len;l>k;l--)
                    {
                        if(ts.va[l-1]!=0)tt.va[l]=(ts.va[l-1]+1)%(K+1);
                        else tt.va[l]=0;                        
                    }
                    tt.len=ts.len+1;po=1;
                    for(l=1;l<=ts.len;l++)
                    {
                        if(tt.va[l]==0&tt.va[po-1]==0)continue;
                        else tt.va[po++]=tt.va[l];
                    }
                    tt.len=po;
                    add(tt,dp[fl][j],te);
                }
            }
            fl=te;
        }
        LL ans=0;
        for(i=0;i<num[fl];i++)
        {
            ans+=dp[fl][i];
            ans%=PP;
        }
        cout<<ans<<endl;
    }
}
