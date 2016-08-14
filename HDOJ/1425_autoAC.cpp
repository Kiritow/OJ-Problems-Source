#include <iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#define N 1000000
using namespace std;
int a[N];
int main()
{
    int n,m,i,flag=0;
    while(scanf("%d%d",&n,&m)!=EOF){
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        flag=n-1;
        printf("%d",a[flag]);
        flag-=1;
        for(i=m;i>1;i--){
            printf(" %d",a[flag]);
            flag--;
        }
        cout<<endl;
    }
    return 0;
}
