#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 1000
int co_prime[N];    
int unco_prime[N];    
int s[N];
int Gcd(int a, int b)
{
    return a%b?Gcd(b,a%b):b;
}
int main()
{
    int t,n,i,j,sum;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d",&s[i]);
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(i == j)continue;
                if(Gcd(s[i],s[j]) == 1)co_prime[i] ++;
                else unco_prime[i] ++;
            }
        }
        sum = 0;
        for(i=1;i<=n;i++)sum += co_prime[i] * unco_prime[i];
        printf("%d\n",n*(n-1)*(n-2)/6- sum/2);
        for(i=0;i<=n;i++)co_prime[i] = unco_prime[i] = 0;
    }
    return 0;
}
