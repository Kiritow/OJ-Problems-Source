#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
using namespace std;
#define maxn 200007
#define ll long long
int lp[maxn],rp[maxn];
ll cosw[maxn];
ll dist[maxn];
set<int> haha;
struct Node{
    int id;
    ll cost;
};
bool operator < (Node a,Node b){
    if(a.cost == b.cost) return a.id < b.id;
    return a.cost < b.cost;
}
set<Node> mind;
int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i = 0;i < n; i++)
            scanf("%d",&lp[i]);
        for(int i = 0;i < n; i++)
            scanf("%d",&rp[i]);
        for(int i = 0;i < n; i++)
            scanf("%d",&cosw[i]);
        haha.clear();
        mind.clear();
        memset(dist,-1,sizeof(dist));
        dist[0] = 0;
        Node x,y;
        x.id = 0;
        x.cost = cosw[0];
        mind.insert(x);
        for(int i = 1;i < n; i++)
            haha.insert(i);
        set<int>::iterator it,it2;
        while(mind.size() > 0){
            x = *mind.begin();
            mind.erase(mind.begin());
            it = haha.lower_bound(x.id - rp[x.id]);
            while(it != haha.end()  && *it <= x.id - lp[x.id]){
                y.id = *it;
                y.cost = x.cost + cosw[y.id];
                dist[y.id] = x.cost;
                mind.insert(y);
                it2 = it++;
                haha.erase(it2);
            }
            it = haha.lower_bound(x.id + lp[x.id]);
            while(it != haha.end()  && *it <= x.id + rp[x.id]){
                y.id = *it;
                y.cost = x.cost + cosw[y.id];
                dist[y.id] = x.cost;
                mind.insert(y);
                it2 = it++;
                haha.erase(it2);
            }
        }
        for(int  i = 0;i < n; i++){
            if(i) printf(" ");
            printf("%I64d",dist[i]);
        }
        printf("\n");
    }
    return 0;
}
