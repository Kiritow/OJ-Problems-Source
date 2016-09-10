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
int main()
{
    int T;
    int iCase = 0;
    scanf("%d",&T);
    long long a,b;
    while(T--){
        iCase++;
        scanf("%I64d%I64d",&a,&b);
        a--;
        long long ans = (b*(b+1)/2)*(b*(b+1)/2) - (a*(a+1)/2)*(a*(a+1)/2);
        printf("Case #%d: %I64d\n",iCase,ans);
    }
    return 0;
}
