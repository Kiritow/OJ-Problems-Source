#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm> 
using namespace std; 
int ha[30],dp[2100][2100];
int main()
{
    int n,i,j,carry,len1,len2,k,sji;
    char s1[50],s2[2010],s3[2010];
    while(~scanf("%d",&n))
    {
        scanf("%s",s1);
        for(i=0;i<n;i++)
        {
            scanf("%d",&carry);
            ha[s1[i]-'a']=carry;
        }
        scanf("%s %s",s2,s3);
        len1=strlen(s2);
        len2=strlen(s3);
        memset(dp,0,sizeof(dp));
        for(i=1;i<=len2;i++)
        {
            for(j=1;j<=len1;j++)
            {
                if(s3[i-1] == s2[j-1])
                {
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j-1]+ha[s3[i-1]-'a']);
                }
                else 
                {
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        printf("%d\n",dp[len2][len1]);
    }
    return 0;
}
