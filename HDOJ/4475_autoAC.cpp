#include<iostream>
#include<cstdio>
#include<math.h>
using namespace std;
const int con=1000003;
__int64 arr[con+1000];
int main()
{
    int T;
    __int64 n;
    arr[0]=0;
    arr[1]=2;
    for(int i=2;i<=con;i++)
    {
        arr[i]=(arr[i-1]*2*i)%con;
    }
    scanf("%d",&T);
    while(T--)
    {
        scanf("%I64d",&n);
         if(n<=con)
             printf("%I64d\n",arr[n%con]);
         else printf("0\n");
    }
    return 0;
}
