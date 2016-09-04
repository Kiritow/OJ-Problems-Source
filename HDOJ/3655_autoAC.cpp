#include<cstdio>  
#include<cstring>  
#include<queue>  
#include<vector>  
#define N 3010  
#define M 200010  
#define inf 200000000  
typedef long long ll;  
using namespace std;  
int n,m;  
int head[N],cnt;  
int dp[4][N];  
bool vis[N];  
vector<int>vv;  
struct Edge{  
    int v,c,ne;  
}edge[M*2];  
void addedge(int u,int v,int w){  
    edge[cnt].v=v;  
    edge[cnt].c=w;  
    edge[cnt].ne=head[u];  
    head[u]=cnt++;  
    edge[cnt].v=u;  
    edge[cnt].c=w;  
    edge[cnt].ne=head[v];  
    head[v]=cnt++;  
}  
void init(){  
    memset(head,-1,sizeof(head));  
    cnt=0;  
}  
void SPFA(int u){  
    queue<int>q;  
    int i;  
    for(i=1;i<=n;i++){  
        dp[u][i]=inf;  
        vis[i]=0;  
    }  
    q.push(u);  
    dp[u][u]=0;  
    vis[u]=1;  
    while(!q.empty()){  
        int v=q.front();  
        q.pop();  
        for(int i=head[v];i!=-1;i=edge[i].ne){  
            int vv=edge[i].v;  
            if(dp[u][v]+edge[i].c<dp[u][vv]){  
                dp[u][vv]=dp[u][v]+edge[i].c;  
                if(!vis[vv]){  
                    vis[vv]=1;  
                    q.push(vv);  
                }  
            }  
        }  
        vis[v]=0;  
    }  
}  
int main(){  
    int i,j,u,v,w;  
    while(scanf("%d %d",&n,&m)==2){  
        init();  
        for(i=1;i<=m;i++){  
            scanf("%d %d %d",&u,&v,&w);  
            addedge(u,v,w);  
        }  
        for(i=1;i<=3;i++)  
            SPFA(i);  
        vv.clear();  
        for(i=1;i<=n;i++){  
            int flag=1;  
            for(j=head[i];j!=-1;j=edge[j].ne){  
                int num=0;  
                if(dp[1][edge[j].v]+edge[j].c==dp[1][i])num++;  
                if(dp[2][edge[j].v]+edge[j].c==dp[2][i])num++;  
                if(dp[3][edge[j].v]+edge[j].c==dp[3][i])num++;  
                if(num>1){  
                    flag=0;  
                    break;  
                }  
            }  
            if(flag && dp[1][i]!=inf && dp[2][i]!=inf && dp[3][i]!=inf)  
                vv.push_back(i);  
        }  
        int len=vv.size();  
        if(len){  
            printf("%d\n",len);  
            for(i=0;i<len;i++){  
                if(!i)  
                    printf("%d",vv[i]);  
                else  
                    printf(" %d",vv[i]);  
            }  
            printf("\n");  
        }  
        else  
            printf("impossible\n");  
    }  
    return 0;  
}
