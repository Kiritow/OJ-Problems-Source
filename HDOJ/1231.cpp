#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXL 10240
int a[MAXL];
typedef struct
{
    int result,start,ends;
}PACK;
PACK MaxSum(int N)
{
    int sum=-1;
    int tmp=0;
    int start=0;
    int ends=0;
    int tmpstart=0;
    int tmpends=0;
    for(int i=0;i<N;i++)
    {
        if(tmp>0)
        {
            tmp+=a[i];
            tmpends=i;
        }
        else
        {
            tmp=a[i];
            tmpstart=i;
        }
        if(tmp>sum)
        {
            sum=tmp;
            start=tmpstart;
            ends=tmpends;
        }
    }
    if(ends<start)
    {
        ends=start;
    }
    PACK c;
    c.result=sum;
    c.start=start;
    c.ends=ends;
    return c;
}
int main()
{
    int t;
    while(scanf("%d",&t)==1&&t!=0)
    {
        bool check=true;
        for(int i=0;i<t;i++)
        {
            scanf("%d",&a[i]);
            if(check&&a[i]>=0) check=false;
        }
        if(check)
        {
            printf("0 %d %d\n",a[0],a[t-1]);
            continue;
        }
        PACK c=MaxSum(t);
        printf("%d %d %d\n",c.result,a[c.start],a[c.ends]);
    }
    return 0;
}
