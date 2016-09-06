#include<cstdio>
#include<stdlib.h>
const int maxn=500005;
struct time
{
    int start;
    int end;
}t[maxn];
int cmp(const void*a,const void*b)
{
    time*c=(time*)a;
    time*d=(time*)b;
    return c->start-d->start;
}
int max(int a,int b)
{
    return a>b?a:b;
}
int main()
{
    int N;
    while(~scanf("%d",&N))
    {
        int a,b,c,d;
        char ss;
        int i;
        for(i=0;i<N;i++)
        {
            scanf("%d%c%d%d%c%d",&a,&ss,&b,&c,&ss,&d);
            t[i].start=a*60+b;
            t[i].end=c*60+d;
        }
        qsort(t,N,sizeof(t[0]),cmp);
        int starttime=t[0].start,endtime=t[0].end;
        int alltime=0;
        for(i=1;i<N;i++)
        {
            if(t[i].start<=endtime)
            {
                endtime=max(endtime,t[i].end);
            }
            else 
            {
                alltime+=(endtime-starttime);
                starttime=t[i].start;
                endtime=t[i].end;
            }
        }
        alltime+=(endtime-starttime);
        printf("%d\n",1440-alltime);
    }
    return 0;
}
