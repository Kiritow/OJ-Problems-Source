#include<stdio.h>
#include<string.h>
#include<math.h>
#define pi acos(-1.0)
#define eps 1e-7
int main()
{
    int n,t,f,i,r,pep;
    double s[10005];
    double max,min,mid;
    scanf("%d",&t);
    while(t--)
    {
        min=0;max=0;
        scanf("%d%d",&n,&f);
        f++;
        for(i=0; i<n; i++)
        {
            scanf("%d",&r);
            s[i]=pi*r*r;
            if(max<s[i]) max=s[i];
        }
        while(max-min>eps)
        {
            mid=(max+min)/2;
            pep=0;
            for(i=0;i<n;i++)
            {
                pep+=(int)(s[i]/mid);
            }
            if(pep>=f)
                min=mid;
            else
                max=mid;
        }
        printf("%.4lf\n",mid);
    }
return 0;
}
