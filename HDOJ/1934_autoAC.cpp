#include <iostream>
#include <algorithm>
#include <string.h>
#include <cmath>
#include <stdio.h>
#include <queue>
using namespace std;
char mm[10] = {"ACMIP"};
char a[10];
char b[10];
__int64 n;
int check(char c[])
{
    int len = strlen(c);
    bool isok2 = true;
    bool isok1 = true;
    for(int i=0;i<3;i++)
    {
        if(c[i] <'A' || c[i] >'Z')
        {
            isok1 = false;
            break;
        }
    }
    for(int i=3;i<7;i++)
    {
        if(c[i] <'0' || c[i] >'9')
        {
            isok1 = false;
            break;
        }
    }
    for(int i=0;i<5;i++)
    {
        if(c[i] <'B' || c[i] > 'Z' || c[i] == 'C' || c[i] == 'M' || c[i] == 'I' || c[i] == 'P')
        {
            isok2 = false;
            break;
        }
    }
    for(int i=5;i<7;i++)
    {
        if(c[i] <'0' || c[i] > '9')
        {
            isok2 = false;
            break;
        }
    }
    if(isok1) return 1;
    else if(isok2) return 2;
    return 0;
}
__int64 cal_old(char s[])
{
    __int64 sum = 0;
    for(int i=0;i<3;i++)
    {
        sum = sum * 26 + (s[i]-'A');
    }
    for(int i=3;i<7;i++)
    {
        sum = sum *10 + (s[i] -'0');
    }
    return sum;
}
char dir[27] = {"BDEFGHJKLNOQRSTUVWXYZ"};
int cal_new(char s[])
{
    __int64 sum = 0;
    for(int i=0;i<5;i++)
    {
        int res = -1;
        while(s[i] != dir[++res]);
        sum = sum *21 + res;
    }
    int tmp = 0;
    for(int i=5;i<7;i++)
    {
        tmp  = tmp* 10 + (s[i] - '0');
    }
    sum *= 100;
    sum += tmp;
    sum = sum + cal_old("ZZZ99999") + 1;
    return sum;
}
int main()
{
    while(~scanf("%s %s %d",a,b,&n))
    {
        getchar();
        if(a[0] == '*' && b[0] == '*' && n == 0) break;
        int res = check(a);
        int tmp = check(b);
        if(res == 0 || tmp == 0)
        {
            printf("N\n");
            continue;
        }
        __int64 sum_a = 0;
        __int64 sum_b = 0;
        if(res == 1) 
            sum_a = cal_old(a);
        else 
            sum_a = cal_new(a);
        if(tmp == 1)
            sum_b = cal_old(b);
        else 
            sum_b = cal_new(b);
        if(sum_b > sum_a && sum_a + n >= sum_b)
            printf("Y\n");
        else 
            printf("N\n");
    }
    return 0;
}
