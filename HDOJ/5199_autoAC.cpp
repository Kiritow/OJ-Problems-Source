#include<cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAXN 1000010
using namespace std;
struct node{
    int id;
    int h;
}q[MAXN];
int ans[MAXN];
priority_queue<int,vector<int>,greater<int> > pq;
bool cmp(node a,node b){
    if(a.h==b.h) return a.id<b.id;
    return a.h<b.h;
}
int n,m;
int main(){
    while(scanf("%d%d",&n,&m)==2){
        while(!pq.empty()) pq.pop();
        int tm;
        for(int i=0;i<n;++i)
        {
            scanf("%d",&tm);
            pq.push(tm);
        }
        for(int i=0;i<m;++i){
            scanf("%d",&q[i].h);
            q[i].id=i;
        }
        sort(q,q+m,cmp);
        memset(ans,0,sizeof(ans));
        for(int i=0;i<m;++i){
            int tans=0;
            while(!pq.empty()&&pq.top()<q[i].h) pq.pop();
            while(!pq.empty()&&i<m&&pq.top()==q[i].h){
                tans++;
                pq.pop();
            }
            ans[q[i].id]=tans;
            if(pq.empty())
                break;
        }
        for(int i=0;i<m;++i)
            printf("%d\n",ans[i]);
    }
    return 0;
}
