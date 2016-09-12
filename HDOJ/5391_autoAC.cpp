#include<iostream>
#include<cstring>
#include<cstdio>
#include<math.h>
#include<algorithm>
using namespace std;
bool isPrimeNum(int num)
{
     if (num <= 2)
     {
         return num == 2;
     }
     if (num % 2 == 0)
     {
         return false;
     }
     int iSqrt = sqrt(num);
     for (int i = 3; i <= iSqrt; i+=2)
     {
         if (num % i == 0)
         {
             return false;
         }
     }
     return true;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        if(n==4) printf("2\n");
        else if(isPrimeNum(n)) printf("%d\n",n-1);
        else printf("0\n");
    }
    return 0;
}
