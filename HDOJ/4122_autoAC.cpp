#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#define INF 99999999
using namespace std;
const int MAX=2500+10;
char mon[5];
int M[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
struct Node{
    int num,t;
}order[MAX],q[MAX*4];
int MON(char *m){
    if(strcmp(m,"Jan") == 0)return 1;
    if(strcmp(m,"Feb") == 0)return 2;
    if(strcmp(m,"Mar") == 0)return 3;
    if(strcmp(m,"Apr") == 0)return 4;
    if(strcmp(m,"May") == 0)return 5;
    if(strcmp(m,"Jun") == 0)return 6;
    if(strcmp(m,"Jul") == 0)return 7;
    if(strcmp(m,"Aug") == 0)return 8;
    if(strcmp(m,"Sep") == 0)return 9;
    if(strcmp(m,"Oct") == 0)return 10;
    if(strcmp(m,"Nov") == 0)return 11;
    return 12;
}
bool LeapYear(int &year){
    return year%4 == 0 && year%100 || year%400 == 0;
}
int Time(int &year,int Mon,int &d,int &h){
    int t=0;
    for(int i=2000;i<year;++i){
        if(LeapYear(i))t+=366;
        else t+=365;
    }
    bool flag=LeapYear(year);
    for(int i=1;i<Mon;++i){
        if(flag && i == 2)t+=29;
        else t+=M[i];
    }
    t+=d-1;
    return t*24+h;
}
int main(){
    int n,m,t,s,r,h,d,year,a;
    while(~scanf("%d%d",&n,&m),n+m){
        for(int i=0;i<n;++i){
            scanf("%s%d%d%d%d",mon,&d,&year,&h,&r);
            order[i].num=r,order[i].t=Time(year,MON(mon),d,h); 
        }
        int top=0,tail=0,p=0;
        __int64 sum=0;
        scanf("%d%d",&t,&s);
        for(int i=0;i<m;++i){
            scanf("%d",&a);
            while(top<tail && q[tail-1].num+(i-q[tail-1].t)*s>=a)--tail;
            q[tail].num=a,q[tail++].t=i;
            while(p<n && i == order[p].t){
                while(q[top].t+t<i)++top;
                sum+=(q[top].num+(i-q[top].t)*s)*order[p++].num;
            }
        }
        printf("%I64d\n",sum);
    }
    return 0;
}
