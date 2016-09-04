#include<stdio.h>
#include<math.h>
int N, P, Q;
double f[200005];
double logC(int n, int m) {
    return f[n]-f[m]-f[n-m];
}
int main() {
    int test = 0;
    for(int i=1; i<=200000; i++)
     f[i] = f[i-1] + log(0.0+i);
    while(scanf("%d%d%d", &N, &P, &Q) != EOF) {
        double a = 0, b = 0;
        for(int red=Q; red<=N-(P-Q); red++) {
            int blue = N - red;
            double p = exp(logC(red, Q) + logC(N-red, P - Q) - logC(N, P));
            double q = (red - Q + 0.0) / (N - P);
            a += p * q;
            b += p;
        }
        printf("Case %d: %.4lf\n", ++test, a/b);
    }
    return 0;
}
