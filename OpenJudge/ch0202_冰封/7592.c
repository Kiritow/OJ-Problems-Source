#include<stdio.h>
#include<stdlib.h>

int fafafa(long a,long b){
    if(a%b == 0) return b;
    return fafafa(b, a%b);
}

int main(void){
    long i,j;
    //i = 100; j = 10;
    scanf("%ld%ld",&i,&j);
    if(i<j){long t = i; i = j;j = t;}
    printf("%ld",fafafa(j,i));
    //system("PAUSE");
    return 0;
}
