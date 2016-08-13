#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int main()
{
    int n,i,j,k,a,b,c;
    int ans[1000],len;
    while(~scanf("%d",&n),n)
    {
        len = 0;
        for(i = 1; i<=n; i*=10)
        {
            c = (n/i)/11;
            b = (n/i)%11;
            if(b+c && b<10)
            {
                a = (n-b*i-11*c*i)/2;
                if(n == 2*a+b*i+11*c*i)
                    ans[len++] = a+b*i+c*i*10;
            }
            b--;
            if(b+c && b>=0)
            {
                a = (n-b*i-11*c*i)/2;
                if(n == 2*a+b*i+11*c*i)
                    ans[len++] = a+b*i+c*i*10;
            }
        }
        if(len)
        {
            sort(ans,ans+len);
            printf("%d",ans[0]);
            for(i = 1; i<len; i++)
                if(ans[i]!=ans[i-1])
                    printf(" %d",ans[i]);
            printf("\n");
        }
        else
            printf("No solution.\n");
    }
    return 0;
}
