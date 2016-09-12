#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <ctime>
#include <cassert>
#include <complex>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define ACCU accumulate
#define TWO(x) (1<<(x))
#define TWOL(x) (1ll<<(x))
#define clr(a) memset(a,0,sizeof(a))
#define POSIN(x,y) (0<=(x)&&(x)<n&&0<=(y)&&(y)<m)
#define PRINTC(x) cout<<"Case #"<<++__<<": "<<x<<endl 
#define POP(x) (__builtin_popcount(x))
#define POPL(x) (__builtin_popcountll(x))
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long ll;
typedef long double LD;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<ll> VL;
typedef vector<PII> VPII;
typedef complex<double> CD;
const int inf=0x20202020;
const ll mod=1000000007;
const double eps=1e-9;
const double pi=3.1415926535897932384626;
const int DX[]={1,0,-1,0},DY[]={0,1,0,-1};
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll powmod(ll a,ll b,ll mod) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
const int N=101000;
struct node {
    node *s[2],*f;
    int val,d;
    bool rev;
    bool isr() { return !f||(f->s[0]!=this && f->s[1]!=this);}
    bool dir() { return f->s[1]==this;}
    void setc(node *c,int d) { s[d]=c;if (c) c->f=this;}
    void push() {
        if (rev) { swap(s[0],s[1]); rep(i,0,2) if (s[i]) s[i]->rev^=1;} rev=0;
    }
    void upd() {
        val=d;
        rep(i,0,2) if (s[i]&&s[i]->val<val) val=s[i]->val;
    }
}pool[N],*cur;
stack<node*> sta;
void rot(node *x) {
    node *p=x->f;bool d=x->dir();
    if (!p->isr()) p->f->setc(x,p->dir()); else x->f=p->f;
    p->setc(x->s[!d],d);x->setc(p,!d);
    p->upd();
}
void splay(node *x) {
    node *q=x;
    while (1) { sta.push(q);if (q->isr()) break; q=q->f; }
    while (!sta.empty()) sta.top()->push(),sta.pop();
    while (!x->isr()) {
        if (x->f->isr()) rot(x);
        else if (x->isr()==x->f->isr()) rot(x->f),rot(x);
        else rot(x),rot(x);
    }
    x->upd();
}
node *expose(node *x) {
    node *q=NULL;
    for (;x;x=x->f) splay(x),x->s[1]=q,(q=x)->upd();
    return q;
}
void evert(node *x) { expose(x); splay(x); x->rev^=1; x->push();}
void expose(node *x,node *y) { evert(x); expose(y); splay(x);}
void link(node *x,node *y) { evert(x); evert(y); x->setc(y,1);}
void cut(node *x,node *y) { expose(x,y); x->s[1]=y->f=NULL;}
const int R=100000;
int ans,ret[N],n;
VI d[N];
int main() {
    for (int i=2;i<=R;i++) for (int j=i+i;j<=R;j+=i) d[j].pb(i);
    for (int i=1;i<=R;i++) {
        pool[i].d=pool[i].val=i;
    }
    for (int i=2;i<=R;i++) {
        link(pool+i,pool+1); ans+=1;
        per(j,0,SZ(d[i])) {
            int v=d[i][j];
            expose(pool+i,pool+v);
            int u=pool[i].val;
            if (u>=v) continue;
            ans=ans-u+v;
            splay(pool+u);
            if (pool[u].s[0]) pool[u].s[0]->f=NULL,pool[u].s[0]=NULL;
            else if (pool[u].s[1]) pool[u].s[1]->f=NULL,pool[u].s[1]=NULL;
            else assert(0);
            link(pool+i,pool+v);
        }
        ret[i]=ans;
    }
    while (scanf("%d",&n)!=EOF) {
        printf("%d\n",ret[n]);
    }
}
