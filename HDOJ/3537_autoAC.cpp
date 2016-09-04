#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string.h>
using namespace std;
int SG(int x)
{
    int tmp = x;
    int cnt = 0;
    while(tmp)
    {
        if(tmp&1)cnt++;
        tmp>>=1;
    }
    if(cnt&1)return 2*x;
    else return 2*x + 1;
}
int a[110];
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        for(int i = 0;i < n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        n = unique(a,a+n)-a;
        int sum = 0;
        for(int i = 0;i < n;i++)
            sum ^= SG(a[i]);
        if(sum)printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}
