#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<set>
#include<cmath>
#include<vector>
#include<bitset>
#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define eps 1e-6
#define pi acos(-1.0)
using namespace std;
typedef long long ll;
const int maxn = 100000 + 10;
struct Node
{
    int pos,l,r,gval;
    Node(int pos = 0,int l = 0,int r = 0,int gval = 0):pos(pos),l(l),r(r),gval(gval){}
    bool operator < (const Node & a) const
    {
        if(gval != a.gval) return gval < a.gval;
        if(pos != a.pos) return pos < a.pos;
        return r < a.r;
    }
}node[maxn*20];
ll sum[maxn*20];
int cnt[maxn*20];
int a[maxn],pa[maxn],pre[maxn],val[maxn],n,tot;
int gcd(int a,int b) { return b == 0?a:gcd(b,a%b);}
vector<Node>vt[maxn];
void precal()
{
    for(int i = 0;i <= n;++i) vt[i].clear();
    vt[n].push_back(Node(n,n,n,a[n]));
    Node ntmp;
    int x;
    for(int i = n - 1;i >= 1;--i)
    {
        int size = vt[i + 1].size();
        int cnt = 1;
        vt[i].push_back(Node(i,i,i,a[i]));
        for(int j = 0;j < size;++j)
        {
            ntmp = vt[i+1][j];
            x = gcd(a[i],ntmp.gval);
            if(cnt && vt[i][cnt-1].gval == x)
                vt[i][cnt - 1].r = ntmp.r;
            else
                vt[i].push_back(Node(i,ntmp.l,ntmp.r,x)),cnt++;
        }
    }
    tot = 0;
    for(int i = 1;i <= n;++i)
        for(int j = 0;j < (int)vt[i].size();++j)
            node[++tot] = Node(vt[i][j]);
    sort(node + 1,node + tot + 1);
    sum[0] = 0;
    for(int i = 1;i <= tot;++i)
        sum[i] = sum[i-1] + node[i].r - node[i].l + 1;
    cnt[1] = 1;
    for(int i = 2;i <= tot;++i)
        cnt[i] = cnt[i-1] + (node[i].gval != node[i-1].gval);
}
int f(int l,int r)
{
    int L = 0,R = vt[l].size() - 1;
    while(L < R)
    {
        int m = (L + R)>>1;
//        cout<<vt[l][m].r<<endl;
        if(vt[l][m].r < r)
            L = m + 1;
        else
            R = m;
    }
    return vt[l][L].gval;
}
int main()
{
    char str[20];
    int t,tcase = 0,Q;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&Q);
        for(int i = 1;i <= n;++i)
            scanf("%d",&a[i]);
        precal();
        ll x,y,ans1,ans2;
        Node tmp;
        printf("Case #%d:\n",++tcase);
        while(Q--)
        {
            scanf("%s",str);
            scanf("%I64d%I64d",&x,&y);
            if(str[0] == 'S')
            {
                if(cnt[tot] < x)
                {
                    puts("-1");
                    continue;
                }
                int L = lower_bound(cnt + 1,cnt + tot + 1,x) - cnt;
                int R = upper_bound(cnt + 1,cnt + tot + 1,x) - cnt - 1;
                if(sum[R] - sum[L - 1] < y)
                {
                    puts("-1");
                    continue;
                }
                int pos = lower_bound(sum + L,sum + R + 1,y + sum[L-1]) - sum;
                ll tx = sum[pos] - sum[L - 1] - y;
                ans1 = node[pos].pos;
                ans2 = node[pos].r - tx;
                printf("%I64d %I64d\n",ans1,ans2);
            }
            else
            {
                int val = f(x,y),p1,p2;
                tmp = Node(-inf,0,0,val);
                p1 = lower_bound(node + 1,node + tot + 1,tmp) - (node );
                ans1 = cnt[p1];
                tmp = Node(x,x,y,val);
                p2 = lower_bound(node + p1,node + tot + 1,tmp) - node;
                ans2 = sum[p2 - 1] - sum[p1 - 1] + y - node[p2].l + 1;
                printf("%I64d %I64d\n",ans1,ans2);
            }
        }
    }
    return 0;
}
