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
int n,k;
int main()
{
    while(scanf("%d%d",&n,&k) == 2)
    {
        if(n == 0 && k == 0)break;
        if((n-1)%(k+1) == 0)printf("Jiang\n");
        else printf("Tang\n");
    }
    return 0;
}
