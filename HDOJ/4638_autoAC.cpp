#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<set>
#include<map>
#include<vector>
#include<cstring>
#include<stack>
#include<cmath>
#include<queue>
using namespace std;
#define CL(x,v); memset(x,v,sizeof(x));
#define INF 0x3f3f3f3f
#define LL long long
#define REP(i,r,n) for(int i=r;i<=n;i++)
#define RREP(i,n,r) for(int i=n;i>=r;i--)
const int MAXN=1e5+100;
int tree[MAXN];
int n;
int lowbit(int x)
 {
     return x&(-x);
 }
 void add(int pos,int val)
 {
     while(pos <=n)
     {
         tree[pos] += val;
         pos += lowbit(pos);
     }
 }
 int read(int x)
 {
     int s=0;
     while(x>0)
     {
         s += tree[x];
         x -= lowbit(x);
     }
     return s;
 }
int A[MAXN],pos[MAXN];
struct node{
    int l,r,index;
    bool operator <(const node& rsh)const{
        if(r==rsh.r)
            return l<rsh.l;
        else return r<rsh.r;
    }
};
vector<node> Q;
int ans[MAXN];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int m;
        scanf("%d%d",&n,&m);
        REP(i,1,n){
            scanf("%d",&A[i]);
            pos[A[i]]=i;
        }
        Q.clear();
        node tmp;
        REP(i,1,m)
        {
            scanf("%d%d",&tmp.l,&tmp.r);
            tmp.index=i;
            Q.push_back(tmp);
        }
        sort(Q.begin(),Q.end());
        CL(tree,0);
        int j=0;
        for(int i=1;i<=n;i++)
        {
            add(i,1);
            if(A[i]+1<=n&&pos[A[i]+1]<i)
            {
                add(pos[A[i]+1],-1);
            }
            if(A[i]-1>=1&&pos[A[i]-1]<i)
            {
                add(pos[A[i]-1],-1);
            }
            while(Q[j].r==i)
            {
                ans[Q[j].index]=read(Q[j].r)-read(Q[j].l-1);
                j++;
            }
        }
        REP(i,1,m)
        {
            printf("%d\n",ans[i]);
        }
    }
    return 0;
}
