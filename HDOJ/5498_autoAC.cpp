#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<math.h>
using namespace std;
#define ll long long
#define maxn 101
int p;
struct Node{
    int mat[maxn][maxn];
    void init(){
        memset(mat,0,sizeof(mat));
    }
    void one(int n){
        init();
        for(int i = 0;i < n; i++)
            mat[i][i] = 1;
    }
    int Det(int n,  int mod1){ 
        int ans = 1;
        int *p1,*p2,mul;
        for(int i = 0;i < n; i++){
            for(int j = i+1;j < n; j++){
                while(mat[i][i] != 0 && mat[j][i] != 0){
                    if(abs(mat[i][i]) > abs(mat[j][i]))
                        p1=mat[i],p2=mat[j],mul=mat[i][i]/mat[j][i];
                    else
                        p1=mat[j],p2=mat[i],mul=mat[j][i]/mat[i][i];
                    for(int l = i;l < n; l++)
                        p1[l] = (p1[l]-(ll)p2[l]*mul)%mod1;
                }
                if(mat[i][i] == 0){
                    ans = -ans;
                    for(int l = i;l < n;l++)
                        swap(mat[i][l],mat[j][l]);
                }
            }
            ans = (ll)ans*mat[i][i] % mod1;
        }
        return (ans+mod1)%mod1;
    }
};
int matrix[maxn][maxn];
void multi(Node& a,Node& b,int n){ 
    for(int i = 0;i < n; i++)
        for(int j = 0;j < n; j++)
            matrix[i][j] = 0;
    for(int i = 0;i < n; i++){
        for(int j = 0;j < n; j++){
            if(a.mat[i][j] == 0) continue;
            for(int k = 0;k < n; k++){
                if(b.mat[j][k] == 0) continue;
                matrix[i][k] = (matrix[i][k]+(ll)a.mat[i][j]*b.mat[j][k])%p;
            }
        }
    }
    for(int i = 0;i < n; i++)
        for(int j = 0;j < n; j++)
            a.mat[i][j] = matrix[i][j];
}
int mp[maxn][maxn];
int main(){
    int t,n,m,q,u,v;
    Node a,b,c;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d",&n,&m,&p,&q);
        c.init();
        for(int i = 0;i < m; i++){
            scanf("%d%d",&u,&v);
            u--,v--;
            c.mat[u][u]++;
            c.mat[v][v]++;
            c.mat[u][v] = c.mat[v][u] = -1;
        }
        if(q < n-1){
            printf("0\n");
            continue;
        }
        int ans = c.Det(n-1,p);
        if(ans == 0){
            printf("0\n");
            continue;
        }
        a.init();
        b.one(n);
        for(int i = 1;i < n; i++)
            a.mat[i][i] = i,a.mat[i][i-1] = n-i;
        while(q){
            if(q&1) multi(b,a,n);
            multi(a,a,n);
            q/=2;
        }
        ans = (ll)ans*b.mat[n-1][0]%p;
        printf("%d\n",ans);
    }
    return 0;
}
