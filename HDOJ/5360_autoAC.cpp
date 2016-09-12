#include<cstdio>
#include<cmath>
#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll maxn=100005;
int T,n,m,l[maxn],r[maxn],ans[maxn],tot,f[maxn];
struct lr
{
    int l,r,id;
    lr(int l,int r,int id):l(l),r(r),id(id){};
    bool operator <(const lr& a)const
    {
        if (r==a.r) return l>a.l;
        return r>a.r;
    }
};
vector<lr> p[maxn];
int main()
{
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);    tot=0;
        for (int i=1;i<=n;i++) scanf("%d",&l[i]);
        for (int i=1;i<=n;i++) scanf("%d",&r[i]);
        for (int i=0;i<=n;i++) p[i].clear();
        for (int i=1;i<=n;i++) p[l[i]].push_back(lr(l[i],r[i],i));
        priority_queue<lr> que;
        for (int i=0;i<=n;)
        {
            for (int j=0;j<p[i].size();j++) que.push(lr(p[i][j]));
            while (!que.empty()&&que.top().r<i) que.pop();
            if (!que.empty()) {ans[tot++]=que.top().id; que.pop(); i++;}
            else break;
        }
        printf("%d\n",tot);
        if (tot) 
        {
            memset(f,0,sizeof(f));
            printf("%d",ans[0]);
            for (int i=1;i<tot;i++) printf(" %d",ans[i]);
            for (int i=0;i<tot;i++) f[ans[i]]=1;
            for (int i=1;i<=n;i++) if (!f[i]) printf(" %d",i);
        }
        else for (int i=1;i<=n;i++) 
        {
            if (i>1) printf(" ");
            printf("%d",i);
        }
        printf("\n");
    }
    return 0;
}
