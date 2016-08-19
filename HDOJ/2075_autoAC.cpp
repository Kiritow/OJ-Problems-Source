#include<stdio.h>
int main()
{
        long int a,b;
        int n;
        scanf("%d",&n);
        while(n--)
        {
                scanf("%ld%ld",&a,&b);
                if(a<b) printf("NO\n");
                else if(a%b==0) printf("YES\n");
                else printf("NO\n");
        }
}
