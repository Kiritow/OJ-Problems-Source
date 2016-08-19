#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
#include <cmath>
#include <set>
#include <bitset>
#include <vector>
using namespace std;
const int BORDER = (1<<20)-1;
const int MAXSIZE = 37;
const int MAXN = 250100;
const int INF = 0x4ffffff;
#define CLR(x,y) memset(x,y,sizeof(x))
#define ADD(x) x=((x+1)&BORDER)
#define IN(x) scanf("%d",&x)
#define OUT(x) printf("%d\n",x)
#define MIN(m,v) (m)<(v)?(m):(v)
#define MAX(m,v) (m)>(v)?(m):(v)
#define ABS(x) (x>0?x:-x)
bitset<MAXSIZE> state[MAXSIZE];
int n,cur_n;
int init()
{
    int i,j;
    for(i = 0; i < MAXSIZE; ++i)
        state[i].reset();
    return 0;
}
bool dfs(const int& match,const int& cur,const int& sel,
        bitset<MAXSIZE> mask)
{
    if(mask.count() < match)
        return false;
    else if(sel == match)
        return true;
    else if(sel + 36 - cur < match)
        return false;
    return dfs(match,cur+1,sel,mask) || 
        dfs(match,cur+1,sel+1,mask&state[cur]);
}
int input()
{
    int i,a,b;
    IN(n);
    for(i = 0; i < n; ++i)
    {
        scanf("%d%d",&a,&b);
        state[a-1].set(b-1);
    }
    return 0;
}
int work()
{
    int i,j;
    bitset<MAXSIZE> mask;
    mask.set();
    for(cur_n = 2; cur_n*cur_n <= n&& dfs(cur_n,0,0,mask); ++cur_n)
        ;
    OUT(cur_n-1);
    return 0;
}
int main()
{
    int i,j,tt;
    IN(tt);
    while(tt--)
    {
        init();
        input();
        work();
    }
    return 0;
}
