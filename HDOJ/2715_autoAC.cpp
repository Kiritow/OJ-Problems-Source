#include<stdio.h>
#include<string.h>
typedef __int64 ll;
ll m;
ll cal(ll s,ll x)
{
    return (2*s+x-1)*x;
}
ll binary_search(ll x)
{
    ll left,right,mid,tmp;
    left=1,right=m/2+1;
    while(left<=right)
    {
        mid=(left+right)>>1;
        tmp=cal(mid,x);
        if(tmp==2*m)
            return mid;
        else if(tmp<2*m)
            left=mid+1;
        else
            right=mid-1;
    }
    return -1;
}
int main()
{
    ll i,tmp,num,cnt=1;    
    while(scanf("%I64d",&m)!=EOF)
    {
        num=0;
        for(i=2;i*i<=2*m+10;i++)
        {
            tmp=binary_search(i);
            if(tmp!=-1)
                num++;
        }
        printf("%I64d\n",num+1);
    }
    return 0;
}
