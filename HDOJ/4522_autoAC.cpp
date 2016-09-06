#include<iostream>
#include<cstring>
#include<algorithm>
const int N=207;
const int inf=1e7;
using namespace std;
int dist1[N];
int dist0[N];
int visited[N];
int edge1[N][N];
int edge0[N][N];
int n,m,k;
void Dijkstra1(int u){
    memset(visited,0,sizeof(visited));
    for(int i=1;i<=n;i++){
        dist1[i]=edge1[u][i];
    }
    visited[u]=1;
    for(int i=1;i<n;i++){
        int min=inf,v=u;
        for(int j=1;j<=n;j++){
            if(dist1[j]<min&&!visited[j]){
                min=dist1[j];
                v=j;
            }
        }
        if(min==inf)return ;
        visited[v]=1;
        for(int k=1;k<=n;k++){
            if(!visited[k]&&edge1[v][k]<inf&&dist1[v]+edge1[v][k]<dist1[k]){
                dist1[k]=dist1[v]+edge1[v][k];
            }
        }
    }
}
void Dijkstra0(int u){
    memset(visited,0,sizeof(visited));
    for(int i=1;i<=n;i++){
        dist0[i]=edge0[u][i];
    }
    visited[u]=1;
    for(int i=1;i<n;i++){
        int min=inf,v=u;
        for(int j=1;j<=n;j++){
            if(dist0[j]<min&&!visited[j]){
                min=dist0[j];
                v=j;
            }
        }
        if(min==inf)return ;
        visited[v]=1;
        for(int k=1;k<=n;k++){
            if(!visited[k]&&edge0[v][k]<inf&&dist0[v]+edge0[v][k]<dist0[k]){
                dist0[k]=dist0[v]+edge0[v][k];
            }
        }
    }
}
int main(){
    int _case;
    scanf("%d",&_case);
    while(_case--){
        scanf("%d%d",&n,&m);
        char str[10100];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                edge1[i][j]=edge1[j][i]=inf;
                edge0[i][j]=edge0[j][i]=inf;
            }
        }
        for(int i=1;i<=m;i++){
            scanf("%s%d",str,&k);
            int len=strlen(str);
            int s1=0,s2=0;
            if(k==1){
                for(int j=0;j<len;j++){
                    while(str[j]!='+'&&j<len){
                        s2=s2*10+str[j]-'0';
                        j++;
                    }
                    edge1[s1][s2]=1;
                    edge0[s1][s2]=1;
                    s1=s2;
                    s2=0;
                }
            }else if(k==0){
                for(int j=0;j<len;j++){
                    while(str[j]!='+'&&j<len){
                        s2=s2*10+str[j]-'0';
                        j++;
                    }
                    edge0[s1][s2]=1;
                    s1=s2;
                    s2=0;
                }
            }
        }
        int d1,d2,u,v;
        scanf("%d%d%d%d",&d1,&d2,&u,&v);
        Dijkstra1(u);
        Dijkstra0(u);
        if(dist1[v]==inf&&dist0[v]==inf){
            printf("-1\n");
        }else if(dist1[v]==inf&&dist0[v]<inf){
            printf("%d\n",dist0[v]*d1);
        }else if(dist1[v]<inf&&dist0[v]==inf){
            printf("%d\n",dist1[v]*d2);
        }else {
            printf("%d\n",min(dist1[v]*d2,dist0[v]*d1));
        }
    }
    return 0;
}
