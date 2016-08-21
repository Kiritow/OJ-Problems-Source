#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct node
{
    int num;
    char name[50];
    char p[5];
    int time;
    int ok;
};
struct node p[50];
int get_time(char s[])
{
    int len=strlen(s),i;
    int t1,t2,flag,sum;
    t1=t2=0;
    flag=0;
    sum=0;
    for(i=0;i<len;i++)
    {
        if(s[i]==' ')
        {
            sum+=(t2-t1+1);
            flag=t1=t2=0;
            continue;
        }
        if(s[i]=='-')
        {
            flag=1;
            continue;
        }
        if(!flag)
            t1=t1*10+s[i]-'0';
        else
            t2=t2*10+s[i]-'0';
    }
    sum+=t2-t1+1;
    return sum;
}
bool cmp(node a,node b)
{
    return a.num<b.num;
}
bool cmp2(node a,node b)
{
    if(a.ok!=b.ok)
        return a.ok<b.ok;
    return a.num<b.num;
}
int main()
{
    int i;
    char s[500],hh[500];
    int dd,mm,ss;
    int flag = 0;
    while(scanf("%d",&p[0].num)!=EOF,p[0].num)
    {
        for(i=0;i<22;i++)
            p[i].ok=0;
        int temp;
        scanf("%s %s",p[0].name,p[0].p);
        getchar();
        gets(s);
        p[0].time=get_time(s);
        for(i=1;i<22;i++)
        {
            scanf("%d %s %s",&p[i].num,p[i].name,p[i].p);
            getchar();
            gets(s);
            p[i].time=get_time(s);
        }
        scanf("%s",hh);
        dd=hh[0]-'0';
        mm=hh[2]-'0';
        ss=hh[4]-'0';
        int mark=0;
        sort(p,p+22,cmp);
        for(i=0;i<22;i++)
        {
            if(p[i].p[0]=='G')
            {
                p[i].ok=1;
                mark=1;
                break;
            }
        }
        int count=0;
        for(i=0;i<22;i++)
        {
            if(p[i].p[0]=='D')
            {
                if(dd==0)
                    break;
                p[i].ok=2;
                dd--;
            }
        }
        for(i=0;i<22;i++)
        {
            if(p[i].p[0]=='M')
            {
                if(mm==0)
                    break;
                p[i].ok=3;
                mm--;
            }
        }
        for(i=0;i<22;i++)
        {
            if(p[i].p[0]=='S')
            {
                if(ss==0)
                    break;
                p[i].ok=4;
                ss--;
            }
        }
        if(mark!=1 || dd!=0 || mm!=0 || ss!=0)
        {
            printf("IMPOSSIBLE TO ARRANGE\n\n");
            continue;
        }
        int maxn=-1,max_i;
        for(i=0;i<22;i++)
        {
            if(p[i].ok)
            {
                if(p[i].time>=maxn)
                {
                    maxn=p[i].time;
                    max_i=i;
                    if(p[i].time==maxn)
                    {
                        if(p[i].num>p[max_i].num)
                            max_i=i;
                    }
                }
            }
        }
        printf("%d %s %s\n",p[max_i].num,p[max_i].name,p[max_i].p);
        int col=p[max_i].num;
        sort(p,p+22,cmp2);
        for(i=0;i<22;i++)
        {
            if(p[i].ok && col!=p[i].num)
                printf("%d %s %s\n",p[i].num,p[i].name,p[i].p);
        }
        printf("\n");
    }
    return 0;
}
