#pragma comment(linker, "/STACK:1024000000,1024000000")
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
const int MAXN = 100010;
int a[MAXN];
int num[40];
int bit[40];
int main()
{
    int T;
    int n,m;
    bit[0] = 1;
    for(int i = 1;i <= 31;i++)
        bit[i] = 2*bit[i-1];
    scanf("%d",&T);
    int iCase = 0;
    while(T--)
    {
        iCase++;
        scanf("%d%d",&n,&m);
        for(int i = 0;i < n;i++)
            scanf("%d",&a[i]);
        long long tot = (long long)n*(n+1)/2;
        int last = 0;
        int i = 0,j = 0;
        memset(num,0,sizeof(num));
        long long sum = 0;
        while(j < n)
        {
            for(int k = 0;k <=31;k++)
                if(a[j] & bit[k])
                    num[k]++;
            int s = 0;
            for(int k = 0;k <= 31;k++)
                if(num[k])
                    s += bit[k];
            if(s >= m)
            {
                while(s >=m)
                {
                    for(int k = 0;k <= 31;k++)
                        if(a[i] & bit[k])
                            num[k]--;
                    s = 0;
                    for(int k = 0;k <= 31;k++)
                        if(num[k])
                            s += bit[k];
                    i++;
                }
                sum += (long long)(n-j)*(i-last);
                last = i;
            }
            j++;
        }
        printf("Case #%d: ",iCase);
        cout<<tot-sum<<endl;
    }
    return 0;
}
