#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define MAXLEN 10
#define MAXNUM 10
int dp[MAXLEN][MAXNUM];
int num[MAXLEN];
char _tmpbuff[MAXLEN];

inline int Deal(int N)
{
    sprintf(_tmpbuff,"%d",N);
    int _len=strlen(_tmpbuff);
    /// num: 低位存放数字低位(逆序)
    for(int i=0; i<_len; i++)
    {
        num[i]=_tmpbuff[_len-i-1]-'0';
    }
    num[_len]=0;
    int ans=0;
    for(int i=_len-1; i>=0; i--)
    {
        for(int j=0; j<num[i]; j++)
        {
            if(num[i+1]==6&&j==2) continue;
            ans+=dp[i+1][j];///重要 i+1
        }
        /// ?
        if (num[i] == 4 || (num[i + 1] == 6 && num[i] == 2)) break;
    }
    return ans;
}

int main()
{
    dp[0][0] = 1;
    for (int i = 1; i < MAXLEN; ++i)
        for (int j = 0; j < MAXNUM; ++j)
            for (int k = 0; k < MAXNUM; ++k)
                if (j != 4 && !(j == 6 && k == 2))
                    dp[i][j] += dp[i - 1][k];
    int n,m;
    while(scanf("%d %d",&n,&m)==2&&!(n==0&&m==0))
    {
        /// Calculate M

        int ans_m=Deal(m+1);
        int ans_n=Deal(n);

        printf("%d\n",ans_m-ans_n);
    }
    return 0;
}
