#include<stdio.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
#include<complex>
using namespace std;
typedef long long lld;
#define pb push_back
#define mp make_pair
#define X first
#define Y second
lld s[2010];
int main()
{
    int n;
    int cc=1;
    while(scanf("%d",&n)!=EOF)
    {
        if(n == 0)
            break;
        lld sum=0;
        bool zero=true;
        for(int i=0;i<n;i++)
        {
            scanf("%I64d",&s[i]);
            s[i+n]=s[i];
            sum+=s[i];
            if(s[i] != 0)
                zero=false;
        }
        if(sum < 0)
        {
            printf("Case %d: -1\n",cc++);
            continue;
        }
        if(sum == 0 && !zero)
        {
            printf("Case %d: -1\n",cc++);
            continue;
        }
        lld ans=0;
        for(int i=0;i<n;i++)
        {
            lld now=0;
            for(int j=0;j<n;j++)
            {
                now+=s[i+j];
                if(now < 0)
                {
                    lld x=-now/sum;
                    if(x*sum != -now)
                        x++;
                    ans+=x;
                }
            }
        }
        printf("Case %d: %I64d\n",cc++,ans);
    }
    return 0;
}
