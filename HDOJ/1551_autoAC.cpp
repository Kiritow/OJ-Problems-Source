#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<queue>
#define nz 250001 
#define nz1 500 
using namespace std;
double sb[nz];
double sum;
int a,b;
int cnm(double x)
{
    int cnt = 0;  
    for(int i = 0; i<a; i++)  
    {  
        cnt+=(int)(sb[i]/x);  
    }  
    if(cnt>=b) return 1;   
    return 0; 
}
int main()
{
    int c,d,e,f;
    while(scanf("%d%d",&a,&b)&&(a||b))
    {
        sum=0;
        for(int y=0;y<a;y++)
        {
            scanf("%lf",&sb[y]);
            sum=sum+sb[y];
        }    
        sum =sum/(double)b;
        double l=0,r=sum;
        while(r-l>1e-10)
        {
            double mid;
            mid=(r+l)/2.0;
            if(cnm(mid))
            {
                l=mid;
            }
            else
            {
                r=mid;
            }
        }
        printf("%.2lf\n",l);
    }
    return 0;
}
