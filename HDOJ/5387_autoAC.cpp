#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;
int gcd(int u,int v)
{
    if(u<v) swap(u,v);
    return v==0?u:gcd(v,u%v);
}
int abs(int x)
{
    if(x<0) return -x;
    else return x;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int hh,mm,ss;
        scanf("%d:%d:%d",&hh,&mm,&ss);
        int ts,tm,th;
        ts=6*ss;
        tm=60*mm+ss;
        th=3600*(hh%12)+60*mm+ss;
        int difms=abs(10*ts-tm);
        int difhm=abs(12*tm-th);
        int difhs=abs(120*ts-th);
        if(difms>10*180) difms=10*360-difms;
        if(difhm>120*180) difhm=120*360-difhm;
        if(difhs>120*180) difhs=120*360-difhs;
        if(difhm%120==0)
            printf("%d ",difhm/120);
        else
            printf("%d/%d ",difhm/gcd(difhm,120),120/gcd(difhm,120));
        if(difhs%120==0)
            printf("%d ",difhs/120);
        else
            printf("%d/%d ",difhs/gcd(difhs,120),120/gcd(difhs,120));
        if(difms%10==0)
            printf("%d \n",difms/10);
        else
            printf("%d/%d \n",difms/gcd(difms,10),10/gcd(difms,10));
    }
    return 0;
}
