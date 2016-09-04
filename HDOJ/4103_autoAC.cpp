#include<stdio.h>
#include<iostream>
#include<string>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<queue>
using namespace std;
int a,b;
double c,d,t,pi;
bool flag;
int main()
{
    pi = 3.1416926536;
    while(scanf("%d%d%lf",&a,&b,&c)!=EOF && (a!=0 || b !=0 || fabs(c)>0.0000001))
    {
        printf("%d\n",a - 1);
    }
    return 0;
}
