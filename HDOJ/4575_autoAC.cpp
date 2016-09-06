#include <iostream>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>
using namespace std;
#define inf 9e99
#define eps 1e-9
#define x first
#define y second
#define pb push_back
#define sz(a) int(a.size())
#define rep(i,a,b) for(int i=a;i<=b;i++)
template<class T> inline void gmin(T&a,T b) {if(a>b)a=b;}
template<class T> inline T sqr(T a) {return a*a;}
#define N 20020
vector<int> to[N],len[N];
int col[N],n;
double sum[N],L;
#define is_leaf(x) sz(to[x])==1 && sum[to[x][0]]<sum[x]
void pre_dfs(int x) {
    rep(i,0,sz(to[x])-1) {
        int y=to[x][i];
        if (sum[y]<0) {
            col[y]=x==1?y:col[x];
            sum[y]=sum[x]+len[x][i];
            pre_dfs(y);
        }
    }
}
vector<int> path,tmp[N];
double dp1[N],ans1[N];
double dp2[N],ans2[N];
double Y1(int j) {return dp1[j]+sqrt(dp1[j])+sqr(sum[j])+2.0*sum[j]*L;}
double Y2(int j) {return dp2[j]+sqrt(dp2[j])+sqr(sum[j])-2.0*sum[j]*L;}
double slope1(int j,int k) {return (Y1(j)-Y1(k))/(sum[j]-sum[k]);}
double slope2(int j,int k) {return (Y2(j)-Y2(k))/(sum[j]-sum[k]);}
double calc(double Ej,double sum) {return Ej+sqrt(Ej)+sum*sum;}
struct Queue {
    map<double,int> q;
    void clear() {q.clear();}
    int size() {return q.size();}
    int front() {return sz(q)?q.begin()->y:0;}
    int front2() {return sz(q)?(++q.begin())->y:0;}
    int back() {return sz(q)?q.rbegin()->y:0;}
    int back2() {return sz(q)?(++q.rbegin())->y:0;}
    void pop_front() {q.erase(q.begin());}
    void pop_back() {q.erase(--q.end());}
    void insert(int x,int y) {q[x]=y;}
    void merge(Queue *b) {
        while (b->size()) {
            int cur=b->front();
            b->pop_front();
            if (q.find(sum[cur])!=q.end()) {
                int j=cur,k=q[sum[cur]];
                if (Y2(j)>=Y2(k)) continue;
            }
            q[sum[cur]]=cur;
            if (sz(q)<=2) continue;
            map<double,int>::iterator i=q.find(sum[cur]),l1,l2,r1,r2;
            if (i!=q.begin() && i!=(--q.end())) {
                l1=i, l1--;
                r1=i, r1++;
                if (slope2(l1->y,i->y)>=slope2(i->y,r1->y)) {
                    q.erase(i);
                    continue;
                }
            }
            while (i!=q.begin() && i!=(++q.begin())) {
                l1=i, l1--;
                l2=l1, l2--;
                if (slope2(l2->y,l1->y)<=slope2(l1->y,i->y)) break;
                q.erase(l1);
            }
            while (i!=(--q.end()) && i!=(--(--q.end()))) {
                r1=i, r1++;
                r2=r1, r2++;
                if (slope2(i->y,r1->y)<=slope2(r1->y,r2->y)) break;
                q.erase(r1);
            }
        }
    }
} q1,*q2[N];
void first_run(int x) {
    rep(i,0,sz(to[x])-1) {
        int y=to[x][i];
        if (sum[y]<=sum[x]) continue;
        path.pb(y);
        tmp[x].clear();
        while (sz(q1)>=2 && slope1(q1.front(),q1.front2())<=2.0*sum[y] ) {
            tmp[x].pb(q1.front());
            q1.pop_front();
        }
        dp1[y]=calc(dp1[q1.front()],sum[y]-sum[q1.front()]-L);
        while (sz(q1)>=2 && slope1(q1.back2(),q1.back())>=slope1(q1.back(),y) ) {
            tmp[x].pb(q1.back());
            q1.pop_back();
        }
        q1.insert(sum[y],y);
        first_run(y);
        q1.pop_back();
        rep(i,0,sz(tmp[x])-1)
            q1.insert(sum[tmp[x][i]],tmp[x][i]);
        path.pop_back();
    }
    if (is_leaf(x)) {
        gmin(ans1[col[x]],dp1[x]);
    }
}
void merge(Queue *&a,Queue *&b) {
    if (b->size() < a->size()) {
        a->merge(b);
    } else {
        b->merge(a);
        a=b;
    }
}
double get_val(Queue *q,int x) {
    while (q->size()>=2 && slope2(q->back(),q->back2())>=2.0*sum[x]) q->pop_back();
    dp2[x]=calc(dp2[q->back()],sum[q->back()]-sum[x]-L);
    while (q->size()>=2 && slope2(q->front2(),q->front())<=slope2(q->front(),x) ) q->pop_front();
    return dp2[x];
}
void second_run(int x) {
    q2[x]=new Queue;
    rep(i,0,sz(to[x])-1){
        int y=to[x][i];
        if (sum[y]<=sum[x]) continue;
        second_run(y);
        if (x==1) {
            gmin(ans2[y],get_val(q2[y],x));
        } else {
            merge(q2[x],q2[y]);
        }
    }
    if (x!=1) {
        dp2[x]=is_leaf(x)?0:get_val(q2[x],x);
        q2[x]->insert(sum[x],x);
    }
}
double get_answer() {
    vector<int> part;
    rep(i,2,n) if (col[i]==i) part.pb(i);
    double min1=inf,min2=inf;
    int pos1;
    rep(i,0,sz(part)-1) {
        if (min1>ans2[part[i]]) {
            min2=min1;
            min1=ans2[part[i]];
            pos1=i;
        } else
        if (min2>ans2[part[i]]) {
            min2=ans2[part[i]];
        }
    }
    double res=inf;
    rep(i,0,sz(part)-1)
        gmin(res,ans1[part[i]]+(pos1==i?min2:min1));
    return res;
}
int main() {
    while (~scanf("%d%lf",&n,&L)) {
        rep(i,1,n) {
            to[i].clear();
            len[i].clear();
        }
        rep(i,1,n-1) {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            to[u].pb(v);
            to[v].pb(u);
            len[u].pb(w);
            len[v].pb(w);
        }
        if (sz(to[1])<2) {
            puts("-1");
            continue;
        }
        fill(sum+2,sum+n+1,-1);
        pre_dfs(1);
        fill(dp1+2,dp1+n+1,inf);
        fill(dp2+1,dp2+n+1,inf);
        fill(ans1,ans1+n+1,inf);
        fill(ans2,ans2+n+1,inf);
        path.clear();
        path.pb(1);
        q1.clear();
        q1.insert(0,1);
        first_run(1);
        second_run(1);
        printf("%.2lf\n",get_answer());
    }
    return 0;
}
