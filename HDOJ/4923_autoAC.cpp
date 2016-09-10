#include <iostream>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
const int maxn=1e5+10;
const double eps=1e-8;
const int INF=2e9;
struct node{
    int id,num0,num1;
    double rate;
}e[maxn],f,g;
int t,a[maxn];
stack<node>mm;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int i,j,k,n,p,q;
        double num,ans=0;
        t=0;
        scanf("%d",&n);
        int l=0,r=n-1;
        for(i=0;i<n;i++)scanf("%d",&a[i]);
        a[n]=1;
        while(a[l]==0)l++;
        while(a[r]==1)r--;
        if(l>r){printf("0.000000\n");continue;}
        for(i=l;i<=r;)
        {
            j=k=0;
            while(a[i]==1){i++;j++;}
            while(a[i]==0){i++;k++;}
            e[t].id=t;e[t].num1=j;e[t].num0=k;e[t].rate=1.0*j/(j+k);
            t++;
        }
        while(!mm.empty())mm.pop();
        for(i=0;i<t;i++)
        {
            if(mm.empty())mm.push(e[i]);
            else
            {
                f=mm.top();
                if(f.rate<=e[i].rate)mm.push(e[i]);
                else
                {
                    g=e[i];
                    while(true)
                    {
                        f=mm.top();
                        if(f.rate>g.rate)
                        {
                            g.num1+=f.num1;
                            g.num0+=f.num0;
                            g.rate=1.0*g.num1/(g.num0+g.num1);
                            mm.pop();
                        }
                        else
                        {
                            mm.push(g);
                            break;
                        }
                        if(mm.empty())
                        {
                            mm.push(g);
                            break;
                        }
                    }
                }
            }
        }
        while(!mm.empty())
        {
            f=mm.top();
            mm.pop();
            ans+=f.rate*f.rate*f.num0+(1-f.rate)*(1-f.rate)*f.num1;
        }
        printf("%.6f\n",ans);
    }
    return 0;
}
