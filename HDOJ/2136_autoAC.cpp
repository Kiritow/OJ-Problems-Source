#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
const int MAX=1000000;
int x[MAX];
using namespace std;
int main()
{
    int n,m,i,j,sum;
    memset(x,-1,sizeof(x));
    x[1]=0;
    sum=0;
    for(i=2;i<MAX;i++)
    {
        if(x[i]==-1)
        {
            sum+=1;
            for(j=i;j<MAX;j+=i)
            x[j]=sum;
        }
    }
    while(scanf("%d",&n)!=EOF)
    printf("%d\n",x[n]);
    return 0;
}
