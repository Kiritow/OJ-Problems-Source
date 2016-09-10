#include<stdio.h>
#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<sstream>
#include<time.h>
#include<utility>
#include<malloc.h>
#include<stdexcept>
using namespace std;
int is_prime(int n )
{
    for(int i=2 ;i*i<=n;i++ )
    {
        if ( n % i ==0)
            return 0;
    }
    return 1;
}
int n,m;
int  main ()
{
    int prime[10005];
    memset(prime,0,sizeof(prime));
    for(int i=2 ;i<=10002;i++)
    {
        if ( is_prime(i) )
            prime[i] = 1;
    }
    while (cin>>n)
    {
        int num =0;
        for(int i=2 ;i<=n;i++)
            for(int j=i ;j<=(n-i)/2;j++)
            {
                if (prime[i] && prime[j]&& prime[n-i-j])
                {
                    num++;
                }
            }
        cout<<num<<endl;
    }
    return 0;
}
