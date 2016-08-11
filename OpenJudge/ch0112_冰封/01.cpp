#include<stdio.h>
#include<iostream>
using namespace std;
int main(void){
    int m,n;
    char a;

    scanf("%d %c %d",&m,&a,&n);

    switch(a){
        case '+':
             printf("%d",m+n);
             break;
        case '-':
             printf("%d",m-n);
             break;
        case '*':
             printf("%d",m*n);
             break;
        case '/':
             if(n==0)break;
             printf("%d",m/n);
             break;
        case '%':
             if(n==0)break;
             printf("%d",m%n);
             break;
    }

/*    unsigned long long a = 1;
    for(int i = 0; i < 100; i++){
        a *= 10;
    }

    cout<<a;
*/
    getchar();getchar();getchar();getchar();getchar();
    return 0;
}