#include <cstdio>  
#include <cstring>  
#include <iostream>  
#define N 35   
#define OVER 7  
typedef unsigned long long ll;  
using namespace std;  
char B[N];  
char A[N];  
int dp[N][10][OVER+1];    
int next(int now,int p,int q)  
{  
    switch(now)  
    {  
        case 0:return p>0?1:OVER;  
        case 1:return p>0?1:p<0?2:OVER;  
        case 2:return p<0?3:q?4:OVER;  
        case 3:return p<0?3:p&&q-p?5:q?4:OVER;  
        case 4:return p>0?5:OVER;  
        case 5:return p<0?6:p>0?5:OVER;  
        case 6:return p<0?6:OVER;  
        default:return OVER;  
    }  
}  
void DP()  
{  
    memset(dp,128,sizeof(dp));  
    for(int i = 0 ; i < 10 ; i++)  
        dp[0][i][OVER-1] = i;  
    for(int i = 1 ; i < N ; i++)  
        for(int j = 0 ; j < 10 ; j++)  
            for(int l = 0 ; l < OVER ; l++)  
                for(int k = 0 ; k < 10 ; k++)  
                    dp[i][j][l] = max(dp[i][j][l] , dp[i-1][k][next(l,k-j,k)]+j);  
}  
int find(ll a,ll b)  
{  
    sprintf(B,"%I64u",b);  
    int len = strlen(B);  
    sprintf(A,"%0*I64u",len--,a);  
    int ii,sum = 0,now;   
    for(ii = 0 ; A[ii] && A[ii]==B[ii] ; ii++)  
    {  
        now = !ii ? 0 : next(now,A[ii]-A[ii-1],A[ii]-'0');  
        sum += A[ii]-'0';  
    }  
    int tsum = sum, tnow = now, ans = 0;  
    for(int i = ii; B[i] ; i++)  
    {  
        for( int j = i==ii? A[i] - '0' + 1 : 0 ; j < B[i] - '0' ; j++)  
            ans = max(ans,dp[len-i][j][!i ? 0 : next(now,j-B[i-1]+'0',j)]+sum);  
        now = !i ? 0 : next(now,B[i]-B[i-1],B[i]-'0');  
        sum += B[i]-'0';  
    }  
    if(!ii)  
    {  
        while(A[ii]=='0')  
        {  
            ii++;  
            if(!A[ii])return ans;  
            for(int i = A[ii]=='0'?1:A[ii]-'0'+1 ; i < 10 ; i++)  
                ans = max(ans,dp[len-ii][i][0]);  
        }  
        now = 0;  
    }else now = next(tnow,A[ii]-A[ii-1],A[ii]-'0');  
    sum = tsum + A[ii] - '0';  
    for(int i = ++ii;A[i]; i++)  
    {  
        for( int j = A[i] - '0' + 1 ; j < 10 ; j++)  
            ans = max(ans,dp[len-i][j][next(now,j-A[i-1]+'0',j)]+sum);  
        now = next(now,A[i]-A[i-1],A[i]-'0');  
        sum += A[i] - '0';  
    }  
    return ans;  
}  
int main()  
{  
    int t,cas = 1;  
    ll a,b;  
    scanf("%d",&t);  
    DP();  
    while(t--)  
    {  
        scanf("%I64u %I64u",&a,&b);          
        if(!a)a++;  
        if(!(b+1))b--;  
        printf("Case %d: %d\n",cas++,find(a-1,b+1));  
    }  
    return 0;  
}
