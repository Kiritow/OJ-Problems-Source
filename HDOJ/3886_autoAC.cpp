#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#define ll long long
#define M 100000000
using namespace std;
char str[101],a[101],b[101];
int len,bit[101],dp[101][101][10];
bool ok(int i,int u,int v)
{
    if(str[i]=='/') return u<v;
    if(str[i]=='-') return u==v;
    if(str[i]=='\\') return u>v;
}
int dfs(int pos,int j,int pre,bool h,bool f)
{
    if(pos==-1) return j==len;
    if(!f&&dp[pos][j][pre]!=-1) return dp[pos][j][pre];
    int ans=0;
    int e=f?bit[pos]:9;
    for(int i=0;i<=e;i++){
        if(h) ans+=dfs(pos-1,j,i,h&&i==0,f&&i==e);
        else if(j<len&&ok(j,pre,i)) ans+=dfs(pos-1,j+1,i,h,f&&i==e);
        else if(j>0&&ok(j-1,pre,i)) ans+=dfs(pos-1,j,i,h,f&&i==e);
        ans%=M;
    }
    if(!f) dp[pos][j][pre]=ans;
    return ans;
}
int solve(char an[],bool f)
{
    int m=0,i,j=0,le=strlen(an);
    while(an[j]=='0') j++;
    for(i=le-1;i>=j;i--) bit[m++]=an[i]-'0';
    if(f&&m>0){
        for(i=0;i<m;i++){
            if(bit[i]){
                bit[i]--;
                break;
            }
            else bit[i]=9;
        }
    }
    return dfs(m-1,0,0,1,1);
}
int main()
{
    int i,j,k,m,n;
    while(scanf("%s",str)!=EOF){
        len=strlen(str);
        scanf("%s%s",a,b);
        memset(dp,-1,sizeof(dp));
        printf("%08d\n",(solve(b,0)-solve(a,1)+M)%M);
    }
    return 0;
}
