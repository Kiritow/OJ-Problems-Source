#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
int main()
{
    char s[20];
    float d;
    long x,n;
    scanf("%d",&n);
    while(n--){
        scanf("%f",&d);
        memcpy(&x,&d,4);
        printf("%X\n",x);
    }
    return 0;
}
