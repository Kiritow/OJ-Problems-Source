#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <numeric>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <list>
#include <set>
#include <map>
using namespace std;
#define pii pair<int,int>
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define PI acos(-1.0)
typedef __int64 LL;
typedef unsigned __int64 ULL;
const int N=100010;
const int INF=0x3f3f3f3f;
const int MOD=95041567,STA=8000010;
const LL LNF=1LL<<60;
const double EPS=1e-8;
const double OO=1e15;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};
const int day[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
inline int sign(double x){return (x>EPS)-(x<-EPS);}
template<class T> T gcd(T a,T b){return b?gcd(b,a%b):a;}
template<class T> T lcm(T a,T b){return a/gcd(a,b)*b;}
template<class T> inline T lcm(T a,T b,T d){return a/d*b;}
template<class T> inline T Min(T a,T b){return a<b?a:b;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}
template<class T> inline T Min(T a,T b,T c){return min(min(a, b),c);}
template<class T> inline T Max(T a,T b,T c){return max(max(a, b),c);}
template<class T> inline T Min(T a,T b,T c,T d){return min(min(a, b),min(c,d));}
template<class T> inline T Max(T a,T b,T c,T d){return max(max(a, b),max(c,d));}
LL low[N<<2][2],f[N];
int l[N],la[N],q[N][2],type[N],eng[N];
int T,n;
void update(int l,int r,int rt,int w,LL val,int flag)
{
    if(l==r){
        low[rt][flag]=val;
        return;
    }
    int mid=(l+r)>>1;
    if(w<=mid)update(lson,w,val,flag);
    else update(rson,w,val,flag);
    low[rt][flag]=Min(low[rt<<1][flag],low[rt<<1|1][flag]);
}
LL query(int l,int r,int rt,int L,int R,int flag)
{
    if(L<=l && r<=R){
        return low[rt][flag];
    }
    int mid=(l+r)>>1;
    LL ret=LNF;
    if(L<=mid)ret=Min(ret,query(lson,L,R,flag));
    if(R>mid)ret=Min(ret,query(rson,L,R,flag));
    return ret;
}
int binary(int l,int r,int tar)
{
    int mid;
    while(l<r){
        mid=(l+r)>>1;
        if(q[mid][0]<tar)l=mid+1;
        else r=mid;
    }
    return l;
}
int main()
{
    int i,j,t,L,R,top;
    LL lowf;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        mem(la,0);
        for(i=1;i<=n;i++){
            scanf("%d",&type[i]);
            l[i]=la[type[i]];
            la[type[i]]=i;
        }
        for(i=1;i<=n;i++){
            scanf("%d",&eng[i]);
        }
        mem(low,INF);mem(f,INF);f[0]=0;
        update(0,n+1,1,0,0,1);
        q[top=0][0]=0;q[top][1]=INF;
        for(i=1;i<=n;i++){
            while(q[top][1]<=eng[i]){
                update(0,n+1,1,q[top-1][0],LNF,0);
                top--;
            }
            q[++top][0]=i;q[top][1]=eng[i];
            t=q[top-1][0];
            lowf=query(0,n+1,1,t,i-1,1);
            update(0,n+1,1,t,lowf+eng[i],0);
            L=binary(0,top+1,l[i]);
            f[i]=query(0,n+1,1,q[L][0],i,0);
            if(l[i]<q[L][0]){
                lowf=query(0,n+1,1,l[i],q[L][0]-1,1);
                f[i]=Min(f[i],lowf+q[L][1]);
            }
            update(0,n+1,1,i,f[i],1);
        }
        printf("%I64d\n",f[n]);
    }
    return 0;
}
