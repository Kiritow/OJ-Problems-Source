#include <cstdio>
#include <cstring>
#include <iostream> 
#include <algorithm>
#include <cmath>
#define INF 0x3fffffff
using namespace std;
struct node {
    int a, b;
}dian[105];
int main() {
    int n, m;
    while(scanf("%d %d", &n, &m) != EOF) {
        for(int i = 0; i < m; i++) {
            scanf("%d %d", &dian[i].a, &dian[i].b);
        }
        int ans = INF;
        for(int i = 0; i<m; i++) {
            int t = n / dian[i].a;
            if(n % dian[i].a) t++;
            if(t * dian[i].b < ans) ans = t * dian[i].b;
        }
        printf("%d\n", ans);
    }
    return 0;
}
