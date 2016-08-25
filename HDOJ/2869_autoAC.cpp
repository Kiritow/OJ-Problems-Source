#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int main()
{
        int prime[100];
        int k = 0;
        for(int i=2;i<=500;i++)
        {
        bool flag = false;
        for(int j=2;j<=(int)sqrt((double) i);j++)
        if( i % j == 0) { flag = true; break;}
        if(!flag) prime[k++] = i;
        }
        int a,b;
        while(scanf("%d%d",&a,&b)!=EOF)
        {
        int w=0,h=0;
        int c = a,d = b;
        for(int i=0;i<=94;i++) 
        {
            while(a % prime[i] == 0 && prime[i] != c)
            {
                w++;
                a /= prime[i];
            }
            while(b % prime[i] == 0 && prime[i] != d)
            {
                h++;
                b /= prime[i];
            }
        }
        if( w> h) printf("Win\n");
        else      printf("Lose\n");
    }
    return 0;
}
