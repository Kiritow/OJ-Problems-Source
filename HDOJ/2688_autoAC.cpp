#include<algorithm> 
#include<string.h>
using namespace std;
const int maxn=10005;
const int maxm=3000005;
int c[maxn],a[maxm],n;
int sum(int x)
{
    int s=0;
    while(x>=1)
    {
        s+=c[x];
        x-=x&(-x);
    }
    return s;
}
void updata(int i)
{
    while(i<=maxn-1)
    {
        c[i]++;
        i+=i&(-i);
    }
}
int main()
{
    int i,m,x,y;
    __int64 ans;
    char str[2];
    while(scanf("%d",&n)>0)
    {
        memset(c,0,sizeof(c));
        ans=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            updata(a[i]);
            ans+=sum(a[i]-1);
        }
        scanf("%d",&m);
        while(m--)
        {
            scanf("%s",str);
            if(str[0]=='Q')
                printf("%I64d\n",ans);
            else 
                if(str[0]=='R')
                {
                    scanf("%d %d",&x,&y);
                    int count=a[x];
                    for(i=x;i<y;i++)
                    {
                        a[i]=a[i+1];
                        if(a[i]>count)
                            ans--;
                        else
                            if(a[i]<count)
                                ans++;
                    }
                    a[y]=count;
                }
        }
    }
    return 0;
}
