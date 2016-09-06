#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <map>
#include <stack>
#include <algorithm>
#define lson l, m , rt << 1
#define rson m + 1, r, rt << 1 | 1
#define maxn 50010
using namespace std;
struct people{
    int id,loty,abty;
    bool operator < (const people& cmp)const {
        return abty > cmp.abty;
    }
}emp[maxn];
int Max[maxn << 2],t,n,m,ans[maxn],L[maxn],R[maxn],head[maxn],tot,ed;
map <int, int> mp;
struct Edge{
    int v,next;
}edge[maxn];
void add(int u,int v){
    edge[ed].v = v;
    edge[ed].next = head[u];
    head[u] = ed ++;
}
void dfs(int root){
    bool vis[maxn];
    memset(vis,0,sizeof(vis));
    tot = 0;    stack <int> ss;
    while(!ss.empty()){ss.pop();}
    ss.push(root); vis[root] = true;    L[root] = tot ++;
    while(!ss.empty()){
        int now = ss.top();
        bool flag = false;
        for(int i = head[now]; i != - 1; i = edge[i].next){
            int x = edge[i].v;
            if(!vis[x]){
                flag = true;
                vis[x] = true;
                L[x] = tot ++;
                ss.push(x);
                head[now] = edge[i].next;
                break;
            }
        }
        if(flag)    continue;
        if(vis[now]){
            R[now] = tot;
            ss.pop();
        }
    }
}
int query(int L, int R, int l, int r, int rt){
    if(L > R) return -1;
    if(L <= l && r <= R){
        return Max[rt];
    }int m = (l + r) >> 1;
    int ll = -1, rr = -1;
    if(L <= m) ll = query(L,R,lson);
    if(R > m) rr = query(L,R,rson);
    return max(ll,rr);
}
void update(int &pos, int &val, int l, int r, int rt){
    if(l == r){
        Max[rt] = val;  return ;
    }int m = (l + r) >> 1;
    if(pos <= m) update(pos,val,lson);
    else update(pos,val,rson);
    Max[rt] = max(Max[rt << 1], Max[rt << 1 | 1]);
}
void pre(){
    mp.clear(); mp[-1] = -1;    tot = ed = 0;
    memset(L,0,sizeof(L));  memset(R,0,sizeof(R));  memset(ans,-1,sizeof(ans));
    memset(head,-1,sizeof(head));   memset(Max,-1,sizeof(Max));
    for(int i = 1,fa; i < n; i ++){
        scanf("%d%d%d",&fa,&emp[i].loty, &emp[i].abty);
        add(fa,i);
        mp[emp[i].loty] = i;
        emp[i].id = i;
    }
    dfs(0);
    sort(emp + 1,emp + n);
}
void showans(){
    int fired;
    while(m --){
        scanf("%d",&fired);
        printf("%d\n",ans[fired]);
    }
}
int main(){
    scanf("%d",&t);
    while(t --){
        scanf("%d%d",&n,&m);
        pre();
        for(int i = 1, j; i < n; i = j){
            j = i;
            while(j < n && emp[j].abty == emp[i].abty){
                int id = emp[j].id;
                int lo = query(L[id] + 1,R[id] - 1,0,tot - 1, 1);
                ans[id] = mp[lo];
                j ++;
            }
            j = i;
            while(j < n && emp[j].abty == emp[i].abty){
                int id = emp[j].id;
                update(L[id],emp[j].loty,0,tot - 1, 1);
                j ++;
            }
        }
        showans();
    }
    return 0;
}
