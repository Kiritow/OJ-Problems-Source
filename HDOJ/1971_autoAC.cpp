#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm> 
using namespace std;
#define N 71
#define M 31 
#define Max 999999
int dp[N*M][N*M];  
struct Book
{
    int h, w;
}; 
int cmp(Book x, Book y)
{
    if(x.h!=y.h)
        return x.h>y.h;
    return x.w<y.w;
} 
int main()
{
    int T, i, j, n, sum, k;
    scanf("%d", &T);
    while(T--)
    {
        Book book[N]; 
        scanf("%d", &n);
        sum=0; 
        for(i=1; i<=n; i++)
        {
            scanf("%d%d", &book[i].h, &book[i].w);
            sum+=book[i].w;
        }
        sort(book+1, book+n+1, cmp);
        for(i=0; i<=sum; i++)
            for(j=0; j<=sum; j++)
                dp[i][j]=Max;
        dp[0][0]=0;
        int noww=0; 
        for(i=2; i<=n; i++)
        {
            for(j=noww; j>=0; j--)
            {
                for(k=noww; k>=0; k--)
                {
                    if(dp[j][k]==Max)    
                        continue; 
                    if(noww-j-k<0)
                         continue;
                    int a=0; 
                    if(j==0)
                        a=book[i].h;
                    dp[j+book[i].w][k]=min(dp[j+book[i].w][k], dp[j][k]+a);
                    a=0; 
                    if(k==0)
                        a=book[i].h;
                    dp[j][k+book[i].w]=min(dp[j][k+book[i].w], dp[j][k]+a);
                } 
            }
            noww+=book[i].w;
        }
        int minnum=Max;
        for(j=1; j<=noww; j++)
        {
            for(k=1; k<=noww; k++)
            {
                if(dp[j][k]==Max)
                    continue;
                if(sum-j-k<=0)
                    continue;
                int maxw=max(j, k);
                maxw=max(maxw, sum-j-k); 
                minnum=min(minnum, maxw*(dp[j][k]+book[1].h));
            }
        } 
        printf("%d\n", minnum);
    }
}
