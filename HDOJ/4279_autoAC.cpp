#include"iostream"
#include"cstdio"
#include"cstring"
using namespace std;
const unsigned __int64 limit=3037000498;
unsigned __int64 solve(unsigned __int64 x)
{
    unsigned __int64 ans,low,mid,up,temp;
    low=1;up=limit;
    while(low<=up)
    {
        mid=(low+up)>>1;
        temp=mid*mid+4*mid;
        if(temp<=x)    low=mid+1;
        else        up=mid-1;
    }
    low--;
    ans=low*(low+1)/2 + (low/2 + low%2)*3;
    temp=x-(low*low+4*low);
    if(!temp)    return ans;
    if(temp<=(low+1)*2)
    {
        if((low+1)%2)    ans+=temp/2 + temp%2;
        else            ans+=(temp-1)/2 + (temp-1)%2;
    }
    else
    {
        ans+=low+1;
        if((low+1)%2)    ans+=temp-(low+1)*2;
    }
    return ans;
}
int main()
{
    int T;
    unsigned __int64 a,b,ans[2];
    cin>>T;
    while(T--)
    {
        scanf("%I64u%I64u",&a,&b);
        if(b<=5)    {printf("0\n");continue;}
        if(a<=6)a=0;
        else    a-=6;
        b-=5;
        ans[0]=solve(a);
        ans[1]=solve(b);
        printf("%I64u\n",ans[1]-ans[0]);
    }
    return 0;
}
