#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
const int P = 1000003;
const int N1 = 262144;
const int N2 = N1+1;
const int P1 = 998244353;
const int P2 = 995622913;
const int E1 = 996173970;
const int E2 = 88560779;
const int F1 = 121392023;
const int F2 = 840835547;
const int I1 = 998240545;
const int I2 = 995619115;
const long long M1 = 397550359381069386LL;
const long long M2 = 596324591238590904LL;
const long long MM = 993874950619660289LL;
long long mul(long long x,long long y,long long z){
    return (x*y - (long long)(x/(long double)z*y+1e-3)*z+z)%z;
}
int trf(int x1,int x2){
    return (mul(M1,x1,MM)+mul(M2,x2,MM))%MM%P;
}
int A[N2],B[N2],C[N2];
int A1[N2],B1[N2],C1[N2];
void fft(int *A,int PM,int PW){
    for(int m = N1,h;h = m/2, m >= 2;PW = (long long)PW*PW%PM,m=h)
        for(int i = 0,w=1;i < h;i++, w = (long long)w*PW%PM)
            for(int j = i;j < N1;j += m){
                int k = j+h, x = (A[j]-A[k]+PM)%PM;
                (A[j]+=A[k])%=PM;
                A[k] = (long long)w*x%PM;
            }
    for(int i = 0,j = 1;j < N1-1;j++){
        for(int k = N1/2; k > (i^=k);k /= 2);
        if(j < i)swap(A[i],A[j]);
    }
}
void mul(){
    memset(C,0,sizeof(C));
    memcpy(A1,A,sizeof(A));
    memcpy(B1,B,sizeof(B));
    fft(A1,P1,E1); fft(B1,P1,E1);
    for(int i = 0;i < N1;i++)C1[i] = (long long)A1[i]*B1[i]%P1;
    fft(C1,P1,F1);
    for(int i = 0;i < N1;i++)C1[i] = (long long)C1[i]*I1%P1;
    fft(A,P2,E2); fft(B,P2,E2);
    for(int i = 0;i < N1;i++)C[i] = (long long)A[i]*B[i]%P2;
    fft(C,P2,F2);
    for(int i = 0;i < N1;i++)C[i] = (long long)C[i]*I2%P2;
    for(int i = 0;i < N1;i++)C[i] = trf(C1[i],C[i]);
}
int INV[P];
const int MAXN = 100010;
int F[MAXN];
int a[MAXN];
int pd[MAXN];
int pb[MAXN];
int pc2[MAXN];
int p[MAXN];
int main()
{
    INV[1] = 1;
    for(int i = 2;i < P;i++)
        INV[i] = (long long)P/i*(P-INV[P%i])%P;
    F[0] = 1;
    for(int i = 1;i < MAXN;i++)
        F[i] = (long long)F[i-1]*i%P;
    int n,b,c,d;
    while(scanf("%d%d%d%d",&n,&b,&c,&d) == 4){
        for(int i = 0;i < n;i++)scanf("%d",&a[i]);
        pd[0] = 1;
        for(int i = 1;i < n;i++)
            pd[i] = (long long)pd[i-1]*d%P;
        memset(A,0,sizeof(A));
        memset(B,0,sizeof(B));
        for(int i = 0;i < n;i++)
            A[i] = (long long)a[n-1-i]*F[n-1-i]%P;
        for(int i = 0;i < n;i++)
            B[i] = (long long)pd[i]*INV[F[i]]%P;
        mul();
        for(int i = 0;i < n;i++)p[i] = C[i];
        reverse(p,p+n);
        memset(A,0,sizeof(A));
        pb[0] = 1;
        for(int i = 1;i < n;i++)
            pb[i] = (long long)pb[i-1]*b%P;
        pc2[0] = 1;
        int c2 = (long long)c*c%P;
        for(int i = 1, s = c;i < n;i++){
            pc2[i] = (long long)pc2[i-1]*s%P;
            s = (long long)s*c2%P;
        }
        for(int i = 0;i < n;i++)
            A[i] = (long long)pb[i]*INV[F[i]]%P*p[i]%P*pc2[i]%P;
        memset(B,0,sizeof(B));
        B[0] = 1;
        for(int i = 1;i < n;i++)
            B[i] = B[N1-i] = INV[pc2[i]];
        mul();
        for(int i = 0;i < n;i++)C[i] = (long long)C[i]*pc2[i]%P;
        for(int i = 0;i < n;i++)
            printf("%d\n",C[i]);
    }
    return 0;
}
