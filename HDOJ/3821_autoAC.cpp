#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define maxn 1005
int x[maxn],y[maxn];
int map[maxn];
int main()
{
    int i,j,T,C=1,n,m;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                int t;
                scanf("%d",&t);
                if(t==1)
                {
                    x[i]=j;
                    map[j]=i;
                }
            }
        }
        for(i=0; i<n; i++)
        {
            y[i]=x[i];
        }
        vector<int>v;
        for(i=1; i<n; i++)
        {
            for(j=i; j>=1; j--)
            {
                if(y[j]<y[j-1])
                {
                    swap(y[j],y[j-1]);
                    v.push_back(j-1);
                }
            }
        }
        printf("Case %d: %d\n",C++,v.size());
        int len=v.size();
        for(i=0;i<len-1;i++)
        {
            printf("%d ",v[i]);
        }
        if(len!=0)
        {
            printf("%d",v[len-1]);
        }
        printf("\n");
    }
    return 0;
}
