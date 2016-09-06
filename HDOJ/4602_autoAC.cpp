#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int mod=1000000007;
struct Matrix{
    long long arr[2][2];
};
Matrix init,unit;
int n,k;
long long num[2][2]={{4,-4},{1,0}};
void Init(){
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++){
            init.arr[i][j]=num[i][j];
            unit.arr[i][j]=(i==j)?1:0;
        }
}
Matrix Mul(Matrix a,Matrix b){
    Matrix c;
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++){
            c.arr[i][j]=0;
            for(int k=0;k<2;k++)
                c.arr[i][j]=(c.arr[i][j]%mod+a.arr[i][k]*b.arr[k][j]%mod+mod)%mod;
            c.arr[i][j]%=mod;
        }
    return c;
}
Matrix Pow(Matrix a,Matrix b,int k){
    while(k){
        if(k&1){
            b=Mul(a,b);
        }
        a=Mul(a,a);
        k>>=1;
    }
    return b;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        Init();
        if(k>n){
            printf("0\n");
            continue;
        }
        int tmp=n-k+1;
        if(tmp==1){
            printf("1\n");
            continue;
        }
        if(tmp==2){
            printf("2\n");
            continue;
        }
        if(tmp==3){
            printf("5\n");
            continue;
        }
        Matrix res=Pow(init,unit,tmp-3);
        long long ans=(res.arr[0][0]*5+res.arr[0][1]*2)%mod;
        cout<<ans<<endl;
    }
    return 0;
}
