#include <cstdio>
#include <cstring>
using namespace std;
char str1[105],str2[105];
int dp[105][105];
int record[205][205];
void output(int l1,int l2)
{
    if(l1==0&&l2==0)return;
    if(record[l1][l2]==2)
     {
         output(l1-1,l2-1);
            printf("%c",str1[l1-1]);
    }
    if(record[l1][l2]==1)
       {
            output(l1,l2-1);
            printf("%c",str2[l2-1]);
    }
    if(record[l1][l2]==3)
       {
           output(l1-1,l2);
           printf("%c",str1[l1-1]);
    }
}
int main()
{
    while(~scanf("%s%s",&str1,&str2))
    {
        memset(dp,0,sizeof(dp));
        int len1=strlen(str1);
        int len2=strlen(str2);
        int count=0;
        for(int i=1;i<=len1;i++)
         {
              dp[i][0]=i;
              record[i][0]=3;
        }
        for(int i=1;i<=len2;i++)
        {
           dp[0][i]=i;
           record[0][i]=1;
        }
        for(int i=1;i<=len1;i++)
        {
            for(int j=1;j<=len2;j++)
            {
                if(str1[i-1]==str2[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                    record[i][j]=2;
                }
                else 
                {
                    if(dp[i-1][j]<dp[i][j-1])
                    {
                        dp[i][j]=dp[i-1][j]+1;
                        record[i][j]=3;
                    }
                    else
                    {
                        dp[i][j]=dp[i][j-1]+1;
                      record[i][j]=1;
                    }
                }
            }
        }
        output(len1,len2);
        printf("\n");
    }
}
