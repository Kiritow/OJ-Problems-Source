#pragma comment(linker, "/STACK:65536000")
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <algorithm>
#define clr(a,b) memset(a,b,sizeof(a))
#define mpr(a,b) make_pair(a,b)
#define ll long long
#define eps 1e-6
using namespace std;
const int N=100005,M=300005;
int n,m,q,eid,id,now,top;
int head[N],ed[M],nxt[M];
int dfn[N],low[N],gid[N];
int sta[N],block[N];
vector<pair<int,int> >gra[N],qu[N];
int f[N],vis[N],come[N],out[N],fa[N];
int tlca[3*N],pt[3*N][2];
int aa[N],bb[N],cc[N];
int findfa(int s){return s==fa[s]?s:fa[s]=findfa(fa[s]);}
void addedge(int s,int e){
     ed[eid]=e;nxt[eid]=head[s];head[s]=eid++;
}
void tarjan(int s,int f,int b){
     dfn[s]=low[s]=++now;
     sta[top++]=s;block[s]=b;
     for(int i=head[s];~i;i=nxt[i]){
          int e=ed[i];
          if(i==f||i==(f^1))continue;
          if(!dfn[e]){
               tarjan(e,i,b);
               low[s]=min(low[s],low[e]);
          }else
               low[s]=min(low[s],dfn[e]);
     }
     if(low[s]==dfn[s]){
          id++;
          while(top){
               int k=sta[--top];
               gid[k]=id;
               if(k==s)return ;
          }
     }
}
void lca(int s,int f){
     fa[s]=s;
     for(int i=0;i<(int)gra[s].size();i++){
          int e=gra[s][i].first;
          if(e==f)continue;
          lca(e,s);
          fa[findfa(e)]=s;
     }
     vis[s]=1;
     for(int i=0;i<(int)qu[s].size();i++){
          int e=qu[s][i].first,d=qu[s][i].second;
          if(vis[e])tlca[d]=findfa(e);
     }
}
void dfs(int s,int f){
     for(int i=0;i<(int)qu[s].size();i++){
          int d=qu[s][i].second;
          int k=(tlca[d]==s)?-1:out[tlca[d]];
          if(~pt[d][0])pt[d][1]=k;
          else pt[d][0]=k;
     }
     for(int i=0;i<(int)gra[s].size();i++){
          int e=gra[s][i].first,g=gra[s][i].second;
          if(e==f){
               come[s]=g;continue;
          }
          out[s]=g;
          dfs(e,s);
     }
}
int main(){
     while(~scanf("%d%d",&n,&m)){
          eid=0;clr(head,-1);
          for(int i=0;i<m;i++){
               int a,b;scanf("%d%d",&a,&b);
               addedge(a,b);addedge(b,a);
          }
          id=now=top=0;
          for(int i=1;i<=n;i++)dfn[i]=0;
          int cnt=0;
          for(int i=1;i<=n;i++)
               if(!dfn[i])tarjan(i,-1,++cnt);
          for(int i=1;i<=id;i++){
               gra[i].clear();qu[i].clear();
          }
          for(int i=1;i<=n;i++)
               for(int j=head[i];~j;j=nxt[j]){
                    int s=gid[i],e=gid[ed[j]];
                    if(s!=e)gra[s].push_back(mpr(e,i));
               }
          clr(f,0);
          scanf("%d",&q);
          for(int i=0;i<q;i++){
               int a,b,c;scanf("%d%d%d",&a,&b,&c);
               if(block[a]!=block[b]){f[i]=1;continue;}
               if(block[b]!=block[c]){f[i]=1;continue;}
               if(block[a]!=block[c]){f[i]=1;continue;}
               if(a==b&&a!=c){f[i]=1;continue;}
               int s=gid[a],e=gid[b],k=gid[c];
               qu[s].push_back(mpr(e,i*3));
               qu[e].push_back(mpr(s,i*3));
               qu[s].push_back(mpr(k,i*3+1));
               qu[k].push_back(mpr(s,i*3+1));
               qu[e].push_back(mpr(k,i*3+2));
               qu[k].push_back(mpr(e,i*3+2));
               aa[i]=a;bb[i]=b;cc[i]=c;
          }
          for(int i=1;i<=id;i++)vis[i]=0;
          for(int i=0;i<q*3;i++)
               pt[i][0]=pt[i][1]=-1;
          for(int i=1;i<=id;i++)
               if(!vis[i]){
                    lca(i,-1);
                    dfs(i,-1);
               }
          for(int i=0;i<q;i++){
               if(f[i]){
                    puts("No");continue;
               }
               if(gid[aa[i]]==gid[bb[i]]){
                    if(gid[cc[i]]==gid[aa[i]])puts("Yes");
                    else puts("No");
               }
               else if(gid[cc[i]]==tlca[i*3]){
                    if(pt[i*3][1]==-1){
                         int k=(gid[aa[i]]==gid[cc[i]])?aa[i]:bb[i];
                         if(k==pt[i*3][0]&&cc[i]!=k) puts("No");
                         else puts("Yes");
                    }else{
                         if(pt[i*3][0]==pt[i*3][1]&&cc[i]!=pt[i*3][0]) puts("No");
                         else puts("Yes");
                    }
               }else if(tlca[i*3+1]==gid[cc[i]]&&tlca[i*3+2]==tlca[i*3]){
                    int k=(pt[i*3+1][0]==-1)?aa[i]:pt[i*3+1][0];
                    if(come[gid[cc[i]]]==k&&k!=cc[i])puts("No");
                    else puts("Yes");
               }else if(tlca[i*3+2]==gid[cc[i]]&&tlca[i*3+1]==tlca[i*3]){
                    int k=(pt[i*3+2][0]==-1)?bb[i]:pt[i*3+2][0];
                    if(come[gid[cc[i]]]==k&&k!=cc[i])puts("No");
                    else puts("Yes");
               }else puts("No");
          }
     }
}
