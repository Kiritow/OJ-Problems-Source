#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
    int t;
    int a,b;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%d %d",&a,&b);
        printf("Scenario #%d:\n",i+1);
        if(a%2==0||b%2==0)
        {
            printf("%.2f\n",(double)a*b);
        }
        else
        {
            printf("%.2f\n",(double)a*b-1+sqrt(2));
        }
        printf("\n");
    }
    return 0;
}
