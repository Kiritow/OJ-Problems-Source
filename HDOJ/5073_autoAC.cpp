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
double x[50010];
int main()
{
    int T;
    int n,k;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&k);
        for(int i = 0;i < n;i++)
            scanf("%lf",&x[i]);
        sort(x,x+n);
        if(n == k){
            printf("0\n");
            continue;
        }
        int cnt = n-k;
        double sum = 0;
        double sum2 = 0;
        for(int i = 0;i < cnt;i++){
            sum += x[i];
            sum2 += x[i]*x[i];
        }
        double ans = sum2 - 2*sum*(sum/cnt) + cnt*(sum/cnt)*(sum/cnt);
        for(int i = cnt;i < n;i++){
            sum += x[i];
            sum2 += x[i]*x[i];
            sum -= x[i-cnt];
            sum2 -= x[i-cnt]*x[i-cnt];
            ans = min(ans,sum2-2*sum*(sum/cnt)+cnt*(sum/cnt)*(sum/cnt));
        }
        printf("%.10lf\n",ans);
    }
    return 0;
}
