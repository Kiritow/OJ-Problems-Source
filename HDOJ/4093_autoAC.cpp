#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<cmath>
#include<ctime>
#include<iomanip>
using namespace std;
const double eps(1e-8);
typedef long long lint;
const long double PI = acos(-1.0);
struct Complex
{
    long double real, image;
    Complex(long double _real, long double _image)
    {
        real = _real;
        image = _image;
    }
    Complex(){}
};
Complex operator + (const Complex &c1, const Complex &c2)
{
    return Complex(c1.real + c2.real, c1.image + c2.image);
}
Complex operator - (const Complex &c1, const Complex &c2)
{
    return Complex(c1.real - c2.real, c1.image - c2.image);
}
Complex operator * (const Complex &c1, const Complex &c2)
{
    return Complex(c1.real*c2.real - c1.image*c2.image, c1.real*c2.image + c1.image*c2.real);
}
int rev(int id, int len)
{
    int ret = 0;
    for(int i = 0; (1 << i) < len; i++)
    {
        ret <<= 1;
        if(id & (1 << i)) ret |= 1;
    }
    return ret;
}
Complex A[1 << 16];
void FFT(Complex *a, int len, int DFT)
{
    for(int i = 0; i < len; i++) A[rev(i, len)] = a[i];
    for(int s = 1; (1 << s) <= len; s++)
    {
        int m = (1 << s);
        Complex wm = Complex(cos(DFT*2*PI/m), sin(DFT*2*PI/m));
        for(int k = 0; k < len; k += m)
        {
            Complex w = Complex(1, 0);
            for(int j = 0; j < (m >> 1); j++)
            {
                Complex t = w*A[k + j + (m >> 1)];
                Complex u = A[k + j];
                A[k + j] = u + t;
                A[k + j + (m >> 1)] = u - t;
                w = w*wm;
            }
        }
    }
    if(DFT == -1) for(int i = 0; i < len; i++) A[i].real /= len, A[i].image /= len;
    for(int i = 0; i < len; i++) a[i] = A[i];
}
int polynomialLength;
void multiply(Complex *p1, Complex *p2)
{
    for(int i = 0; i < polynomialLength; i++)
        p1[i] = p1[i]*p2[i];
    return;
}
void Copy(Complex *p1, Complex *p2)
{
    for(int i = 0; i < polynomialLength; i++)
        p1[i] = p2[i];
    return;
}
int a[13010];
int p, m;
Complex f[6][1 << 16];
Complex g[7][1 << 16];
const int par[6][10] = 
{
    {0},
    {1},
    {1, -1},
    {1, -3, 2},
    {1, -6, 3, 8, -6},
    {1, -10, 15, 20, -20, -30, 24}
};
void solve()
{
    int maxL = 0;
    for(int i = 1; i <= m; i++)
        maxL = max(maxL, a[i]);
    polynomialLength = 1;
    while(polynomialLength <= maxL*p) polynomialLength <<= 1;
    for(int i = 1; i <= p; i++)
    {
        for(int j = 0; j < polynomialLength; j++)
            f[i][j] = Complex(0, 0);
        for(int j = 1; j <= m; j++)
            f[i][i*a[j]].real += 1;
        FFT(f[i], polynomialLength, 1);
    }
    int inclusiveLength = -1;
    switch(p)
    {
        case 1: Copy(g[0], f[1]);
                inclusiveLength = 1;
                break;
        case 2: Copy(g[0], f[1]);
                multiply(g[0], f[1]);
                Copy(g[1], f[2]);
                inclusiveLength = 2;
                break;
        case 3: Copy(g[0], f[1]);
                multiply(g[0], f[1]); multiply(g[0], f[1]);
                Copy(g[1], f[2]);
                multiply(g[1], f[1]);
                Copy(g[2], f[3]);
                inclusiveLength = 3;
                break;
        case 4: Copy(g[0], f[1]);
                multiply(g[0], f[1]); multiply(g[0], f[1]); multiply(g[0], f[1]);
                Copy(g[1], f[2]);
                multiply(g[1], f[1]); multiply(g[1], f[1]);
                Copy(g[2], f[2]);
                multiply(g[2], f[2]);
                Copy(g[3], f[3]);
                multiply(g[3], f[1]);
                Copy(g[4], f[4]);
                inclusiveLength = 5;
                break;
        case 5: Copy(g[0], f[1]);
                multiply(g[0], f[1]); multiply(g[0], f[1]); multiply(g[0], f[1]); multiply(g[0], f[1]);
                Copy(g[1], f[2]);
                multiply(g[1], f[1]); multiply(g[1], f[1]); multiply(g[1], f[1]);
                Copy(g[2], f[2]);
                multiply(g[2], f[2]); multiply(g[2], f[1]);
                Copy(g[3], f[3]);
                multiply(g[3], f[1]); multiply(g[3], f[1]);
                Copy(g[4], f[3]);
                multiply(g[4], f[2]);
                Copy(g[5], f[4]);
                multiply(g[5], f[1]);
                Copy(g[6], f[5]);
                inclusiveLength = 7;
                break;
    }
    for(int i = 0; i < inclusiveLength; i++)
        FFT(g[i], polynomialLength, -1);
    for(int i = 0; i < polynomialLength; i++)
    {
        double res = 0;
        for(int j = 0; j < inclusiveLength; j++)
            res += g[j][i].real*par[p][j];
        for(int j = 1; j <= p; j++) res /= j;
        if(res > 0.5) printf("%d: %.0f\n", i, res);
    }
    return;
}
int main()
{
    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++)
    {
        scanf("%d %d", &m, &p);
        for(int i = 1; i <= m; i++)
            scanf("%d", &a[i]);
        printf("Case #%d:\n", cas);
        solve();
        putchar('\n');
    }
    return 0;
}
