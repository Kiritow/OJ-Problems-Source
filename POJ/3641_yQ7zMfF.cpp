#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <cstdlib>
#include <queue>
#include <stack>
#include <vector>
#include <ctype.h>
#include <algorithm>
#include <string>
#include <set>
#define PI acos(-1.0)
#define maxn 10005
#define INF 0x7fffffff
#define eps 1e-8
typedef long long LL;
typedef unsigned long long ULL;
using namespace std;
LL pow_mod(LL aa,LL ii,LL nn)
{
  if(ii==0)
    return 1%nn;
  LL temp=pow_mod(aa,ii>>1,nn);
  temp=temp*temp%nn;
  if(ii&1)
    temp=temp*aa%nn;
  return temp;
}
bool test (LL n,LL a,LL d)
{
  if(n==2)
    return true;
  if(n==a)
    return true;
  if((n&1)==0)
    return false;
  while(!(d&1))
    d=d>>1;
  LL t=pow_mod(a,d,n);
  while((d!=n-1)&&(t!=1)&&(t!=n-1))
  {
    t=(LL)t*t%n;
    d=d<<1;
  }
  return (t==n-1||(d&1)==1);
}
bool isPrime(LL n)
{
  if(n<2)
    return false;
  LL a[]= {2,3,5,7,61};
  for(int i=0; i<=4; i++)
    if(!test(n,a[i],n-1))
      return false;
  return true;
}
int main()
{
  int T;
  LL p,a;
  while(scanf("%lld%lld",&p,&a))
  {
    if(!p&&!a)
      break;
    if(isPrime(p))
    printf("no\n");
    else if(pow_mod(a,p,p)==a)
      printf("yes\n");
    else printf("no\n");
  }
  return 0;
}
