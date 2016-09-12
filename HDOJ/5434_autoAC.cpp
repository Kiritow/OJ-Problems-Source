#include<map>
#include<set>
#include<cmath>
#include<stack>
#include<queue>
#include<cstdio>
#include<cctype>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;
typedef long long LL;
const int matMX = 128 + 5;
const int INF = 0x3f3f3f3f;
const LL mod = 1e9 + 7;
struct Mat {
    int m, n;
    LL S[matMX][matMX];
    Mat(int a, int b) {
        m = a;
        n = b;
        memset(S, 0, sizeof(S));
    }
    Mat(int a, int b, LL w[][matMX]) {
        m = a;
        n = b;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                S[i][j] = w[i][j];
            }
        }
    }
};
Mat mat_mul(Mat A, Mat B) {
    Mat C(A.m, B.n);
    for(int i = 0; i < A.m; i++) {
        for(int j = 0; j < B.n; j++) {
            for(int k = 0; k < A.n; k++) {
                C.S[i][j] = (C.S[i][j] + A.S[i][k] * B.S[k][j]) % mod;
            }
        }
    }
    return C;
}
Mat Blank(int m, int n) {
    Mat ret(m, n);
    for(int i = 0; i < m; i++) {
        ret.S[i][i] = 1;
    }
    return ret;
}
Mat mat_pow(Mat A, LL b) {
    Mat ret = Blank(A.m, A.n);
    while(b) {
        if(b & 1) ret = mat_mul(ret, A);
        A = mat_mul(A, A);
        b >>= 1;
    }
    return ret;
}
LL S[matMX][matMX];
void DFS(int m, int cnt, int x, int y) {
    if(cnt == m) {
        S[x][y] = 1;
        return;
    }
    DFS(m, cnt + 1, x << 1, y << 1);
    DFS(m, cnt + 1, x << 1 | 1, y << 1 | 1);
    if(cnt) {
        if((x & 1) ^ (y & 1) == 0) {
            DFS(m, cnt + 1, x << 1, y << 1 | 1);
            DFS(m, cnt + 1, x << 1 | 1, y << 1);
        } else if((x & 1) && !(y & 1)) {
            DFS(m, cnt + 1, x << 1 | 1, y << 1);
        } else {
            DFS(m, cnt + 1, x << 1, y << 1 | 1);
        }
    } else {
        DFS(m, cnt + 1, x << 1 | 1, y << 1);
        DFS(m, cnt + 1, x << 1, y << 1 | 1);
    }
}
int main() {
    int m, n; 
    while(~scanf("%d%d", &n, &m)) {
        DFS(m, 0, 0, 0);
        Mat A(1 << m, 1 << m, S), B(1 << m, 1);
        memset(B.S, 0, sizeof(B.S));
        B.S[0][0] = 1;
        Mat ret = mat_mul(mat_pow(A, n), B);
        LL ans = 0;
        for(int i = 0; i < (1 << m); i++) {
            ans += ret.S[i][0];
            ans %= mod;
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
