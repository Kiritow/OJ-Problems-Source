#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
int change(char s[])
{
    if(strcmp(s,"B]") == 0)return 0;
    if(strcmp(s,"KB]") == 0)return 1;
    if(strcmp(s,"MB]") == 0)return 2;
    if(strcmp(s,"GB]") == 0)return 3;
    if(strcmp(s,"TB]") == 0)return 4;
    if(strcmp(s,"PB]") == 0)return 5;
    if(strcmp(s,"EB]") == 0)return 6;
    if(strcmp(s,"ZB]") == 0)return 7;
    if(strcmp(s,"YB]") == 0)return 8;
}
char s[100];
int main()
{
    int T;
    int iCase = 0;
    double a;
    scanf("%d",&T);
    while(T--)
    {
        iCase++;
        scanf("%lf[%s",&a,s);
        int t = change(s);
        double ans = pow(1000.0,t)/pow(1024.0,t);
        ans = 1-ans;
        printf("Case #%d: %.2lf%%\n",iCase,ans*100);
    }
    return 0;
}
