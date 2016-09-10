#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 110;
int map[maxn][maxn];
int n, m;
int cal(int i, int j) {
    int ans = 1;
    if (map[i][j+1] == 0)
        ans <<= 1;
    if (map[i+1][j] == 0)
        ans <<= 1;
    if (map[i-1][j] == 0)
        ans <<= 1;
    if (map[i][j-1] == 0)
        ans <<= 1;
    return ans;
}
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        memset(map, -1, sizeof(map));
        int flag = 0;
        for (int i = 1; i <= m; i++) {
            map[1][i] = flag;
            flag = !flag;
        }
        for (int i = 2; i <= n; i++)
            for (int j = 1; j <= m; j++)
                map[i][j] = !map[i-1][j];
        int ans = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) 
                if (map[i][j])
                    ans += cal(i, j);    
        memset(map, -1, sizeof(map));
        flag = 1;
        for (int i = 1; i <= m; i++) {
                map[1][i] = flag;
                flag = !flag;
            }
        for (int i = 2; i <= n; i++)
            for (int j = 1; j <= m; j++)
                map[i][j] = !map[i-1][j];
        int tmp = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (map[i][j])
                    tmp += cal(i, j);
        printf("%d\n", max(ans, tmp));
    }
    return 0;
}
