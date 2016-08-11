#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
char stra[128];
char strb[128];
#define MAXL 105
int dp[MAXL][MAXL];
int label(char c)
{
    switch(c)
    {
        case 'A': return 0;
        case 'C': return 1;
        case 'G': return 2;
        case 'T': return 3;
        case '-': return 4;
        default: return 4;/// Here if c=='\0' , we should regard it as a '-';
    }
}
int trans[5][5]=
{
    {
        5,-1,-2,-1,-3
    },
    {
        -1,5,-3,-2,-4
    },
    {
        -2,-3,5,-2,-2
    },
    {
        -1,-2,-2,5,-1
    },
    {
        -3,-4,-2,-1,0
    }
};
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b;
        scanf("%d %s %d %s",&a,stra+1,&b,strb+1);
        memset(dp,0,sizeof(int)*MAXL*MAXL);
        /// Init this dp array (Why?)
        int n=max(a,b);
        for(int ci=1;ci<=n;ci++)
        {
            dp[0][ci]=dp[0][ci-1]+trans[label('-')][label(strb[ci])];
            dp[ci][0]=dp[ci-1][0]+trans[label(stra[ci])][label('-')];
        }

        for(int i=1;i<=a;i++)
        {
            for(int j=1;j<=b;j++)
            {
                dp[i][j]=max(max(dp[i-1][j]+trans[label(stra[i])][label('-')],dp[i][j-1]+trans[label('-')][label(strb[j])]),dp[i-1][j-1]+trans[label(stra[i])][label(strb[j])]);
            }
        }
        printf("%d\n",dp[a][b]);
    }
    return 0;
}
