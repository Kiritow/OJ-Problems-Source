#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
#define RD(x) scanf("%d",&x)
#define RD2(x,y) scanf("%d%d",&x,&y)
#define RD3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define clr0(x) memset(x,0,sizeof(x))
#define clr1(x) memset(x,-1,sizeof(x))
#define eps 1e-9
const double pi = acos(-1.0);
typedef long long LL;
typedef unsigned long long ULL;
const int modo = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int inf = 0x3fffffff;
const LL _inf = 1e18;
const int maxn = 105,maxm = 10005;
int p[maxn],n,k,cas = 1;
char a[maxn],b[maxn];
void work()
{
    scanf("%s%s",a,b);
    int n = strlen(a),m = strlen(b);
    printf("Case %d: ",cas++);
    if(a[0] > b[0])
        printf("%c ",'>');
    else if(a[0] == b[0])
        printf("%c ",'=');
    else
        printf("%c ",'<');
    int _a = (a[3]-'0')*10 + a[4] - '0',_b = (b[3]-'0')*10 + b[4] - '0';
    char __a,__b;
    if(n == 5)
        __a = 'A';
    else
        __a = a[5];
    if(m == 5)
        __b = 'A';
    else
        __b = b[5];
    if(a[1] != b[1]){
        if(a[2] < b[2] || (a[2] == b[2] && _a < _b))
           printf("%c\n",'<');
        else if(a[2] > b[2] || (a[2] == b[2] && _a > _b))
           printf("%c\n",'>');
        else
           printf("%c\n",'=');
    }else if(a[1] == b[1]){
        if(a[2] < b[2] || (a[2] == b[2] && _a < _b) || (a[2] == b[2] && _a == _b && __a < __b))
           printf("%c\n",'<');
        else if(a[2] > b[2] || (a[2] == b[2] && _a > _b) || (a[2] == b[2] && _a == _b && __a > __b))
           printf("%c\n",'>');
        else
           printf("%c\n",'=');
    }
    return;
}
int main()
{
    int _;RD(_);
    while(_--){
        work();
    }
    return 0;
}
