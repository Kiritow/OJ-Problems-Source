#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
    int T;
    int a,b,c;
    int iCase=0;
    scanf("%d",&T);
    while(T--)
    {
        iCase++;
        scanf("%d%d%d",&a,&b,&c);
        int res;
        if((b+c)*2>=a) res=a/2+(b+c-a/2+a%2+1)/2;
        else res=(b+c)+(a-(b+c)*2+2)/3;
        printf("Case %d: %d\n",iCase,res);
    }
    return 0;
}
