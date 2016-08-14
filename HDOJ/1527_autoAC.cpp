#include<stdio.h>
#include<math.h>
int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b)==2)
    {
        double j,k,r,R;
        int t;
        if(a>b)
        {
            t=a;
            a=b;
            b=t;
        }
        r=(sqrt(5.0)-1)/2;
        R=1.0/r;
        j=(int)(r*a);
        if(a!=(int)(j*R))
            j+=1;
        printf("%d\n",b!=(int)(j*R)+j);
    }
    return 0;
}
