#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int N,M,x,y;
    while(scanf("%d%d%d%d",&N,&M,&x,&y)!=EOF)
    {
        if(2*x==N&&2*y==M)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
