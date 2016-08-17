#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<iostream>
#include<string.h>
using namespace std;
int main()
{
 int m;
    int n,v;
    while(scanf("%d %d",&n,&v),n,v)
    {
        int i;
        m=0;
        int a;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a);
            m=max(a,m);
        }
        printf("%.0lf\n",ceil(double(v)/m)*3);
    }
return 0;
}
