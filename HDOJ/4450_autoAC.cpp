#include<cstdio>
int main()
{
    int n,i,s,a;
    while(scanf("%d",&n),n)
    {
        s=0;
        while(n--){scanf("%d",&a);s+=a*a;}
        printf("%d\n",s);
    }
    return 0;
}
