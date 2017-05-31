#include<cstdio>  
#include<iostream>  
#include<math.h>  
using namespace std;  
double sum=0,sum1=0;  
int a[1100],num=0;  
int main()  
{  
    while (cin>>a[++num])  
    {  
        /*for (int i=1;i<=num-1;++i) 
        if (a[i]==a[num]) 
        { 
            --num; 
            break; 
        }*/  
    }  
    --num;  
    for (int i=1;i<=num;++i) sum1+=a[i];  
    printf("%0.0lf",sum1*pow(2,num-1));  
    return 0;  
}  
