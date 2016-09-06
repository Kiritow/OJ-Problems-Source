#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
double f[1<<20], p[25];
int main()
{
    while(scanf("%d", &n)!=EOF)
    {
        for(int i=0; i<n; i++)
            scanf("%lf", &p[i]);
        int all=(1<<n)-1;
        f[all]=0;
        for(int s=all-1; s>=0; s--)
        {
            double temp=0;
            f[s]=1;
            for(int i=0; i<n; i++)
            {
                if(s&(1<<i)) continue;
                f[s]+=f[s|(1<<i)]*p[i];
                temp+=p[i];
            }
            f[s]/=temp;
        }
        printf("%lf\n", f[0]);
    }
}
