#include<iostream>
#include<queue>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iomanip>
#include<map>
#include<cstdlib>
#include<cmath>
#include<vector>
#define LL long long
#define IT __int64
#define zero(x) fabs(x)<eps
#define mm(a,b) memset(a,b,sizeof(a))
const int INF=0x7fffffff;
const double inf=1e8;
const double eps=1e-10;
const double PI=acos(-1.0);
const int Max=200001;
using namespace std;
int s[Max];
int t[Max];
int sign(double x)
{
    return (x>eps)-(x<-eps);
}
int main()
{
    int n,m,i,j,q,p,res,k;
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(i=1;i<=Max;i++)
        {
            s[i]=0;
        }
        for(i=1;i<=n;i++)
        {
            scanf("%d",&q);
            s[q]=1;
        }
        k=0;
        for(i=1;i<=Max;i++)
        {
            if(s[i]==0)
                t[++k]=i;
        }
        sort(t+1,t+(k+1));
        while(m--)
        {
            scanf("%d",&p);
            if(s[p]==0)
                printf("%d\n",p);
            else
            {
                int left=1;
                int right=k;
                while(left<right)
                {
                    int mid=(left+right)>>1;
                    if(p<t[mid])
                    {
                        res=t[mid];
                        right=mid-1;
                        if(p<t[right])
                            res=t[right];
                    }
                    else
                    {
                        left=mid+1;
                        if(p<t[left])
                            res=t[left];
                    }
                }
                printf("%d\n",res);
            }
        }
    }
    return 0;
}
