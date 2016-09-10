#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <cctype>
#include <ctime>
using namespace std;
int ans[8][8][8]={
    {
       {1}
    },
    {
        {2},
        {1,1}
    },
    {
        {3},
        {2,3},
        {1,1,1}
    },
    {
        {4},
        {2,6},
        {2,3,4},
        {1,1,1,1}
    },
    {
        {5},
        {3,10},
        {2,4,10},
        {2,3,4,5},
        {1,1,1,1,1}
    },
    {
        {6},
        {3,15},
        {2,6,20},
        {2,3,6,15},
        {2,3,4,5,6},
        {1,1,1,1,1,1}
    },
    {
        {7},
        {4,21},
        {3,7,35},
        {2,5,12,35},
        {2,3,5,9,21},
        {2,3,4,5,6,7},
        {1,1,1,1,1,1,1}
    },
    {
        {8},
        {4,28},
        {3,11,56},
        {2,6,14,70},
        {2,4,8,20,56},
        {2,3,4,7,12,28},
        {2,3,4,5,6,7,8},
        {1,1,1,1,1,1,1,1}
    }
};
int main()
{
    int n,m,r,T,tt=0;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&n,&m,&r);
        printf("Case #%d: %d\n",++tt,ans[n-1][m-1][r-1]);
    }
    return 0;
}
