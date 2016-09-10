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
int p[maxn],n,k;
char q[maxn] = {'p','q','r','u','v','w','x','y','z','\n'};
char ch[maxn];
void work()
{
    for(int i = 0;i < 10;++i){
        RD(p[i]);
    }
    int k = 0;
    while(k < 10 && p[k] == 0)k++;
    if(k == 10){
        puts("0");
        return ;
    }
    if(k == 9){
        printf("%d\n",p[9]);
        return;
    }
    if(p[k] == 1)
        printf("%c",q[k]);
    else if(p[k] == -1)
        printf("-%c",q[k]);
    else
        printf("%d%c",p[k],q[k]);
    for(int i = k+1;i < 9;++i){
        if(p[i] > 1)
            printf("+%d%c",p[i],q[i]);
        else if(p[i] < -1)
            printf("%d%c",p[i],q[i]);
        else if(p[i] == 1)
            printf("+%c",q[i]);
        else if(p[i] == -1)
            printf("-%c",q[i]);
    }
    if(p[9] == 0)
        puts("");
    else if(p[9] > 0)
        printf("+%d\n",p[9]);
    else
        printf("%d\n",p[9]);
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
