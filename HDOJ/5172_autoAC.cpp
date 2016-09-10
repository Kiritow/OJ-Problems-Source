#include <iostream>
#include <string.h>
#include <math.h>
#include <queue>
#include <algorithm>
#include <stdlib.h>
#include <map>
#include <set>
#include <stdio.h>
using namespace std;
#define LL __int64
#define pi acos(-1.0)
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
const double eqs=1e-9;
#define root 1, n, 1
#define lson l, mid, rt<<1
#define rson mid+1, r, rt<<1|1
int a[1000002], pre[1000002], pos[1000002];
int Max[4000000];
LL sum[1000002];
void PushUp(int rt)
{
        Max[rt]=max(Max[rt<<1],Max[rt<<1|1]);
}
void build(int l, int r, int rt)
{
        if(l==r){
                Max[rt]=pre[l];
                return ;
        }
        int mid=l+r>>1;
        build(lson);
        build(rson);
        PushUp(rt);
}
int Query(int ll, int rr, int l, int r, int rt)
{
        if(ll<=l&&rr>=r){
                return Max[rt];
        }
        int mid=l+r>>1, ans=-1;
        if(ll<=mid) ans=max(ans,Query(ll,rr,lson));
        if(rr>mid) ans=max(ans,Query(ll,rr,rson));
        return ans;
}
int main()
{
        int n, m, i, j, x, l, r, ans;
        while(scanf("%d%d",&n,&m)!=EOF){
                memset(pos,-1,sizeof(pos));
                sum[0]=0;
                for(i=1;i<=n;i++){
                        scanf("%d",&x);
                        pre[i]=pos[x];
                        pos[x]=i;
                        sum[i]=sum[i-1]+x;
                }
                build(root);
                while(m--){
                        scanf("%d%d",&l,&r);
                        if(sum[r]-sum[l-1]!=(LL)(r-l+1)*(r-l+2)/2){
                                puts("NO");
                                continue ;
                        }
                        ans=Query(l,r,root);
                        if(ans<l) puts("YES");
                        else puts("NO");
                }
        }
        return 0;
}
