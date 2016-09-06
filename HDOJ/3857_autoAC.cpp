#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int n,i,a;
    int out;
    while (scanf("%d",&n)!=EOF)
    {
        out=0;
        for (i=1;i<=n;i++)
        {
            scanf("%d",&a);
            if (a==i)
            {
                if (out==0) printf("%d",a);
                else printf(" %d",a);
                out=1;
            }
        }
        if (out==1) printf("\n");
        else printf("No Mistake\n");
    }
    return 0;
}
