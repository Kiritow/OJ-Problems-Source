#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stack>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
int a[5], pri, n;
__int64 f(int x,int i)
{
    int j;
    __int64 sum=0;
    for(j=0;j<i;j++){
        sum = (sum+a[j])*x;
    }
    return sum+a[j];
}
void solve()
{
    int i, j, k;
    int pri2 = pri*pri;
    for(i=0;i<pri;i++)
    {
        if( (f(i,n))%pri==0 ){
            for(j=i;j<pri2;j+=pri)
            {
                if( f(j,n)%pri2==0 ){
                    printf("%d\n",j);
                    return;
                }
            }
        }
    }
    printf("No solution!\n");
}
int main()
{
    int cse;
    cin>>cse;
    for(int t=1;t<=cse;t++)
    {
        scanf("%d",&n);
        for(int i=0;i<=n;i++) scanf("%d",&a[i]);
        scanf("%d",&pri);
        printf("Case #%d: ",t);
        solve();
    }
    return 0;
}
