#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#include"math.h"
using namespace std;
char b[100];
int a[350];
int c[350];
int k;
int hw(int s[])
{
    int cnt=0;
    int x=k-1;
    while(cnt<x)
    {
        if(c[cnt]==c[x])
        {
            cnt++;
            x--;
        }
        else
            break;
    }
    if(cnt>=x)
        return 1;
    else
        return 0;
}
void  jz1(int m,int r)
{
    memset(c,0,sizeof(c));
     k=0;
    while(m)
    {
       c[k++]=m%r;
        m=m/r;
    }

}
void  jz2(int m,int r)
{
    memset(c,0,sizeof(c));
     memset(b,'\0',sizeof(b));
     k=0;
    while(m)
    {
       c[k++]=m%r;
        m=m/r;
    }
    for(int i=0;i<k;i++)
    {
       if(c[i]>=10)
            b[i]=c[i]-10+'A';
        else
            b[i]=c[i]+'0';
    }
    for(int i=k-1;i>=0;i--)
        printf("%c",b[i]);
    putchar('\n');
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
      int r;
      memset(a,0,sizeof(a));
      scanf("%d",&r);
      for(int i=1;i<=300;i++)
      {
         jz1(i*i,r);
         a[i]=hw(c);
      }
      int sum=0;
      for(int i=1;i<=300;i++)
      {
          if(a[i])
          sum+=i;
      }
      jz2(sum,r);
    }
    return 0;
}
