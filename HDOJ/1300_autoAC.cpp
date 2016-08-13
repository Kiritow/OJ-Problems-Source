#include <iostream>   
#include <iomanip>   
#include <fstream>   
#include <sstream>   
#include <algorithm>   
#include <string>   
#include <set>   
#include <utility>   
#include <queue>   
#include <stack>   
#include <list>   
#include <vector>   
#include <cstdio>   
#include <cstdlib>   
#include <cstring>   
#include <cmath>   
#include <ctime>   
#include <ctype.h> 
using namespace std;
#define MAXN 1100
typedef struct kind
{
    int num,price;
}Kind;
Kind kind[MAXN];
int sum[MAXN];
int ans[MAXN];
int main()
{
    int t;
    int i,j;
    int n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        sum[0]=0;
        memset(ans,0,sizeof(ans));
        for(i=1;i<=n;i++)
        {
            scanf("%d%d",&kind[i].num,&kind[i].price);
            sum[i]=sum[i-1]+kind[i].num;
            ans[i]=(sum[i]+10)*kind[i].price;
        }
        for(i=1;i<=n;i++)                                
            for(j=1;j<=i;j++)                                   
                ans[i]=min(ans[i],(sum[i]-sum[j]+10)*kind[i].price+ans[j]);
        printf("%d\n",ans[n]);
    }
    return 0;
}
