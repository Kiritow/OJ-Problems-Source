#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
struct P
{
    double x,y;
}c[25],d[25];
int ans[25];
bool operator<(P a,P b)
{
    if(a.x!=b.x)return a.x<b.x;
    return a.y<b.y;
}
int ctd[255];
int main()
{
    int n;
    int T=0;
    char a,b;
    double pi=acos(-1.0);
    double eps=1e-7;
    ctd['C']=0,ctd['D']=1,ctd['E']=2;
    ctd['F']=3,ctd['G']=4,ctd['A']=5;
    ctd['B']=6;
    char dtc[10];
    dtc[0]='C',dtc[1]='D',dtc[2]='E';
    dtc[3]='F',dtc[4]='G',dtc[5]='A';
    dtc[6]='B';
    while(scanf("%d",&n),n)
    {
        scanf(" %c %c",&a,&b);
        int i,j;
        for(i=0;i<n;i++)
            scanf("%lf %lf",&c[i].x,&c[i].y);
        for(double i=-60.0;i<61.0;i+=0.005)
        {
            double ang;
            ang=i*pi/180.0;
            for(j=0;j<n;j++)
            {
                d[j].x=c[j].x*cos(ang)+c[j].y*sin(ang);
                d[j].y=-c[j].x*sin(ang)+c[j].y*cos(ang);
            }
            sort(d,d+n);
            double sd=(d[n-1].y-d[0].y)/(ctd[b]-ctd[a]);
            double ssd=sd*2;
            if(ssd+eps<1.0 || ssd>5.0+eps)
                continue;
            ans[0]=ctd[a];
            for(j=1;j<n;j++)
            {
                if(d[j].x-d[j-1].x>5*ssd+eps || d[j].x-d[j-1].x+eps<ssd)
                    break;
                if(d[j].y-d[j-1].y>(6-ans[j-1])*sd+eps)
                    break;
                if(d[j-1].y-d[j].y>ans[j-1]*sd+eps)
                    break;
                double dis=d[j].y-d[j-1].y;
                int tmp=(int)(dis/sd);
            if(dis>=0)
                {
                if(tmp*sd-dis+eps<0)
                    tmp++;
                if(tmp*sd-dis>0+eps)
                    break;
                }
                else 
                {
                 if(tmp*sd-dis>0+eps)
                    tmp--;
                 if(tmp*sd-dis+eps<0)
                     break;
                }
                ans[j]=tmp+ans[j-1];
            }
            if(j==n)
            {
                break;
            }
        }
        printf("Case %d: ",++T);
        for(i=0;i<n;i++)
        {
            printf("%c",dtc[ans[i]]);
        }
        printf("\n");
    }
    return 0;
}
