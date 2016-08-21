#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
 int n;
 scanf("%d",&n);
 while(n--)
 {
 int a;
 scanf("%d",&a);
 int sum=0;
 for(int i=pow(2.0,a-1);i<pow(2.0,a);i++)
 sum+=__builtin_popcount(i);
 printf("%d\n",sum);
 }
 return 0;
}
