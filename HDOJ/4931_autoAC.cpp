#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int a[20];
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;i++)
    {
        for(int i=1;i<=6;i++)
            scanf("%d",&a[i]);
        sort(a+1,a+7);
        if(a[6]+a[5]>a[4]+a[3]+a[2])
            printf("Grandpa Shawn is the Winner!\n");
        else
            printf("What a sad story!\n");
    }
    return 0;
}
