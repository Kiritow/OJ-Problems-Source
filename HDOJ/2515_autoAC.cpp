#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stack>
#include<queue>
#include<iostream>
#include<algorithm>
using namespace std;
#define M 2000000000
#define N 100005
int a[N],b[N];
int main()
{
    int n,i,j,g;
    while(~scanf("%d",&n))
    {
        for(i=1;i<=(n-1)*n/2;i++)
        {
            scanf("%d",&a[i]);
        }
        g=(a[1]+a[2]-a[n])/2;
        printf("%d\n",g);
        for(i=1;i<n;i++)
            printf("%d\n",a[i]-g);
    }
    return 0;
}
