#include<iostream>  
#include<map>  
#include<string.h>
using namespace std;  
#define N 35  
#define FF(i,n) for(int i=0;i<n;i++)  
int ans[N];  
int init[N][N];  
void matrixMul(int a[][N],int b[][N],int n,int mod){  
    int i,j,k;  
    int buf[N][N]={0};  
    FF(i,n)FF(k,n) if(a[i][k])FF(j,n)if(b[k][j])  
        buf[i][j]=(buf[i][j]+a[i][k]*b[k][j])%mod;  
    FF(i,n)FF(j,n) a[i][j]=buf[i][j];  
}  
void matrixMul(int a[],int b[][N],int n,int mod){  
    int i,j;  
    int buf[N]={0};  
    FF(i,n)FF(j,n)  
        buf[i]=(buf[i]+a[j]*b[i][j])%mod;  
    FF(i,n) a[i]=buf[i];  
}  
void matrixMul(int ans[],int init[][N],int n,int m,int mod){  
    for(;m;m>>=1){  
        if(m&1) matrixMul(ans,init,n,mod);  
        matrixMul(init,init,n,mod);  
    }  
}  
int main(void){  
    int t;  
    int i,j,k,n,mod;  
    int Map[N][N];  
    n=30;  
    mod=2008;  
    while(~scanf("%d",&t)){  
        int a,b;  
        int ind=0;  
        map<int,int> M;  
        memset(Map,0,sizeof(Map));  
        while(t--){ 
            scanf("%d%d",&a,&b);  
            if(M.find(a)==M.end())  
                M[a]=ind++;  
            if(M.find(b)==M.end())  
                M[b]=ind++;  
            Map[M[b]][M[a]]++;  
        }  
        scanf("%d",&t);  
        while(t--){  
            int v1,v2;  
            int t1,t2;  
            scanf("%d%d%d%d",&v1,&v2,&t1,&t2);  
            if(M.find(v1)==M.end()||M.find(v2)==M.end()||(t1==0&&t2==0)){  
                printf("0\n");  
                continue;  
            }  
            memset(ans,0,sizeof(ans));  
            ans[M[v1]]=1;  
            int ret;  
            if(t1==0)  
                ret=0;  
            else{  
                FF(j,M.size())FF(k,M.size()) init[j][k]=Map[j][k];  
                matrixMul(ans,init,M.size(),t1,mod);  
                ret=ans[M[v2]]%mod;  
            }  
            t1++;  
            for(;t1<=t2;t1++){  
                FF(i,M.size())FF(j,M.size()) init[i][j]=Map[i][j];                
                matrixMul(ans,init,M.size(),1,mod);               
                ret=(ret+ans[M[v2]])%mod;  
            }  
            printf("%d\n",ret);  
        }  
    }  
}
