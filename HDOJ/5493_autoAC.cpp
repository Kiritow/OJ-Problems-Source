#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <bitset>
#include <vector>
#include <sstream>
#include <queue>
#include <typeinfo>
#include <fstream>
#include <map>
#include <stack>
typedef long long ll;
using namespace std;
#define sspeed ios_base::sync_with_stdio(0);cin.tie(0)
#define maxn 200006
#define mod 1000000007
#define eps 1e-9
#define e exp(1.0)
#define PI acos(-1)
#define lowbit(x) (x)&(-x)
const double EP  = 1E-10 ;
int Num;
const ll inf=999999999;
inline ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,val1[maxn],val2[maxn];
void add(int * vc,int u ,int v)
{
    while(u <= n )
    {
        vc[u] += v;
        u += lowbit(u);
    }
}
int query(int * vc,int u)
{
    int res=0;
    while(u)
    {
        res += vc[u];
        u -= lowbit(u);
    }
    return res;
}
int RankGet(int * vc,int k)
{
    int L = 1 , R = n;
    while(L < R)
    {
        int mid = L + ((R-L)>>1);
        int res = query(vc,mid);
        if(res == k) R = mid;
        else if(res < k) L = mid + 1;
        else R = mid - 1;
    }
    return L;
}
struct kkk
{
    int x,y;
};
bool cmp(kkk aa,kkk bb)
{
    return aa.x<bb.x;
}
kkk p[maxn];
int ans[maxn];
vector<int> v1,v2;
int main()
{
    int t=read();
    for(int cas=1;cas<=t;cas++)
    {
        n=read();
        for(int i=1;i<=n;i++)
        {
            p[i].x=read(),p[i].y=read();
            p[i].y++;
        }
        sort(p+1,p+n+1,cmp);
        int flag=1;
        memset(val1,0,4*(n+2));memset(val2,0,4*(n+2));
        for(int i = 1 ; i <= n ; ++ i)
        {
            add(val1,i,1);
            add(val2,i,1);
        }
        for(int i=1;i<=n;i++)
        {
            if(p[i].y>n-i+1)
            {
                flag=0;
                break;
            }
            int p1 = RankGet(val1,p[i].y);
            int p2 = n-RankGet(val2,p[i].y) + 1;
            if(p1<p2)
            {
                ans[p1]=p[i].x;
                add(val1,p1,-1);
                add(val2,n-p1+1,-1);
            }
            else
            {
                ans[p2]=p[i].x;
                add(val1,p2,-1);
                add(val2,n-p2+1,-1);
            }
        }
        printf("Case #%d:",cas);
        if(!flag)
        {
            printf(" impossible\n");
        }
        else
        {
            for(int i=1;i<=n;i++)
                printf(" %d",ans[i]);
            printf("\n");
        }
    }
}
