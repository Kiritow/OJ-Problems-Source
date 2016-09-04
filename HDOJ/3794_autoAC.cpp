#include "iostream"
#include "stdio.h"
#include "math.h"
#include "vector"
#include "queue"
#include "memory.h"
#include "algorithm"
#include "string.h"
using namespace std;
#define N 1000005
__int64 a1[N];
__int64 a2[N];
int main()
{
    int n1,n2,i,j;
    while(scanf("%d",&n1)!=EOF&&n1>=0)
    {
        for(i=0;i<n1;i++)
            scanf("%I64d",&a1[i]);
        scanf("%d",&n2);
        for(i=0;i<n2;i++)
            scanf("%I64d",&a2[i]);
        sort(a1,a1+n1);
        sort(a2,a2+n2);
        i=0;
        __int64 sum=0;
        while(a1[i]<0&&a2[i]<0&&i<n1&&i<n2)
            sum+=a1[i]*a2[i++];
        i=n1-1,j=n2-1;
        while(a1[i]>0&&a2[j]>0&&i>=0&&j>=0)
            sum+=a1[i--]*a2[j--];
        printf("%I64d\n",sum);
    }
}
