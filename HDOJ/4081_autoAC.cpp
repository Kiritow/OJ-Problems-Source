#include<iostream>
#include<cstring>
#include<cmath>
const int N=1010;
const double inf=1e14;
using namespace std;
struct Point{
    int x,y,z;
}point[N];
int n;
double edge[N][N];
int nearvex[N];
double  lowcost[N]; 
double sum;
int used[N][N];
int visited[N];
double  Max[N][N];
void prim(int v0){
    sum=0;
    memset(used,0,sizeof(used));
    memset(visited,0,sizeof(visited));
    memset(Max,0,sizeof(Max));
    for(int i=1;i<=n;i++){
        lowcost[i]=edge[v0][i];
        nearvex[i]=v0;
    }
    visited[v0]=1;
    for(int i=1;i<n;i++){
        double min=inf;
        int v=-1;
        for(int j=1;j<=n;j++){
            if(!visited[j]&&lowcost[j]<min){
                v=j,min=lowcost[j];
            }
        }
        if(v!=-1){
            sum+=lowcost[v];
            used[v][nearvex[v]]=used[nearvex[v]][v]=1;
            visited[v]=1;
            for(int k=1;k<=n;k++){
                if(visited[k]&&k!=v){
                          Max[v][k]=Max[k][v]=(Max[k][nearvex[v]]>lowcost[v]?Max[k][nearvex[v]]:lowcost[v]);
                }
                if(!visited[k]&&edge[v][k]<lowcost[k]){
                    lowcost[k]=edge[v][k];
                    nearvex[k]=v;
                }
            }
        }
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&point[i].x,&point[i].y,&point[i].z);
        }
        for(int i=1;i<=n;i++){
            edge[i][i]=0;
            for(int j=i+1;j<=n;j++){
                double dis=sqrt(pow((point[i].x-point[j].x)*1.0,2)+pow((point[i].y-point[j].y)*1.0,2));
                edge[i][j]=edge[j][i]=dis;
            }
        }
        prim(1);
        double r=-1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)if(i!=j){
                if(used[i][j]){
                    r=(r>(point[i].z+point[j].z)*1.0/(sum-edge[i][j])?r:(point[i].z+point[j].z)*1.0/(sum-edge[i][j]));
                }else if(!used[i][j]){
                    r=(r>(point[i].z+point[j].z)*1.0/(sum-Max[i][j])?r:(point[i].z+point[j].z)*1.0/(sum-Max[i][j]));
                }
            }
        }
        printf("%.2lf\n",r);
    }
    return 0;
}
