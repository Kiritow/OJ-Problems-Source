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
const int MAX=4;
const int mod=20090524;
__int64 sum[MAX][MAX],array[MAX][MAX];
void MatrixMult(__int64 a[MAX][MAX],__int64 b[MAX][MAX]){
    __int64 c[MAX][MAX]={0};
    for(int i=0;i<MAX;++i){
        for(int j=0;j<MAX;++j){
            for(int k=0;k<MAX;++k){
                c[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
    for(int i=0;i<MAX;++i){
        for(int j=0;j<MAX;++j)a[i][j]=c[i][j]%mod;
    }
}
__int64 MatrixPow(int k){
    for(int i=0;i<MAX;++i){
        for(int j=0;j<MAX;++j)sum[i][j]=(i == j);
    }
    array[0][0]=array[0][1]=array[0][2]=1,array[0][3]=0;
    array[1][1]=array[1][2]=1,array[1][0]=array[1][3]=0;
    array[2][2]=array[2][3]=1,array[2][0]=array[2][1]=0;
    array[3][3]=1,array[3][0]=array[3][1]=array[3][0]=0;
    while(k){
        if(k&1)MatrixMult(sum,array);
        MatrixMult(array,array);
        k>>=1;
    }
    return (sum[0][2]+sum[0][3])%mod;
}
int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        printf("%I64d\n",MatrixPow(n));
    }
    return 0;
}
