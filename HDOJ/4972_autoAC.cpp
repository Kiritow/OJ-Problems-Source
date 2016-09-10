#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;
const int maxn=1e5+100;
int n,a[maxn];
int main()
{
    int T,cas=1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        bool is=true;
        for(int i=2;i<=n;i++)
            if(abs(a[i]-a[i-1])>3||(a[i]==a[i-1]&&a[i]!=1))
            {
                is=false;
                break;
            }
        if(!is)
        {
            printf("Case #%d: 0\n",cas++);
            continue;
        }
        int cnt=0;
        for(int i=2;i<=n;i++)
        {
            if(a[i]==2&&a[i-1]==1)
                cnt++;
            if(a[i]==1&&a[i-1]==2)
                cnt++;
        }
        if(a[n])
            printf("Case #%d: %d\n",cas++,cnt*2+2);
        else
            printf("Case #%d: %d\n",cas++,cnt+1);
    }
    return 0;
}
