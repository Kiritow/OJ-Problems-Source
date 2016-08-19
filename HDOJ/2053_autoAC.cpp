#include<cstdio>
#include<cmath>
int main()
{
    int n,k;
    while(~scanf("%d",&n)){
        k=sqrt(n);
        if(k*k==n)printf("1\n");
        else printf("0\n");
    }
    return 0;
}
