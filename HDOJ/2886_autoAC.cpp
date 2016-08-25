#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cmath>
#include <stack>
#include <map>
#pragma comment(linker, "/STACK:1024000000");
#define EPS (1e-8)
#define LL long long
#define ULL unsigned long long int
#define _LL __int64
#define _INF 0x3f3f3f3f
#define Mod 1000000007
#define LM(a,b) (((ULL)(a))<<(b))
#define RM(a,b) (((ULL)(a))>>(b))
using namespace std;
map<int,int> Max;
int Cal(int x,int n)
{
  if(n == 1)
    return x;
  if(n == 2)
    return x*x;
  if(Max.find(n) == Max.end())
  {
    if(n&1)
    {
      int t1 = Cal(x,n/2);
      int t2 = Cal(x,n/2 + 1);
      t1 = t1*t2;
      t1 %= 2009;
      Max.insert(pair<int,int>(n,t1));
      return t1;
    }
    else
    {
      int t1 = Cal(x,n/2);
      t1 = t1*t1;
      t1 %= 2009;
      Max.insert(pair<int,int>(n,t1));
      return t1;
    }
  }
  return Max[n];
}
int main()
{
  int n;
  while(scanf("%d",&n) != EOF)
  {
    if(n <= 4)
    {
      printf("%d\n",n);
    }
    else
    {
      if(n%3 == 0)
      {
        printf("%d\n",Cal(3,n/3)%2009);
      }
      else if(n%3 == 2)
      {
        printf("%d\n",(Cal(3,n/3)*2)%2009);
      }
      else
      {
        printf("%d\n",(Cal(3,n/3 - 1)*4)%2009);
      }
    }
  }
  return 0;
}
