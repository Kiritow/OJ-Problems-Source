#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const double pi = acos(-1.0);
const int maxn = 1 << 18;
const int mo=119;
struct Complex {
    double x, y;
    Complex (double real = 0, double imag = 0) : x(real), y(imag) {}
    double &real() {
        return x;
    }
    double &imag() {
        return y;
    }
    void print()
    {
        cout<<"real="<<x<<" imag=%.7lf\n"<<y<<endl;
    }
}Pa[50000],Pb[50000],Pc[50000];
int f[50000];
int n,a,b,p,q,N;
Complex operator+(const Complex &a, const Complex &b) {
    return Complex(a.x + b.x, a.y + b.y);
}
Complex operator-(const Complex &a, const Complex &b) {
    return Complex(a.x - b.x, a.y - b.y);
}
Complex operator*(const Complex &a, const Complex &b) {
    return Complex(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
}
inline void sincos(double theta,double &p0,double &p1)
{
    p0=sin(theta);
    p1=cos(theta);
}
void FFT(Complex P[], int n, int oper)
{
    for (int i = 1, j = 0; i < n - 1; i++) {
        for (int s = n; j ^= s >>= 1, ~j & s;);
        if (i < j) {
            swap(P[i], P[j]);
        }
    }
    Complex unit_p0;
    for (int d = 0; (1 << d) < n; d++) {
        int m = 1 << d, m2 = m * 2;
        double p0 = pi / m * oper;
        sincos(p0, unit_p0.y, unit_p0.x);
        for (int i = 0; i < n; i += m2) {
            Complex unit = 1;
            for (int j = 0; j < m; j++) {
                Complex &P1 = P[i + j + m], &P2 = P[i + j];
                Complex t = unit * P1;
                P1 = P2 - t;
                P2 = P2 + t;
                unit = unit * unit_p0;
            }
        }
    }
}
struct poly{
    int u[50000];
    poly() {
        memset(u,0,sizeof(u));
    }
    poly operator *(poly &B) {
        poly c;
        for (int i=0;i<q;i++) Pa[i]=Complex(u[i],0);
        for (int i=0;i<N-q;i++) Pa[i+q]=Complex(0,0); 
        for (int i=0;i<q;i++) Pb[i]=Complex(B.u[i],0);
        for (int i=0;i<N-q;i++) Pb[i+q]=Complex(0,0);
        FFT(Pa,N,1),FFT(Pb,N,1);
        for (int i=0;i<N;i++) Pc[i]=Pa[i]*Pb[i];
        FFT(Pc,N,-1);
        for (int i=0;i<N;i++) c.u[i]=((long long)(Pc[i].x/N+0.5))%mo;
        for (int i=N;i>=q;i--)
            if (c.u[i])
                (c.u[i-p]+=(c.u[i]*a)%mo)%=mo,
                (c.u[i-q]+=(c.u[i]*b)%mo)%=mo;
        return c;
    }
    void print()
    {
        for (int i=0;i<q;i++) cout<<u[i]<<' ';cout<<endl;
    }
};
int func(int x)
{
    if (x<=0) return 1;
    return f[x];
}
void fgm(int e,poly &sum,poly &b)
{
    sum.u[0]=1;
    b.u[1]=1;
    for (;e;e>>=1) {
        if (e&1) sum=sum*b;
        b=b*b;
    }
}
int main()
{
    for (;cin>>n>>a>>b>>p>>q;) {
        a%=mo,b%=mo;
        for (int i=1;i<=2*q;i++)
            f[i]=(a*func(i-p)+b*func(i-q))%mo;
        if (n<=2*q) {
            printf("%d\n",f[n]);            
            continue;
        }
        for (N=1;N<=q+q+1;N<<=1) ;        
        poly A,B;
        fgm(n-q,A,B);
        int ans=0;
        for (int i=q-1;i>=0;i--)
            ans=(ans+A.u[i]*f[i+q])%mo;
        printf("%d\n",ans);
    }
    return 0;
}
