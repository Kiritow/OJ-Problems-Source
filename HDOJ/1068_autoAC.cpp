#include <iostream>
using namespace std;
const int MAX = 500;
bool visited[MAX];
bool linked[MAX][MAX];
int arossPath[MAX];
int n;
bool search(int u) {
    for (int i = 0; i < n; i++) {
        if (!visited[i]&& linked[i][u]) {
            visited[i] = true;
            if (arossPath[i] == -1 || search(arossPath[i])) {
                arossPath[i] = u;
                return true;
            }
        }
    }
    return false;
}
int maxMatch() {
    int count = 0;
    memset(arossPath, -1, sizeof(arossPath));
    for (int i = 0; i < n; i++) {
        memset(visited, false, sizeof(visited));
        if (search(i))
            count++;
    }
    return count;
}
int main()
{
    int k, a, b;
    while (scanf("%d", &n) != EOF) {
        memset(linked, false, sizeof(linked));
        for (int i = 0; i < n; i++) {
            scanf("%d: (%d)", &a, &k);
            while (k--) {
                scanf("%d", &b);
                linked[a][b] = true;
            }
        }
        cout << (n - maxMatch()/2) << endl;
    }
    return 0;
}
