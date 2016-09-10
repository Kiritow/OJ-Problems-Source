#include<iostream>
#include<cstdio>
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        if(n<k)
            printf("0\n");
        else
        {
            int l=n%k;
            if(l<=k/2)
                printf("%d\n",n*n-l*l);
            else
                printf("%d\n",n*n-(k-l)*(k-l));
        }
    }
    return 0;
}
