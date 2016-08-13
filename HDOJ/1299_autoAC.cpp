#include <iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int is_prime[100000];
int prime[50000];
void prepare()
{
    memset(is_prime,1,sizeof(is_prime));
    for(int i=2;i<1000;i++)
    {
        if(is_prime[i])
            for(int j=i;i*j<100000;j++)
                is_prime[i*j]=0;
    }
    int s=1;
    for(int i=2;i<100000;i++)
        if(is_prime[i])
            prime[s++]=i;
}
int main()
{
    int t;
    scanf("%d",&t);
    prepare();
    int n;
    int temp=0;
    while(t--)
    {
        scanf("%d",&n);
        int s=1,ans=1;;
        while(prime[s]*prime[s]<=n)
        {
            if(n%prime[s]==0)
            {
                int coun=0;
                while(n%prime[s]==0)
                {
                    coun++;
                    n=n/prime[s];
                }
                ans*=(coun*2+1);
            }
            s++;
        }
        if(n!=1)
            ans*=3;
        printf("Scenario #%d:\n%d\n\n",++temp,(ans+1)/2);
    }
    return 0;
}
