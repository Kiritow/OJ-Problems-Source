#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int s, t, m, tot = 0, ans = 0;
long long l;
int vis[11000] = {0};
int sto[110] = {0};
int f[11000] = {0};

int main ()
{
    //freopen ("in.txt", "r", stdin);
    cin >> l >> s >> t >> m;
    for (int i = 0; i < m; i++) cin >> sto[i];
    sort (sto, sto + m);
    if (s == t) {
        for (int i = 0; i < m; i++) {
            if (!(sto[i]%s)) ans++;
        }
        cout << ans;
        return 0;
    }
    int e;
    if (sto[0] > 100) vis[tot = 100] = 1;
    else vis[tot = sto[0]] = 1; 
    for (int i = 1; i < m; i++) {
        if ((e = sto[i] - sto[i-1]) > 100) { vis[tot += 100] = 1;}
        else { vis[tot += e] = 1;}
    }

    for (int i = tot; i >= 0; i--) {
        f[i] = 200;
        for (int j = s; j <= t; j++) {
            f[i] = min (f[i], f[i+j] + vis[i]);
        }
    }
    cout << f[0];
    return 0;
 }
