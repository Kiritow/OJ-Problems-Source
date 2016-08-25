#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int Max = 1000 + 10;
struct node 
{
    int value;
    int volum;
}a[Max];
int f[Max];
int main()
{
    int t;
    int n,v;
    int i,j;
    while(scanf("%d",&t) != EOF)
    {
        while(t--)
        {
            scanf("%d %d",&n,&v);
            memset(f, 0, sizeof(f));
            for(i=1; i<=n; i++)
            {
                scanf("%d",&a[i].value);
            }
            for(i=1; i<=n; i++)
            {
                scanf("%d",&a[i].volum);
            }
            for(i=1; i<=n; i++)
            {
                for(j=v; j>=a[i].volum; j--)
                {
                    f[j] = max(f[j], f[j-a[i].volum] + a[i].value);
                }
            }
            cout<<f[v]<<endl;
        }
    }
    return 0;
}
