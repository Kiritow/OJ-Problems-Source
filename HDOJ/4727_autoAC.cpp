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
int a[100010];
int main()
{
    int T;
    int n;
    scanf("%d",&T);
    int iCase = 0;
    while(T--)
    {
        iCase++;
        scanf("%d",&n);
        for(int i = 0;i < n;i++)
            scanf("%d",&a[i]);
        int ans = 1;
        for(int i = 1;i < n;i++)
            if(a[i] != a[i-1] + 1)
            {
                ans = i+1;
                break;
            }
        printf("Case #%d: %d\n",iCase,ans);
    }
    return 0;
}
