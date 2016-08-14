#include<iostream>
using namespace std;
#define max_n 1010
struct point
{
    double x, y;
};
struct segment
{
    point s, e;
};
double dir(point a, point b, point c)
{
    return a.x*b.y + b.x*c.y + c.x*a.y - a.x*c.y - c.x*b.y - b.x*a.y;
}
bool connected(point a, point b, point c, point d)
{
    if (dir(a, b, c)*dir(a, b, d) <= 0 && dir(d, c, a)*dir(d, c, b) <= 0)return 1;
    return 0;
}
segment se[max_n];
int par[max_n], r[max_n];
int find(int x)
{
    if (x == par[x])return x;
    else return par[x] = find(par[x]);
}
void unite(int x, int y)
{
    int a = find(x), b = find(y);
    if (a != b)
    {
        if (r[a] < r[b])par[a] = b;
        else par[b] = a;
        if (r[a] == r[b])r[a]++;
    }
    return;
}
void inse(int n)
{
    bool ok = 1;
    for (int j = 1; j < n; j++)
    {
        if (connected(se[j].s, se[j].e, se[n].s, se[n].e))
        unite(n, j);
    }
    return;
}
int main()
{
    int tes, k, n, m; char c;
    cin >> tes;
    while (tes--)
    {
        cin >> n;
        k = 0;
        for (int i = 1; i <= n; i++)par[i] = i, r[i] = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> c;
            if (c == 'P')
            {
                k++;
                cin >> se[k].s.x >> se[k].s.y >> se[k].e.x >> se[k].e.y;
                inse(k);
            }
            else
            {
                cin >> m;
                int root = find(m), ans = 0;
                for (int i = 1; i <= k; i++)
                {
                    if (find(i) == root)ans++;
                }
                cout << ans << endl;
            }
        }
        if(tes)cout << endl;
    }
}
