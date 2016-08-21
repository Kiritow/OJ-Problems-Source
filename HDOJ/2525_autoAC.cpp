#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
int N, D, A, K, X;
long long P[105], W[105]; 
void init() {
    memset(P, 0, sizeof (P));
    memset(W, 0, sizeof (W));
    P[0] = N; 
}
void updateday() {
    for (int i = D; i >= 0; --i) {
        P[i+1] = P[i];
    }
    for (int i = K; i >= 0; --i) {
        W[i+1] = W[i];
    }
    P[0] = W[K];
}
void collect() { 
    W[0] = 0;
    for (int i = 1; i <= A; ++i) {
        W[0] += P[i];
    }
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        long long cnt = 0;
        scanf("%d %d %d %d %d", &N, &D, &A, &K, &X);
        init();
        for (int i = 1; i <= X; ++i) { 
            updateday();
            collect(); 
            for (int i = 1; i <= D; ++i) {
                cnt += P[i];
            }
        }
        printf("%I64d\n", cnt * 5);
    }
    return 0;    
}
