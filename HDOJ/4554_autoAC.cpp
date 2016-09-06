#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
using namespace std;
int numa[11],numb[11];
int main()
{
    int T,a,b;
    scanf("%d",&T);
    while(T--)
    {
    scanf("%d%d",&a,&b);
    int x=(a+b)/2;
    int y=a-x;
    int coua=0,coub=0;
    int ita=abs(x);
    int itb=abs(y);
    while(ita)
    {
        numa[coua++]=ita%10;
        ita/=10;
    }
    while(itb)
    {
        numb[coub++]=itb%10;
        itb/=10;
    }
    int xx=0,yy=0;
    for(int i=0;i<coua;i++)
        xx=xx*10+numa[i];
    for(int i=0;i<coub;i++)
        yy=yy*10+numb[i];
    if(x<0)
        xx=-xx;
    if(y<0)
        yy=-yy;
    printf("%d %d\n",xx+yy,xx-yy);
    }
    return 0;
}
