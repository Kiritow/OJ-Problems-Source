#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int n,m;
int MIN(int x,int y)
{
    if (x<y) return x;
    return y;
}
int main()
{
    int x1,y1,x2,y2,t,ii,i,j,k,fx11,fx12,fx21,fx22,move,x1o,x2o,y1o,y2o;
    double ansx,ansy;
    scanf("%d",&t);
    for (ii=1;ii<=t;ii++)
    {
        scanf("%d%d%d%d%d%d",&n,&m,&x1,&y1,&x2,&y2);
        fx11=1;fx12=1;fx21=1;fx22=1;
        if (x1==n&&fx11>0||x1==0&&fx11<0) fx11=-fx11;
        if (y1==m&&fx12>0||y1==0&&fx12<0) fx12=-fx12;
        if (x2==n&&fx21>0||x2==0&&fx21<0) fx21=-fx21;
        if (y2==m&&fx22>0||y2==0&&fx22<0) fx22=-fx22;
        for (i=1;i<=410000;i++)
        {
            if (abs(x1-x2)==abs(y1-y2)&&((x2-x1)/fx11>0)&&((y2-y1)/fx12>0)&&((x1-x2)/fx21 >0)&&((y1-y2)/fx22>0))//杩㈢告
            {
                ansx=(x1+x2)/2.0;
                ansy=(y1+y2)/2.0;
                break;
            }
            if (fx11>0) move=n-x1;
                else move=x1;
            if (fx12>0) move=MIN(move,m-y1);
                else move=MIN(move,y1);
            if (fx21>0) move=MIN(move,n-x2);
                else move=MIN(move,x2);
            if (fx22>0) move=MIN(move,m-y2);
                else move=MIN(move,y2);
//琛告
            if (x1==x2&&((y2-y1)/fx12>0)&&((y1-y2)/fx22>0)&&fx11==fx21&&(x1+fx11*abs(y2-y1)/2.0)>=0&&(x1+fx11*abs(y2-y1)/2.0)<=n)
            {
                ansx=x1+fx11*abs(y2-y1)/2.0;
                ansy=(y1+y2)/2.0;
                break;
            }
//告
            if (y1==y2&&((x2-x1)/fx11>0)&&((x1-x2)/fx21>0)&&fx12==fx22&&(y1+fx12*abs(x2-x1)/2.0)>=0&&(y1+fx12*abs(x2-x1)/2.0)<=m)
            {
                ansx=(x1+x2)/2.0;
                ansy=(y1+fx12*abs(x2-x1)/2.0);
                break;
            }
            x1=move*fx11+x1;
            y1=move*fx12+y1;
            x2=move*fx21+x2;
            y2=move*fx22+y2;
            if (x1==n&&fx11>0||x1==0&&fx11<0) fx11=-fx11;
            if (y1==m&&fx12>0||y1==0&&fx12<0) fx12=-fx12;
            if (x2==n&&fx21>0||x2==0&&fx21<0) fx21=-fx21;
            if (y2==m&&fx22>0||y2==0&&fx22<0) fx22=-fx22;
        }
        printf("Case #%d:\n",ii);
        if (i==410001)
        {
            printf("Collision will not happen.\n");
            continue;
        }
        else 
        {
            printf("%.1lf %.1lf\n",ansx,ansy);
        }
    }
    return 0;
}
