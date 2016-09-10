#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stack>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
#define LL __int64
int main()
{
    LL x, k;
    int cse = 1;
    while(scanf("%I64d %I64d",&x,&k)!=EOF){
        if(!x) break;
        printf("Case #%d: ",cse++);
        LL i = 1;
        LL tmp = x / i;
        while(tmp >= i+1 && i<k){
            tmp = tmp - tmp / (i+1);
            i++;
        }
        printf("%I64d\n",tmp*k);
    }
    return 0;
}
