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
    int n,b,q;
    while(T--){
        iCase++;
        scanf("%d%d%d",&n,&b,&q);
        printf("Case #%d: ",iCase);
        if(q == 1){
            bool flag = false;
            while(b){
                if(n == b){
                    flag = true;
                    break;
                }
                b /= 10;
            }
            if(flag)printf("1.00000\n");
            else printf("0.00000\n");
        }
        else if(q == 10 || q == 100 || q == 1000){
            b *= 100000;
            bool flag = false;
            while(b){
                if(n == b){
                    flag = true;
                    break;
                }
                b /= 10;
            }
            if(flag)printf("1.00000\n");
            else printf("0.00000\n");
        }
        else {
            double ans = (log(n+1)-log(n))/log(10);
            printf("%.5lf\n",ans);
        }
    }
    return 0;
}
