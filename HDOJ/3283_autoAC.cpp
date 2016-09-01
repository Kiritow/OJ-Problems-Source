#include<iostream>
#include<stdio.h>
#include<algorithm>
#include <cstring>
using namespace std;
char a[100];
int main()
{
    int t,i,len,n;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d %s",&n,a);
        len=strlen(a);
        if (next_permutation(a,a+len)) printf("%d %s\n",i,a);
        else
          printf("%d BIGGEST\n",i);
    }
    return 0;
}
