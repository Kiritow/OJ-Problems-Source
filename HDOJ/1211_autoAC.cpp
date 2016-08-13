#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
    __int64 n;
__int64 power(int a,int d)
{
    int i;
    __int64 res=1;
    for(i=1;i<=d;i++)
        res=(res*a)%n;
    return res;
}
int main()
{
    int d,i,j,p,q,e,l,a;
    while(~scanf("%d%d%d%d",&p,&q,&e,&l))
    {    
        n=(p-1)*(q-1);
        for(i=1;;i++)
            if((i*e)%n==1)
            break;
        d=i;
        n=p*q;
        for(i=0;i<l;i++)
        {
            scanf("%d",&a);
            printf("%c",(power(a,d)));
        }
        putchar(10);
    }
}
