#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int a[805][805],b[805][805],c[805][805];
int main()
{
    int n,i,j,k;
    while(~scanf("%d",&n))
    {
        for(i = 0; i<n; i++)
            for(j = 0; j<n; j++)
            {
                scanf("%d",&a[i][j]);
                a[i][j]%=3;
                c[i][j] = 0;
            }
        for(i = 0; i<n; i++)
            for(j = 0; j<n; j++)
            {
                scanf("%d",&b[i][j]);
                b[i][j]%=3;
            }
        for(i = 0; i<n; i++)
            for(j = 0; j<n; j++)
            {
                if(!a[i][j])
                continue;
                for(k = 0; k<n; k++)
                    c[i][k] = c[i][k]+a[i][j]*b[j][k];
            }
        for(i = 0; i<n; i++)
        {
            for(j = 0; j<n; j++)
                if(j==n-1)
                    printf("%d\n",c[i][j]%3);
                else
                    printf("%d ",c[i][j]%3);
        }
    }
    return 0;
}
