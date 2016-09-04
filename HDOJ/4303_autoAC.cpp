#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
#define pb push_back
#define NN 301000
typedef pair<int,int> pii;
vector<pii> ed[NN];
long long ans;
int son[NN],fc[NN];
int val[NN];
void dfs2(int u,int fa,int ecol,int fcnt){
    ans+=((long long)son[u]-fc[u])*fcnt*val[u];
    int i,j,sz=ed[u].size(),v,tcol=-1,vv,tfcnt;
    int totc=0,tott=0;
    for(i=0,j=0;i<sz;++i){
        v=ed[u][i].second;
        if (v==fa) continue;
        if (tcol!=ed[u][i].first){
            tcol=ed[u][i].first;
            totc=0;
            if (j<sz&&ed[u][j].second==fa) ++j;
            for(;j<sz&&ed[u][j].first==tcol;++j){
                vv=ed[u][j].second;
                if (vv==fa) continue;
                totc=totc+son[vv]-fc[vv];
            }
            tott+=totc;
        }
        ans+=((long long)son[u]-tott)*(son[v]-fc[v])*val[u];
        if (ecol==ed[u][i].first) tfcnt=son[u]-totc;
        else tfcnt=son[u]-totc+fcnt;
        dfs2(v,u,ed[u][i].first,tfcnt);
    }
}
int dfs1(int u,int fa,int ecol){
    son[u]=1;
    fc[u]=0;
    int i,sz=ed[u].size(),v,tmp;
    sort(ed[u].begin(),ed[u].end());
    for(i=0;i<sz;++i){
        if (ed[u][i].second==fa) continue;
        v=ed[u][i].second;
        tmp=dfs1(v,u,ed[u][i].first);
        son[u]+=tmp;
        if (ecol==ed[u][i].first) fc[u]+=tmp;
    }
    return son[u]-fc[u];
}
int main(){
    int n,i,a,b,c;
    while(scanf("%d",&n)!=EOF){
        for(i=1;i<=n;++i){
            scanf("%d",&val[i]);
            ed[i].clear();
        }
        for(i=1;i<n;++i){
            scanf("%d%d%d",&a,&b,&c);
            ed[a].pb(make_pair(c,b));
            ed[b].pb(make_pair(c,a));
        }
        dfs1(1,-1,-1);
        ans=0;
        dfs2(1,-1,-1,0);
        printf("%I64d\n",ans);
    }
    return 0;
}
