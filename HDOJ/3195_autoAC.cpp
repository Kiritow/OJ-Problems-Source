#include<stdio.h>   
#include<string.h>   
#include<stdlib.h>   
#include<algorithm>   
#include<math.h>  
using namespace std;   
long long num[27];
void cal()
{
    int front=1,tail;
    long long wei=1;
    num[0]=0;
    while(1)
    {
        int k=front;
        tail=0;
        for(int i=1;i<10;i++)
        {
            for(int j=0;j<k;j++)
            {
                long long b=num[j]+i*wei,c=0;
                for(long long m=wei;m>0;m/=10)
                {
                    long long d=(b/m-(b/(10*m))*10)*m,e=b%(10*wei/m);
                    c+=(d*e);
                }
                c%=(wei*10);
                if(c==b) 
                {
                    num[front++]=b;
                    if(front>25) return;
                }            
            }
        }
        wei*=10;
    }
}
int main()
{
    cal();
    int n;
    while(scanf("%d",&n)==1)
    {
        printf("%I64d\n",num[n-1]);
    }
    return 0;
}
