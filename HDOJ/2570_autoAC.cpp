#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int c,n,v,w,i,V,j;
    double pi[101],p;
    scanf("%d",&c);
    while(c--)
    {
        scanf("%d%d%d",&n,&v,&w);
        for(i=0;i<n;i++)
        {
            scanf("%lf",&pi[i]);
        }
        sort(pi,pi+n);        
        j=n;
        while(1)
        {
            p=0;
            for(i=0;i<j;i++)
                p+=pi[i];
            p/=j;
            V=j*v;
            j--;
            if(j==0||p<=w)
                break;
        }
        if(j==0&&p>w)
            printf("0 0.00\n");
        else
            printf("%d %.2lf\n",V,p/100);
    }
return 0;
}
