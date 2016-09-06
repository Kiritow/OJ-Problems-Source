#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#define MAXN 2010
using namespace std;
int arr[MAXN];
char str[MAXN];
bool flag;
int idx[MAXN];
int cnt[MAXN];
int st[2][MAXN];
int belong[MAXN];
int n;
vector<int> pos[MAXN];
void dfs(int x, int p1, int p2) {
    if (x > n) {
        flag = true;
    }
    if (flag) {
        return;
    }
    if (p1 > 0 && p2 > 0
            && arr[st[0][min(p1, p2)]] != arr[st[1][min(p1, p2)]]) {
        return;
    }
    if (belong[x] == 0) {
        st[0][p1 + 1] = x;
        dfs(x + 1, p1 + 1, p2);
    } else if (belong[x] == 1) {
        st[1][p2 + 1] = x;
        dfs(x + 1, p1, p2 + 1);
    } else {
        st[0][p1 + 1] = x;
        belong[pos[arr[x]][2]] = 1;
        dfs(x + 1, p1 + 1, p2);
        if (!flag) {
            st[1][p2 + 1] = x;
            belong[pos[arr[x]][2]] = 0;
            dfs(x + 1, p1, p2 + 1);
            belong[pos[arr[x]][2]] = -1;
        }
    }
}
int main() {
    int T;
    int i;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        memset(idx, 0, sizeof(idx));
        memset(cnt, 0, sizeof(cnt));
        for (i = 1; i <= n; i++) {
            scanf("%d", &arr[i]);
            cnt[arr[i]]++;
            idx[i] = cnt[arr[i]];
            pos[arr[i]].clear();
        }
        memset(belong, -1, sizeof(belong));
        for (i = 1; i <= n; i++) {
            if (idx[i] == 1) {
                belong[i] = 0;
            } else if (idx[i] == 2 && cnt[arr[i]] == 2) {
                belong[i] = 1;
            } else if (idx[i] == 4) {
                belong[i] = 1;
            }
            pos[arr[i]].push_back(i);
        }
        flag = false;
        dfs(1, 0, 0);
        for (i = 1; i <= (n >> 1); i++) {
            str[st[0][i]] = '0';
            str[st[1][i]] = '1';
        }
        for (i = 1; i <= n; i++) {
            putchar(str[i]);
        }
        putchar('\n');
    }
    return 0;
}
