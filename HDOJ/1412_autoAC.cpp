#include <stdio.h>
#include<algorithm>
int p[20005];
using namespace std;
int main()
{
    int a,b,i;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        for(i=0;i<a+b;i++)
        scanf("%d",&p[i]);
        sort(p,p+(a+b));
        printf("%d",p[0]);
        for(i=1;i<a+b;i++)
        {
            if(p[i]!=p[i-1])
            printf(" %d",p[i]);
        }
        printf("\n");
    }
    return 0;
}
