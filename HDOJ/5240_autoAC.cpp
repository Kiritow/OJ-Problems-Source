#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-4;
struct node
{
    long long r,s,l;
}exam[111111];
bool cmp(node a,node b)
{
    return a.s<b.s;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int ncase=1;ncase<=T;ncase++)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%I64d%I64d%I64d",&exam[i].r,&exam[i].s,&exam[i].l);
        sort(exam,exam+n,cmp);
        for(int i=n-1;i>0;i--)
            exam[i].s-=(exam[i-1].s+exam[i-1].l);
        int flag=1,i=0,j=0;
        while(i<n)
        {
            if(exam[i].s<exam[j].r)
            {
                if(i==j)
                {
                    flag=0;
                    break;
                }
                exam[j].r-=exam[i].s;
                i++;
            }
            else
            {
                exam[i].s-=exam[j].r;
                j++;
            }
        }
        if(flag)
            printf("Case #%d: YES\n",ncase);
        else
            printf("Case #%d: NO\n",ncase);
    }
    return 0;
}
