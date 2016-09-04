#include<iostream>
using namespace std;
#include<cstring>
#include<stdio.h>
double a[100005];
int main()
{
    int i,j,k;
    int N;
    a[0]=0;
    a[1]=1;
    a[2]=3.0;
    for(i=3;i<100001;i++)
    {
        k=(1+i)/2;
        a[i]=a[k-1]+k-1+a[i-k]+i-k+1;
    }
    while(cin>>N)
    {
        printf("%.2lf\n",a[N]/N);
    }
    return 0;
}
