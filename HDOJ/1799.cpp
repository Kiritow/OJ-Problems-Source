#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int cc[2001][2001];

int main()
{
    /// 生成排列组合
    cc[1][1]=1;
    for(int i=2;i<=2000;i++)
    {
        cc[i][0]=1;
        cc[i][1]=i%1007;
        for(int j=2;j<i-1;j++)
        {
            cc[i][j]=(cc[i-1][j-1]+cc[i-1][j])%1007;
        }
        cc[i][i-1]=i%1007;
        cc[i][i]=1;
    }

    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int m,n;
        scanf("%d %d",&m,&n);
        /// 求 C(上m,下n)
        printf("%d\n",cc[n][m]);
    }
    return 0;
}
