#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
int main()
{
    int n,r;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&r);
        printf("Case %d:\n",i);
        for(int j=0; j <2 * r+1; j++)
        {
            for(int k=0; k<2 * r + 1; k++)
            {
                if( abs((j-r)*(j-r)+(k-r)*(k-r)-r*r+0.0)<=3 )
                    putchar('*');
                else
                    putchar(' ');
            }
            puts("");
        }
    }
    return 0;
}
