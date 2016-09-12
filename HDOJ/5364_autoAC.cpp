#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int maxn=1e4+5;
int a;
int b[maxn];
int main()
{
    int m;
    while(scanf("%d",&m)!=EOF)
    {
        memset(b,0,sizeof(b));
        for(int i=0; i<m; i++)
        {
            scanf("%d",&a);
            b[a]++;
        }
        int maxx=-99;
        int flag=0;
        for(int i=0; i<maxn; i++)
        {
            if(maxx<b[i])
            {
                maxx=b[i];
                flag=i;
            }
        }
        if(maxx<=m/2)
            printf("-1\n");
        else
            printf("%d\n",flag);
    }
    return 0;
}
