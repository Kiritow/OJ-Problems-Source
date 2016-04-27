#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

const int M = 100000;
const int N = 20000;

struct EDGE {
        int a;
        int b;
        int v;
} edge[M];

int f[N * 2];

bool Compare(const EDGE &a, const EDGE &b)
{
        return a.v < b.v;
}

int Find(int x)
{
        if (f[x] == x) {
                return f[x];
        } else {
                return f[x] = Find(f[x]);
        }
}

int main()
{
        int n, m;

        ios::sync_with_stdio(false);

        cin >> n;
        cin >> m;
        for (int i = 0; i < m; i++) {
                cin >> edge[i].a;
                cin >> edge[i].b;
                cin >> edge[i].v;
        }

        for (int i = 0; i < n * 2; i++) {
                f[i] = i;
        }

        sort(edge, edge + m, Compare);

        for (int i = m - 1; i >= 0; i--) {
                int x = Find(edge[i].a);
                int y = Find(edge[i].b);

                if (x == y) {
                        cout << edge[i].v << endl;

                        return 0;
                }

                int xx = Find(edge[i].a + n);
                int yy = Find(edge[i].b + n);

                f[x] = yy;
                f[y] = xx;
        }

        cout << "0" << endl;

        return 0;
}
