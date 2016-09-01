#include<cstdio>
int main()
{
    int n;
    int a1,a2,a3;
    int ans;
    while(~scanf("%d%d%d%d",&n,&a1,&a2,&a3))
    {
        if(n==0 && a1==0 && a2==0 && a3==0)
            break;
        ans = 4*n-1;
        if(a2>a1)
        {
            ans+=a2-a1;
        }
        else
        {
            ans+=n+a2-a1;
        }
        if(a3<a2)
        {
            ans+=a2-a3;
        }
        else
            ans+=n+a2-a3;
        printf("%d\n",ans);
    }
    return 0;
}
