#include<cstdio>  
#include<stdlib.h>  
#include<cstring>  
using namespace std;  
const int inf=99999999;  
struct{  
    int v, cap, cost, next, re;  
}edge[10005];  
int n,ans;  
int k,edgeHead[1050];  
int que[10050],pre[1050],dis[1050];  
bool vis[1050];  
int wei[1050];  
int min(int a,int b){  
    return a>b?b:a;  
}  
int max(int a,int b){  
    return a>b?a:b;  
}  
void addEdge(int u,int v,int ca,int co){  
    edge[k].v=v;  
    edge[k].cap=ca;  
    edge[k].cost=co;  
    edge[k].next=edgeHead[u];  
    edge[k].re=k + 1;          
    edgeHead[u]=k ++;  
    edge[k].v=u;  
    edge[k].cap=0;  
    edge[k].cost=-co;               
    edge[k].next=edgeHead[v];  
    edge[k].re=k - 1;  
    edgeHead[v]=k ++;  
}  
bool spfa(){                 
    int i, head = 0, tail = 1;    
    for(i = 0; i <= n; i ++){  
        dis[i] = inf;
        vis[i] = false;  
    }  
    dis[0] = 0;  
    que[0] = 0;  
    vis[0] = true;  
    while(head != tail){  
        int u = que[head];  
        for(i = edgeHead[u]; i != 0; i = edge[i].next){  
            int v = edge[i].v;  
            if(edge[i].cap && dis[v] >dis[u] + edge[i].cost){ 
                dis[v] = dis[u] + edge[i].cost;  
                pre[v] = i;                       
                if(!vis[v]){  
                    vis[v] = true;  
                    que[tail ++] = v;  
                    if(tail == 10000) tail = 0;             
                }  
            }  
        }  
        vis[u] = false;  
        head++;  
        if(head ==10000) head = 0;  
    }  
    if(dis[n] ==inf) return false;
    return true;  
}  
void end(){  
    int u, p;  
    for(u = n; u != 0; u = edge[edge[p].re].v){  
        p = pre[u];  
        edge[p].cap -= 1;  
        edge[edge[p].re].cap += 1;  
        ans += edge[p].cost;  
    }  
}  
int main(){  
    int i,j,v,lim,m,sum;  
    while(scanf("%d %d %d",&v,&m,&lim)!=EOF){  
        k=1;  
        sum=0;  
        memset(edgeHead,0,sizeof(edgeHead));  
        for(i=1;i<=v;i++){  
            scanf("%d",&wei[i]);  
            sum+=wei[i];  
        }  
        if(m<=lim){  
            printf("%d\n",sum);  
            continue;  
        }                            
        n=v-m+2;  
        for(i=0;i<=n;i++){  
            addEdge(i,i+1,lim,0);  
        }  
        for(i=1;i<=v;i++){  
            addEdge(max(1,i-m+1),min(n-1,i)+1,1,-wei[i]);  
        }  
        ans=0;  
        n++;  
        while(spfa())  
            end();  
        printf("%d\n",-ans);  
    }  
    return 0;  
}
