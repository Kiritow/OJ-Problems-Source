#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 30;
const int maxm = 900;
const int INF = 1000000;
vector<vector<pair<int,int> > > edge;
int dist[maxn+10];
bool inQue[maxn+10];
int n;
int num[maxn];
void spfa(int src){
    memset(dist,63,sizeof(dist));
    memset(inQue,0,sizeof(inQue));
    dist[src] = 0;
    queue<int> que;
    que.push(src);
    inQue[src] = 1;
    while(!que.empty())    {
        int u = que.front();
        que.pop();
        for(int i = 0; i < edge[u].size(); i++)
            if(dist[u]+edge[u][i].second<dist[edge[u][i].first]) {
                dist[edge[u][i].first] = dist[u]+edge[u][i].second;
                if(!inQue[edge[u][i].first]){
                    inQue[edge[u][i].first] = 1;
                    que.push(edge[u][i].first);
                }
            }
        inQue[u] = 0;
    } 
}
void init(){
    edge.clear();
    edge.resize(n+1);
}
int main(){
    int ncase;
    cin >> ncase;
    while(ncase--){
        scanf("%d",&n);
        init();
        for(int i = 1; i <= n; i++){
            int a,b;
            scanf("%d%d",&a,&b);
            num[a] = b;
            edge[0].push_back(make_pair(a,b-1));
        }
        for(int i = 1; i <= n; i++){
            for(int j = i+1; j <= n; j++){
                if(num[i]==num[j]){
                    edge[i].push_back(make_pair(j,0));
                    edge[j].push_back(make_pair(i,0));
                }
            }
        }
        int m;
        scanf("%d",&m);
        while(m--){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            edge[a].push_back(make_pair(b,c));
        }
        spfa(0);
        int cnt = 0;
        for(int i=1;i<=n;i++){
              bool flag=0;             
              for(int j=1;j<=n;j++){
                    if(i==j) continue;             
                  for(int k=1;k<=n;k++){            
                      if(k!=i&&k!=j&&dist[i]==dist[j]+dist[k]){
                          cnt++;
                        flag=1;
                        break;
                      }            
                  }
                  if(flag)  break;      
             }             
        }    
        for(int i = 1; i <= n; i++){
            cout<<i<<" "<<dist[i]<<endl;
        }
        cout<<cnt<<endl;
    }
}
