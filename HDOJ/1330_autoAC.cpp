#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int main()
{
    int n,i;
    double sum;
    int f=1;
    while(scanf("%d",&n)!=EOF)
    {
        if(f)
        {
              printf("# Cards  Overhang\n");f=0;
        }
        sum=0;
        for(i=1;i<=n;i++)
        {
            sum=sum+1.0/(2*i);
        }
        printf("%5d     %.3lf\n",n,sum);
    }
    return 0;
}
