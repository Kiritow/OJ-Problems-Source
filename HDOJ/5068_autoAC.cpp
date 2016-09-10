#include<iostream>
#include<sstream>
#include<map>
#include<cmath>
#include<fstream>
#include<queue>
#include<vector>
#include<sstream>
#include<cstring>
#include<cstdio>
#include<stack>
#include<bitset>
#include<ctime>
#include<string>
#include<cctype>
#include<iomanip>
#include<algorithm>
using namespace std  ;
#define INT __int64
#define L(x)  (x * 2)
#define R(x)  (x * 2 + 1)
const int INF = 0x3f3f3f3f ;
const double esp = 0.0000000001 ;
const double PI = acos(-1.0) ;
const INT mod =  1000000007 ;
const int MY = 1400 + 5 ;
const int MX = 50000 + 5 ;
int n ,m ;
struct node
{
    int le ,rt ;
    INT p[2][2] ;
}T[MX*8] ;
node operator *(const node& a ,const node& b)
{
    node c ;
    memset(c.p ,0 ,sizeof(c.p)) ;
    for(int i = 0 ;i < 2 ; ++i)
      for(int k = 0 ;k < 2 ; ++k)
         if(a.p[i][k])
            for(int j = 0 ;j < 2 ; ++j)
               c.p[i][j] = (c.p[i][j] + a.p[i][k]*b.p[k][j])%mod ;
    return c ;
}
void build(int x ,int le ,int rt)
{
    T[x].le = le ; T[x].rt = rt ;
    if(le == rt)
    {
        for(int i = 0 ;i < 2 ; ++i)
          for(int j = 0 ;j < 2 ; ++j)
              T[x].p[i][j] = 1 ;
        return ;
    }
    int Mid = (le + rt)>>1 ;
    build(L(x) ,le ,Mid) ;
    build(R(x) ,Mid+1 ,rt) ;
    T[x] = T[L(x)] * T[R(x)] ;
    T[x].le = le ; T[x].rt = rt ;
}
void update(int x ,int pos ,int i ,int j)
{
    if(T[x].le == T[x].rt)
    {
        T[x].p[i][j] ^= 1 ;
        return ;
    }
    int Mid = (T[x].le + T[x].rt)>>1 ;
    if(pos <= Mid)   update(L(x) ,pos ,i ,j) ;
    else    update(R(x) ,pos ,i ,j) ;
    int le = T[x].le ,rt = T[x].rt ;
    T[x] = T[L(x)] * T[R(x)] ;
    T[x].le = le ; T[x].rt = rt ;
}
node section(int x ,int le ,int rt) 
{
    if(T[x].le == le && T[x].rt == rt)
        return T[x] ;
    int Mid = (T[x].le + T[x].rt)>>1 ;
    if(rt <= Mid)      return   section(L(x) ,le ,rt) ;
    else if(le > Mid)  return   section(R(x) ,le ,rt) ;
    else
          return  section(L(x) ,le ,Mid)*section(R(x) ,Mid+1 ,rt) ;
}
int main()
{
    //freopen("input.txt" ,"r" ,stdin) ;
    int p ,u ,v ,z ;
    while(~scanf("%d%d" ,&n ,&m))
    {
        build(1 ,1 ,n) ;
        for(int i = 0 ;i < m ; ++i)
        {
            scanf("%d" ,&p) ;
            if(p)
            {
                scanf("%d%d%d" ,&u ,&v ,&z) ;
                update(1 ,u ,v-1 ,z-1) ;
            }
            else
            {
               scanf("%d%d" ,&u ,&v) ;
               node ans = section(1 ,u ,v-1) ;
               printf("%I64d\n" ,(ans.p[0][0] + ans.p[0][1] + ans.p[1][0] + ans.p[1][1])%mod) ;
            }
        }
    }
    return 0 ;
}
