#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXN (100+10)
__int64 f[MAXN]={0,0,1};
__int64 h = 1000000007;
int main()
{
    int t;
    int n;
    for (int i=3;i<=100;i++)
    {
        f[i]=((i-1)*f[i-1]%h+f[i-2]*(i-1)%h)%h;
    }
    scanf(" %d",&t);
    while (t--)
    {
        scanf(" %d",&n);
        printf("%I64d\n",f[n]);
    }
}
