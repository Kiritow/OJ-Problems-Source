#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
const int maxn=110;
char board[maxn];
int w[maxn][maxn];
int Min(int x,int y)
{ 
    return (x<y)?x:y;
}
int main()
{
    int n,ans,Max;
    while(~scanf("%d",&n))
    {
        ans=0;                  
        for(int i=1;i<=n;i++)
        {
            scanf("%s",&board);
            w[i][n-1]=(board[n-1]=='#')?0:1;
            for(int j=n-2;j>=0;j--)
            {
                if(board[j]=='#') w[i][j]=0;
                else w[i][j]=w[i][j+1]+1;
            }
            for(int j=0;j<n;j++)
            {
                Max=maxn;    
                for(int k=i;k>0;k--)
                {
                    Max=Min(Max,w[k][j]);
                    if(Max==0) break;
                    ans+=Max;
                }
            }
        }
        printf("%d\n",ans);
    }                                                                                    
    return 0;
}
