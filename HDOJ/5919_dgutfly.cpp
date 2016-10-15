/* ***********************************************
┆  ┏┓　　　┏┓ ┆
┆┏┛┻━━━┛┻┓ ┆
┆┃　　　　　　　┃ ┆
┆┃　　　━　　　┃ ┆
┆┃　┳┛　┗┳　┃ ┆
┆┃　　　　　　　┃ ┆
┆┃　　　┻　　　┃ ┆
┆┗━┓　马　┏━┛ ┆
┆　　┃　勒　┃　　┆　　　　　　
┆　　┃　戈　┗━━━┓ ┆
┆　　┃　壁　　　　　┣┓┆
┆　　┃　的草泥马　　┏┛┆
┆　　┗┓┓┏━┳┓┏┛ ┆
┆　　　┃┫┫　┃┫┫ ┆
┆　　　┗┻┛　┗┻┛ ┆
************************************************ */
//#pragma comment(linker, "/STACK:102400000,102400000")
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <bitset>
using namespace std;

#define rep(i,a,b) for (int i=(a),_ed=(b);i<=_ed;i++)
#define per(i,a,b) for (int i=(b),_ed=(a);i>=_ed;i--)
#define pb push_back
#define mp make_pair
const int inf_int = 2e9;
const long long inf_ll = 2e18;
#define inf_add 0x3f3f3f3f
#define mod 1000000007
#define LL long long
#define ULL unsigned long long
#define MS0(X) memset((X), 0, sizeof((X)))
#define SelfType int
SelfType Gcd(SelfType p,SelfType q){return q==0?p:Gcd(q,p%q);}
SelfType Pow(SelfType p,SelfType q){SelfType ans=1;while(q){if(q&1)ans=ans*p;p=p*p;q>>=1;}return ans;}
#define Sd(X) int (X); scanf("%d", &X)
#define Sdd(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define Sddd(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define reunique(v) v.resize(std::unique(v.begin(), v.end()) - v.begin())
#define all(a) a.begin(), a.end()
#define   mem(x,v)      memset(x,v,sizeof(x))
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
inline int read(){int ra,fh;char rx;rx=getchar(),ra=0,fh=1;while((rx<'0'||rx>'9')&&rx!='-')rx=getchar();if(rx=='-')fh=-1,rx=getchar();while(rx>='0'&&rx<='9')ra*=10,ra+=rx-48,rx=getchar();return ra*fh;}

const int N = 2e5 + 5;

struct node
{
    int l,r,sum;
}tree[N*40];

int tot,cnt;

void update(int l,int r,int &x,int y,int k,int val)
{
    int tmp = x;
    x = ++tot;
    tree[x] = tmp ? tree[tmp] : tree[y];
    tree[x].sum += val;
    if(l==r) return;
    int mid = (l+r) >> 1;
    if(k<=mid) update(l,mid,tree[x].l,tree[y].l,k,val);
    else update(mid+1,r,tree[x].r,tree[y].r,k,val);
}

int query(int l,int r,int x,int k)
{
    if(l==r) return l;
    int mid = (l+r) >> 1;
    int sum = tree[tree[x].l].sum;
    if(k<=sum) return query(l,mid,tree[x].l,k);
    else return query(mid+1,r,tree[x].r,k-sum);
}

int getsum(int l,int r,int x,int L,int R)
{
    if(L<=l && r<=R) return tree[x].sum;
    int mid = (l+r) >> 1;
    int res = 0;
    if(L<=mid) res += getsum(l,mid,tree[x].l,L,R);
    if(R>mid) res += getsum(mid+1,r,tree[x].r,L,R);
    return res;
}

int a[N],pos[N],rt[N];
int ans[N];

void init()
{
    tot = 0;
    MS0(pos);
    MS0(rt);
}


int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    int cas = 1;
    int t = read();
    while(t--)
    {
        int n = read(), m = read();
        init();
        for(int i=1;i<=n;i++) a[i] = read();
        for(int i=n;i;i--)//倒着插入，以便从l开始计数
        {
            if(pos[a[i]])
            {
                update(1,n,rt[i],rt[i+1],pos[a[i]],-1);//去除重复的数
            }
            update(1,n,rt[i],rt[i+1],i,1);//前缀树继承上一次连接的
            pos[a[i]] = i;
        }
        for(int i=1;i<=m;i++)
        {
            int l = read(), r = read();
            l = (l + ans[i-1]) % n + 1;
            r = (r + ans[i-1]) % n + 1;
            if(l>r) swap(l,r);
            int sum = (getsum(1,n,rt[l],l,r) + 1) / 2;//向上取整，题目要求
            ans[i] = query(1,n,rt[l],sum);
        }
        printf("Case #%d:",cas++);
        for(int i=1;i<=m;i++) printf(" %d",ans[i]);
        printf("\n");
    }


    return 0;
}
