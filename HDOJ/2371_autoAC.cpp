#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#define INF 99999999
using namespace std;
const int MAX=80+10;
int array[MAX][MAX],sum[MAX][MAX];
char s[MAX];
int n,m,a;
void MatrixMult(int a[MAX][MAX],int b[MAX][MAX]){
    int c[MAX][MAX]={0};
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            for(int k=0;k<n;++k){
                c[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j)a[i][j]=c[i][j];
    }
}
void MatrixPow(int k){
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            sum[i][j]=(i == j);
        }
    }
    while(k){
        if(k&1)MatrixMult(sum,array);
        MatrixMult(array,array);
        k>>=1;
    }
}
int main(){
    while(cin>>n>>m,n+m){
        memset(array,0,sizeof array);
        for(int i=0;i<n;++i){
            cin>>a;
            array[a-1][i]=1;
        }
        getchar();
        gets(s);
        MatrixPow(m);
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(sum[i][j]){printf("%c",s[j]);break;}
            }
        }
        cout<<endl;
    }
    return 0;
}
