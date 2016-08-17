#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std ;
int cost[200][200],price[200][200],indexx[200][200] ;
void print(int K,int L,char key[],char let[])
{
    if( K == 0 ) return ;
    print(K-1, L-indexx[K][L],key,let) ;
    printf("%c: ",key[K-1]) ;
    for(int i = L-indexx[K][L] ; i < L ; i++)
    putchar(let[i]) ;
    puts("") ;
}
int main()
{
    int T ;
    scanf("%d",&T) ;
    int K,L ,a[200] ,cnt = 0;
    while(T--)
    {
        char key[200],let[200] ;
        cnt++ ;
        scanf("%d %d %s %s",&K,&L,key,let) ;
        for(int i = 0 ; i < L ; i++)
        scanf("%d",&a[i]) ;
        memset(price,0x40,sizeof(price)) ;
        price[0][0] = 0 ;
        for(int i = 1 ; i <= L ; i++)
        for(int j = i ; j <= L ; j++)
        cost[i][j] = cost[i][j-1]+(j-i+1)*a[j-1] ;
        for(int i = 1 ; i <= K ; i++)
        for(int j = i ; j <= L ; j++)
        for(int k = 1 ; k <= j-i+1 ; k++)
        {
            if(price[i-1][j-k] + cost[j-k+1][j] <= price[i][j])
             price[i][j] = price[i-1][j-k] + cost[j-k+1][j],indexx[i][j] = k ;
        }
        printf("Keypad #%d:\n",cnt) ;
        print(K,L,key,let) ;
        printf("\n") ;
    }
    return 0 ;
}
