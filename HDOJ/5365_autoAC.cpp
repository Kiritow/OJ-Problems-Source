#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<queue>
#include<math.h>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<string>
#include<algorithm>
#include<iostream>
#define exp 1e-10
#define ll __int64
using namespace std;
const int N = 25;
const int inf = 1000000000;
const int mod = 1000000007;
int x[N],y[N],s[6];
int sqare(int x1,int y1,int x2,int y2)
{
    return (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
}
bool judge(int i,int j,int k,int l)
{
    int t=0;
    s[t++]=sqare(x[i],y[i],x[j],y[j]);
    s[t++]=sqare(x[j],y[j],x[k],y[k]);
    s[t++]=sqare(x[k],y[k],x[l],y[l]);
    s[t++]=sqare(x[l],y[l],x[i],y[i]);
    s[t++]=sqare(x[i],y[i],x[k],y[k]);
    s[t++]=sqare(x[l],y[l],x[j],y[j]);
    sort(s,s+6);
    if(s[0]==s[1]&&s[2]==s[3]&&s[1]==s[2]&&s[4]==2*s[0]&&s[5]==s[4])
        return true;
    return false;
}
int main()
{
    int n,i,j,k,l,t;
    while(~scanf("%d",&n))
    {
        t=0;
        for(i=1;i<=n;i++)
            scanf("%d%d",&x[i],&y[i]);
        for(i=1;i<=n;i++)
            for(j=i+1;j<=n;j++)
                for(k=j+1;k<=n;k++)
                    for(l=k+1;l<=n;l++)
                        if(judge(i,j,k,l))
                            t++;
        printf("%d\n",t);
    }
    return 0;
}
