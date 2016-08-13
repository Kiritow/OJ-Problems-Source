#include<stdio.h>
long int A(long int,long int);
int main()
{
    long int n,m;
    while(scanf("%ld%ld",&m,&n)!=EOF)
        printf("%ld\n",A(m,n));
        return 0;
}
long int A(long int m,long int n)
{
    if(n==0) return A(m-1,1);
    else if(m==0)return n+2;
    else if(m==1) return n+2;
    else if(m==2) return 2*n+3;
    else  if(m==3)return A(m,n-1)*2+3;
}
