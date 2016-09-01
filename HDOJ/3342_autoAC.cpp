#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
bool map[111][111];
vector<int>vet[111];
int from[111];
int n,m;
void floyd()
{
   for(int k=0;k<n;k++)
      for(int i=0;i<n;i++)
         for(int j=0;j<n;j++)
            map[i][j]=(map[i][j]||(map[i][k]&&map[k][j]));
}
bool Solve()
{
   queue<int>Q;
   int cnt=0;
   for(int i=0;i<n;i++){
      if(from[i]==0){ Q.push(i);cnt++; }
   }
   while(!Q.empty()){
      int u=Q.front();
      Q.pop();
      for(int i=0;i<vet[u].size();i++){
         int v=vet[u][i];
         if(from[v]>0){
            from[v]--;
            if(from[v]==0){ Q.push(v);cnt++; }
         }
      }
   }
   if(cnt==n)return true;
   return false;
}
int main(){
   int u,v;
   while(scanf("%d%d",&n,&m),n){
      memset(map,false,sizeof(map));
      memset(from,0,sizeof(from));
      for(int i=0;i<n;i++)vet[i].clear();
      while(m--){
         scanf("%d%d",&u,&v);
         map[u][v]=true;
      }
      for(int i=0;i<n;i++)
         for(int j=0;j<n;j++)if(i!=j){
            if(map[i][j]){ from[j]++;vet[i].push_back(j); }
         }
      bool flag=Solve();
      flag?puts("YES"):puts("NO");
   }
   return 0;
}
