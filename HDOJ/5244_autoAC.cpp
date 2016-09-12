#include <cstdio>
using namespace std;
const int MAXK = 20;
const int MAXN = (1 << MAXK);
typedef long long ll;
typedef unsigned long ul;
struct BI{
    ul d[4];
    BI(const ll& a = 0){
        d[0] = a & 0xffffffff;
        d[1] = a >> 32;
        d[2] = a >> 64;
        d[3] = d[2];
    }
    BI operator+(const BI& B)const{
        BI ret(*this);
        int flg = 0;
        ll tmp;
        for(int i = 0; i < 4; i ++){
            tmp = ll(ret.d[i]) + ll(B.d[i]) + ll(flg);
            ret.d[i] = tmp & 0xffffffff;
            flg = (tmp >> 32) & 1;
        }
        return ret;
    }
    BI operator-()const{
        BI ret(*this);
        int flg = 1;
        ll tmp;
        for(int i = 0; i < 4; i ++){
            tmp = ll(~ret.d[i]) + ll(flg);
            ret.d[i] = tmp & 0xffffffff;
            flg = (tmp >> 32) & 1;
        }
        return ret;
    }
    inline BI operator-(const BI& rhs)const{
        return (*this) + (- rhs);
    }
    void operator>>=(int k){
        int i;
        for(i = 0; i < 3; i ++)
            d[i] = (d[i] >> k) | (d[i+1] << (32 - k));
        d[3] = d[3] >> k;
    };
    ll val(){
        return (ll(d[1]) << 32) + ll(d[0]);
    }
};
ll B[MAXN];
BI A[MAXN];
int N, K;
void CalcA(){
    int i, j, b;
    for(j = 0; j < N; j ++)
        A[j] = B[j];
    for(i = 1; i <= K; i ++){
        for(b = 0; b < N; b += (1 << i)){
            int step = (1 << (i - 1));
            for(j = b; j < b + step; j ++){
                BI t1, t2;
                t1 = A[j + step] + A[j];
                t2 = A[j + step] - A[j];
                A[j] = t1;
                A[j + step] = t2;
            }
        }
    }
    if(K > 0){
        for(j = 0; j < N; j ++){
            A[j] >>= (K - 1);
        }
        A[0] = A[0] - B[N - 1];
    }
}
int main(){
    int i, j, T;
    scanf("%d", &T);
    for(i = 1; i <= T; i ++){
        scanf("%d", &K);
        N = 1 << K;
        for(j = 0; j < N; j ++){
            scanf("%I64d", &B[j]);
        }
        CalcA();
        printf("Case #%d:", i);
        for(j = 0; j < N; j ++)
            printf(" %I64d", A[j].val());
        printf("\n");
    }
    return 0;
}
