#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define LL long long
#define FOR(i,x,y)  for(int i = x;i < y;i ++)
#define IFOR(i,x,y) for(int i = x;i > y;i --)
#define N 2
int MOD;
LL p;
struct Matrix{
    LL mat[N][N];
    Matrix operator *(const Matrix& a) const{
        Matrix c;
        memset(c.mat,0,sizeof(c.mat));
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                for(int k=0;k<N;k++){
                    LL ssss = ((mat[i][k]*a.mat[k][j])%MOD+MOD)%MOD;
                    c.mat[i][j] = ((c.mat[i][j]+ssss)%MOD+MOD)%MOD;
                }
            }
        }
        return c;
    }
    Matrix operator ^(LL n) const{
        Matrix c;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                c.mat[i][j]=(i==j);
            }
        }
        Matrix a = *this;
        while(n)
        {
            if(n%2) c=c*a;
            a=a*a;
            n=n>>1;
        }
        return c;
    }
};
Matrix ss;
LL quickpow(LL a,LL n,int m){
    LL ret = 1;
    while(n){
        if(n&1) ret = (ret*a)%m;
        a = (a*a)%m;
        n >>= 1;
    }
    return ret;
}
int main(){
    int T,tCase = 0;
    scanf("%d",&T);
    ss.mat[0][0] = 10; ss.mat[0][1] = -1; ss.mat[1][0] = 1; ss.mat[1][1] = 0;
    while(T--){
        printf("Case #%d: ",++tCase);
        LL x;
        scanf("%I64d%d",&x,&MOD);
        p = (MOD-1)*(MOD+1);
        LL r = quickpow(2,x,p);
        Matrix st;
        st.mat[0][0] = 10; st.mat[0][1] = -1; st.mat[1][0] = 1; st.mat[1][1] = 0;
        st = st^r;
        LL aaaa = (((st.mat[0][0]*10)%MOD+MOD)%MOD + ((st.mat[0][1]*2)%MOD+MOD)%MOD)%MOD;
        if(!aaaa){
            printf("%d\n",MOD-1);
        }
        else
            printf("%I64d\n",aaaa-1);
    }
    return 0;
}
