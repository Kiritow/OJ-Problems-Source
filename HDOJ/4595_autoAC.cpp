#include<cstdio>
#include<cstring>
#include<map>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
map<string,int> match;
char s[100010][20];
int n,m,point[100010],one[100010],two[100010],sum_one[100010],sum_two[100010];
bool cmp(char a,char b)
{
    return a<b;
}
int main()
{
    int i,j,k,a,b,len,c,pos;
    ll l,r,ans;
    while(~scanf("%d%d",&n,&m))
    {
        for(i=1;i<=n;i++)
           scanf("%s",s[i]);
        match.clear();
        for(i=n;i>=1;i--)
        {
            len=strlen(s[i]);
            sort(s[i],s[i]+len,cmp);
            k=match[s[i]];
            if(k==0)
              point[i]=n+1;
            else
              point[i]=k;
            match[s[i]]=i;
        }
        a=n+1;b=n+1;
        for(i=n;i>=1;i--)
        {
            c=point[i];
            if(c<a)
              b=a,a=c;
            else if(c<b)
              b=c;
            one[i]=a;
            two[i]=b;
        }
        for(i=1;i<=n;i++)
        {
            sum_one[i]=sum_one[i-1]+(one[i]-1);
            sum_two[i]=sum_two[i-1]+(two[i]-1);
        }
        ans=0;
        while(m--)
        {
            scanf("%I64d%I64d",&l,&r);
            l+=ans;
            r-=ans;
            ans=0;
            pos=upper_bound(one+1,one+n,r)-one-1;
            if(pos>=l)
            ans+=r*(pos-l+1)-(sum_one[pos]-sum_one[l-1]);
            pos=upper_bound(two+1,two+n,r)-two-1;
            if(pos>=l)
            ans-=r*(pos-l+1)-(sum_two[pos]-sum_two[l-1]);
            printf("%I64d\n",ans);
        }
    }
}
