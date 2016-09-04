#include <iostream>
#include <string.h>
#include <algorithm>
#include <iomanip>
#include <math.h>
using namespace std;
struct dot{
    double x, y, r;
}all[1024];
int n, vis[1024], ok;
double in, out;
void DFS(int u)
{
    if(!ok) return;
    vis[u] = 1;
    if(all[u].y - all[u].r <= 0) {ok = 0; return;}
    for(int v = 0; v < n; ++v)
        if(!vis[v] && hypot(all[u].x - all[v].x, all[u].y - all[v].y) < all[u].r + all[v].r)
            DFS(v);
    if(all[u].x - all[u].r <= 0)
        in = min(in, all[u].y - sqrt(all[u].r * all[u].r - all[u].x * all[u].x));
    if(all[u].x + all[u].r >= 1000)
        out = min(out, all[u].y - sqrt(all[u].r * all[u].r - (1000-all[u].x) * (1000-all[u].x)));
}
int main()
{
    ios::sync_with_stdio(false);
    while(memset(vis, 0, sizeof(vis)), ok = 1, in = out = 1000, cin >> n){
        for(int i = 0; i < n; ++i)
            cin >> all[i].x >> all[i].y >> all[i].r;
        for(int i = 0; i < n; ++i)
            if(!vis[i] && all[i].y + all[i].r >= 1000)
                DFS(i);
        if(!ok) puts("IMPOSSIBLE");
        else printf("%.2f %.2f %.2f %.2f\n", 0.0, in, 1000.0, out);
    }
    return 0;
}
