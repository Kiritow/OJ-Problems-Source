#include <cstdio>
#include <cstring>
const int v = 200005;
int T, N, x;
__int64 a, b, c, A[v], B[v], C[v];
void f(int s, int t) {
    A[s] += a;
    B[s] += b;
    C[s] += c;
    A[t + 1] += -a;
    B[t + 1] += -b;
    C[t + 1] += -c;
}
void insert(__int64 x1, __int64 y1, __int64    x2, __int64 y2) {
    int m = x1 > y1 ? x1 : y1, t = x2 > y2 ? x2 : y2, t2 = x2 > y2 ? y2 : x2;
    a = b = c = 0;
    c = (x2 - x1) * (y2 - y1);
    f(t + 1, v - 5);
    a = 1;
    b = -(x1 + y1);
    c = x1 * y1;
    if(t2 >= m)
        f(m + 1, t2);
    else
        t2 = m;
    if(y2 > x2) {
        a -= 1;
        b +=  x2 + y1;
        c -=  x2 * y1;
    }
    else if(x2 > y2) {
        a -= 1;
        b +=  x1 + y2;
        c -=  x1 * y2;
    }
    f(t2 + 1, t);
}
int main() {
    scanf("%d", &T);
    while(T--) {
        memset(A, 0, sizeof(A));
        memset(B, 0, sizeof(B));
        memset(C, 0, sizeof(C));
        scanf("%d", &N);
        for(int i = 0; i < N; ++i) {
            __int64 x1, y1, x2, y2;
            scanf("%I64d%I64d%I64d%I64d", &x1, &y1, &x2, &y2);
            insert(x1, y1, x2, y2);
        }
        for(int i = 1; i < v; ++i) {
            A[i] += A[i-1];
            B[i] += B[i-1];
            C[i] += C[i-1];
        }
        scanf("%d", &x);
        while(x--) {
            __int64 t;
            scanf("%I64d", &t);
            printf("%I64d\n", t * t * A[t] + t * B[t] + C[t]);
        }
    }    
}
