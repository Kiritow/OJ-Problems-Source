#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <cmath>  
#include <iostream>  
using namespace std;  
bool legal[(1<<16)+1];  
int dp[(1<<16)+1];  
char s[20];  
char str[20];  
int main()  
{  
    int t;  
    scanf("%d",&t);  
    while(t--)  
    {  
        scanf("%s",s);  
        int num=0;  
        int len=strlen(s);  
        for(int i=1;i<(1<<len);i++)  
        {  
            int cnt=0;  
            for(int j=0;j<len;j++)  
                if(i&(1<<j))  
                    str[cnt++]=s[j];  
            int l=0,r=cnt-1;  
            while(l<r && str[l]==str[r])  
            {  
                l++;  
                r--;  
            }  
            if(l==r || l-1==r)  
                legal[i]=true;  
            else  
                legal[i]=false;  
        }  
        memset(dp,0x3f,sizeof(dp));  
        dp[0]=0;  
        for(int i=1;i<(1<<len);i++)  
        {  
            for(int j=i;j>0;j=i&(j-1))  
                if(legal[j])  
                    dp[i]=min(dp[i],dp[i-j]+1);  
        }  
        printf("%d\n",dp[(1<<len)-1]);  
    }  
    return 0;  
}
