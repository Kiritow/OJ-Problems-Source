#include <stdio.h>
#include<math.h>
int main(int argc, char *argv[])
{
    double s;
    int i,x1,x2,y1,y2,n,t;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        if(x1+y1>x2+y2) 
        {
            t=x1;x1=x2;x2=t;
            t=y1;y1=y2;y2=t;
        }
        s=(y1-y2)*sqrt(2.0);
        for(i=x1+y1+1;i<=x2+y2;i++)
        {
            s=s+i*sqrt(2.0)+sqrt((double)(i*i+(i-1)*(i-1)));
        }
        printf("%.3lf\n",s);
    }
    return 0;
}
