#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

/// ItemID[0]=7 stands for "When C=7, This object id is 0"
int ItemID[6];
/// Amount of Item with ID.
int ItemAmount[6];
/// Price of Item with ID.
int ItemPrice[6];

#define MAX_INT 1e9

/// Bucket
int b;
/// Special Combinations.
int s;

///Array of DP
int dp[6][6][6][6][6];

int special_combine[1000][6];
int special_price[1000];

void Solve()
{
    /// May be dangerous.
    memset(dp,-1,sizeof(dp));

    dp[0][0][0][0][0]=0;
    /// i,j,k,x,y respects the amount of selected Item, from 0 to 5
    for(int i=0;i<=ItemAmount[0];i++)
    {
        for(int j=0;j<=ItemAmount[1];j++)
        {
            for(int k=0;k<=ItemAmount[2];k++)
            {
                for(int x=0;x<=ItemAmount[3];x++)
                {
                    for(int y=0;y<=ItemAmount[4];y++)
                    {
                        int FinalPrice = MAX_INT;
                        int TempPrice = MAX_INT;
                        /// Try Each Special Combination
                        for(int si=0;si<s;si++)
                        {
                            if(i>=special_combine[si][0]&&j>=special_combine[si][1]&&k>=special_combine[si][2]&&x>=special_combine[si][3]&&y>=special_combine[si][4])
                            {
                                TempPrice = dp[i-special_combine[si][0]][j-special_combine[si][1]][k-special_combine[si][2]][x-special_combine[si][3]][y-special_combine[si][4]] +special_price[si];
                                FinalPrice = min(FinalPrice,TempPrice);
                            }
                        }
                        if(FinalPrice!=MAX_INT)
                        {
                            dp[i][j][k][x][y]=FinalPrice;
                        }
                        else
                        {
                            /// Just Calculate the original price
                            dp[i][j][k][x][y]=i*ItemPrice[0]+j*ItemPrice[1]+k*ItemPrice[2]+x*ItemPrice[3]+y*ItemPrice[4];
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    scanf("%d",&b);
    for(int i=0;i<b;i++)
    {
        scanf("%d %d %d",&ItemID[i],&ItemAmount[i],&ItemPrice[i]);
    }
    scanf("%d",&s);
    for(int i=0;i<s;i++)
    {
        int _tmp;
        scanf("%d",&_tmp);
        for(int j=0;j<_tmp;j++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            /// Get Original ID to Hashed ID.
            for(int k=0;k<6;k++)
            {
                if(ItemID[k]==a)
                {
                    special_combine[i][k]=b;
                    break;
                }
            }
        }
        scanf("%d",&special_price[i]);
    }
    Solve();
    printf("%d\n",dp[ItemAmount[0]][ItemAmount[1]][ItemAmount[2]][ItemAmount[3]][ItemAmount[4]]);
    return 0;
}
