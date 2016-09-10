#include<iostream>
#include<cstdio>
using namespace std;
const int T = 30;
int main()
{
    int c;
    while (scanf("%d",&c)!=EOF)
    {
        int n , m , i ;
        n = T * 2 + 1;
        m = T * 3;
        printf("%d %d\n",n,m);
        for (int i = 0 ; i <T ; i ++)
        printf("%d %d %d\n",i * 2 + 1 , i * 2 + 2 , 0);
        for (int i = 0 ; i <T ; i ++)
        printf("%d %d %d\n",i * 2 + 2 , i * 2 + 3 , - ( 1 << T - i )); 
        for (int i = 0 ; i <T ; i ++)        
        printf("%d %d %d\n",i * 2  + 1 ,  i * 2 + 3 , -( 1 << T - i - 1 ));
    }
}
