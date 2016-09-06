#include<stdio.h>
#include<math.h>
int main()
{
    int T;
    int iCase=0;
    int n,m,k;
    scanf("%d",&T);
    while(T--)
    {
        iCase++;
        scanf("%d%d%d",&n,&m,&k);
        int t1=n,t2,t3=n;
        if(m<t1)t1=m;
        if(k<t1)t1=k;
        if(m>t3)t3=m;
        if(k>t3)t3=k;
        t2=n+m+k-t1-t3;
        n=t1;m=t2;k=t3;
        int res=0;
        if(n>1)res+=(int)(log(1.0*n)/log(2.0)+0.999);
        if(m>1)res+=(int)(log(1.0*m)/log(2.0)+0.999);
        if(k>1)res+=(int)(log(1.0*k)/log(2.0)+0.999);
        long long res1=(long long)n*m*k-1;
        printf("Case #%d: %I64d %d\n",iCase,res1,res);
    }    
    return 0;
}
