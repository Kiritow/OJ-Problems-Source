#include<iostream>
#include<math.h>
#include<stdio.h>
#include<ctype.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
#include<map>
#include<set>
using namespace std;
#define B(x) (1<<(x))
typedef long long ll;
void cmax(ll& a,ll b){ if(b>a)a=b; }
const int oo=0x3f3f3f3f;
const ll OO=1LL<<61;
const int MOD=2012;
const int maxt=3100000;
const int maxn=40;
map<int,ll>dp[2];
struct Node{
    int v,t,l;
}a[maxn];
bool cmp(Node x,Node y){
    return x.l-x.t<y.l-y.t;
}
int main(){
    int n,w,now,pre,ans;
    map<int,ll>::iterator it;
    ll sum;
    while(scanf("%d %d",&n,&w)!=EOF){
        memset(dp,0,sizeof dp);
        sum=0;
        for(int i=1;i<=n;i++){
            scanf("%d %d %d",&a[i].t,&a[i].v,&a[i].l);
            sum+=a[i].v;
        }
        if(sum<w){
            printf("zhx is naive!\n");
            continue;
        }
        sort(a+1,a+1+n,cmp);
        for(int i=0;i<2;i++)dp[i].clear();
        now=0;
        pre=1;
        dp[now][0]=0;
        for(int i=1;i<=n;i++){
            now^=1;
            pre^=1;
            dp[now].clear();
            for(it=dp[pre].begin();it!=dp[pre].end();++it){
                int u=it->first;
                ll dp_pre=it->second;
                cmax(dp[now][u],dp_pre);
                int uu=max(a[i].l,u+a[i].t);
                cmax(dp[now][uu],dp_pre+a[i].v);
            }
        }
        ans=-1;
        for(it=dp[now].begin();it!=dp[now].end();++it){
            if(it->second>=w){
                ans=it->first;
                break;
            }
        }
        if(ans!=-1)
            printf("%d\n",ans);
        else
            puts("zhx is naive!");
    }
    return 0;
}
