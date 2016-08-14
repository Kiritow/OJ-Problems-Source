#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
using namespace std;
int num[100005];
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        for(int i=1;i<=n;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            num[i]=a-b;
        }
        int i=1,j=n;
        int maxn=0;
        while(i<=n)
        {
            int sum=0;
            int x=i,y=j;
            int flag=0;
            while(1)
            {
                sum+=num[x];
                if(sum<0)
                break;
                x++;
                flag++;
                if(x-1==y)
                break;
                if(x>n)
                {
                 x=1;
                }
            }
            i=i+flag+1;
            maxn=max(maxn,flag);
            j+=flag+1;
            if(j>n)
            j-=n;
        }
        printf("%d\n",maxn);
    }
}
