#include<iostream>
#include<stdlib.h>
using namespace std;
#define N 21
int n,sleep,awake;
struct Time
{
    int hour;
    int minite;
    int sec;
    void trans()
    {        sec=hour*60+minite;    }
    void retrans()
    {        sec+=24*60;        }
    void minusonesecond()
    {
        if(minite==0)
            hour--,minite=59;
        else minite--;
        if(hour<0)
            hour+=24;
    }
    void addonesecond()
    {
        if(minite==59)
            hour++,minite=0;
        else minite++;
        if(hour>23)
            hour-=24;
    }
    bool operator < (const Time a)const
    {    
        if(hour==a.hour)
        {
            return minite<a.minite;
        }
        return hour<a.hour;        
    }
};
struct Arrange
{
    Time tb,te;
} affire[N];
int cmp(const void *a,const void *b)
{
    struct Arrange *A=(Arrange*)a;
    struct Arrange *B=(Arrange*)b;
    if(B->tb<A->tb)
        return 1;
    return -1;
}
Time sle[N][2];
char evn[20];
void solve(bool flag)
{
    int i,j,begin,end,temp=0,nowlast=0,segn=0;
    Time temp1,temp2;
    for(i=2;i<=n;i++)
    {
        end=affire[i].tb.sec-1;
        begin=affire[i-1].te.sec+1;
        if(end<begin&&begin-end!=1)
            end+=24*60;
        if(end-begin+1>=sleep)
        {
            ++segn;
            temp1=affire[i-1].te;
            temp1.addonesecond();
            sle[segn][0]=temp1;
            temp1=affire[i].tb;
            temp1.minusonesecond();
            sle[segn][1]=temp1;
            nowlast=0;
        }
        else if(end-begin+1<sleep)
        {
            if(nowlast==0)
                nowlast+=affire[i-1].te.sec-affire[i-1].tb.sec+1;
            nowlast+=affire[i].te.sec-affire[i-1].te.sec+1;
            if(nowlast>awake)
            {
                printf("No\n");
                return ;
            }
        }
    }
        end=affire[1].tb.sec-1;
        begin=affire[n].te.sec+1;
        if(end<begin&&begin-end!=1)
            end+=24*60;
        if(end-begin+1>=sleep)
        {
            ++segn;
            temp2=affire[n].te;
            temp2.addonesecond();
            sle[segn][0]=temp2;
            temp1=affire[1].tb;
            temp1.minusonesecond();
            sle[segn][1]=temp1;
            nowlast=0;
        }
        else if(end-begin+1<sleep)
        {
            if(nowlast==0)
                nowlast+=affire[n].te.sec-affire[n].tb.sec+1;
            nowlast+=affire[1].te.sec-affire[n].te.sec+1;
            if(nowlast>awake)
            {
                printf("No\n");
                return ;
            }
        }
    if(n==0)
    {
        segn=1;
        printf("Yes\n%d\n",segn);
        printf("00:00-23:59\n");
        return;
    }
    else
    {
        if(segn!=0)
        {
        printf("Yes\n%d\n",segn);
        for(i=1;i<=segn;i++)
        {
            printf("%02d:%02d-%02d:%02d\n",sle[i][0].hour,sle[i][0].minite,sle[i][1].hour,sle[i][1].minite);
        }
        }
        else
            printf("No\n");
    }
}
int main()
{
    while(scanf("%d%d",&sleep,&awake)!=EOF)
    {
        sleep*=60,awake*=60;
        scanf("%d",&n);
        int i,j;
        bool flag=false;
        bool ss=false;
        for(i=1;i<=n;i++)
        {
            Time T1,T2;
            scanf("%d:%d-%d:%d",&T1.hour,&T1.minite,&T2.hour,&T2.minite);
            T1.trans(),T2.trans();
            if(T2.sec-T1.sec+1>awake)
            {
                ss=true;
            }
            if(T2<T1)
            {
                flag=true;
                T2.retrans();
            }
            affire[i].tb=T1,affire[i].te=T2;
        }
        if(ss)
        {
            printf("No\n");
            continue;
        }
        qsort(affire+1,n,sizeof(Time)*2,cmp);
        solve(flag);
    }
}
