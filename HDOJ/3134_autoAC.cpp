#include<iostream>
#include<algorithm>
#include<cmath>
#include<stdio.h>
using namespace std;
const double EPS = 1e-3;
const double PAI = 4 * atan(1.0);
const float FLOAT_MAX = 1.0e38, FLOAT_MIN = -1.0e38;
const double DOUBLE_MAX = 1.79e308, DOUBLE_MIN = -1.79e308;
const int N = 3005;
struct node{
    int x, y, z, id;
};
node a[N];
int f[N];
int n, l;
void add(int x, int y, int z, int id){
    a[l].x = x;
    a[l].y = y;
    a[l].z = z;
    a[l].id = id;
    l++;
}
void input(){
    int i, x, y, z;
    l = 0;
    add(-1,-1, -1, 0);
    for(i = 1; i <= n; i++){
        scanf("%d x %d x %d", &x, &y, &z);
        add(x,y,z,i);
        add(x,z,y,i);
        add(y,x,z,i);
        add(y,z,x,i);
        add(z,x,y,i);
        add(z,y,x,i);
    }
}
bool cmp(const node &a, const node &b){
    if(a.x != b.x)
        return a.x < b.x;
    if(a.y != b.y)
        return a.y < b.y;
    return a.z < b.z;
}
void solve()
{
    int i,j, res;
    sort(a, a+1, cmp);
    res = 0;
    f[0] = 0;
    for(i = 1; i < l; i++)
    {
        f[i] = 1;
        for(j = 1; j < i; j++)
            if(a[i].id != a[j].id && a[j].x < a[i].x && a[j].y < a[i].y && a[j].z < a[i].z)
                f[i] = max(f[i],f[j]+1);
        res = max(res, f[i]);
    }
    printf("%d\n", res);
}
int main()
{
    while(scanf("%d", &n) && n != -1){
        input();
        solve();
    }
    return 0;
}
