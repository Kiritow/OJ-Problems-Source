#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <vector>  
using namespace std;  
const int N = 100005;  
int n, a[N], vis[N];  
int main() {  
    while (~scanf("%d", &n)) {  
        memset(vis, 0, sizeof(vis));  
        for (int i = 1; i <= n; i++)  
            scanf("%d", &a[i]);  
        for (int i = 1; i <= n; i++) {  
            if (vis[i]) continue;  
            int t = i;  
            printf("(%d", t);  
            vis[t] = 1;  
            t = a[t];  
            while (vis[t] == 0) {  
                vis[t] = 1;  
                printf(" %d", t);  
                t = a[t];  
            }  
            printf(")");  
        }  
        printf("\n");  
    }  
    return 0;  
}
