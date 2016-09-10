#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
const int N = 1e5 + 5;
typedef long long ll;
map<int, int> vis;
int T, n, m, k;
struct Node {
    ll x;
    double v;
    int id;
}node[N];
int cmp (const Node &a, const Node &b) {
    return a.x < b.x;
}
double solve () {
    double ans = 0;
    vis.clear();
    sort (node, node + n, cmp);
    for (int i = 0; i < n; i++) 
        vis[node[i].id] = i;
    int pos, tmp;
    int num;
    for (int i = 0; i < m; i++) {
        scanf ("%d", &num);
        pos = vis[num - 1];
        int p1 = pos - 1;
        int p2 = pos + 1;
        double sum = 0;    
        tmp = 0;
        while (tmp < k) {
            if (p1 == -1)
                sum += node[p2++].v;    
            else if (p2 == n)
                sum += node[p1--].v;
            else {
                if (node[pos].x - node[p1].x < node[p2].x - node[pos].x)
                    sum += node[p1--].v;
                else if (node[pos].x - node[p1].x > node[p2].x - node[pos].x)
                    sum += node[p2++].v;
                else if (node[p1].id < node[p2].id)
                    sum += node[p1--].v;
                else
                    sum += node[p2++].v;
            }
            tmp++;
        }
        ans += sum / k;
        node[pos].v = sum / k;
    }
    return ans;
}
int main () {
    scanf ("%d", &T);
    while (T--) {
        scanf ("%d%d%d", &n, &m, &k);
        for (int i = 0; i < n; i++) {
            scanf ("%I64d%lf", &node[i].x, &node[i].v);    
            node[i].id = i;
        }
        printf ("%.6lf\n", solve());
    }
    return 0;
}
