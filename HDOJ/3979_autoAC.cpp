#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
struct Node
{
    int h,g;
}node[10010];
int n,m;
bool cmp(Node a,Node b)
{
    return a.h*b.g < b.h*a.g;
}
int main()
{
    int T;
    int iCase = 0;
    scanf("%d",&T);
    while(T--)
    {
        iCase ++;
        scanf("%d%d",&n,&m);
        for(int i = 0;i < n;i++)
        {
            scanf("%d%d",&node[i].h,&node[i].g);
            node[i].h = (node[i].h + m - 1)/m;
        }
        sort(node,node+n,cmp);
        long long ans = 0;
        int cnt = 0;
        for(int i = 0;i < n;i++)
        {
            cnt += node[i].h;
            ans += (long long)cnt*node[i].g;
        }
        printf("Case #%d: %I64d\n",iCase,ans);
    }
    return 0;
}
