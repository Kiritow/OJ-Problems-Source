#include<iostream>
#include<cstdio>
using namespace std;
const int M = 1010;
int Map[M][M];
int C[M];
int R[M];
int main()
{
    int n;
    int k = 0;
    while(scanf("%d",&n),n)
    {
        memset(C,0,sizeof(C));
        memset(R,0,sizeof(R));
        int ans = 0;
        int res = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                cin>>Map[i][j];
                ans += Map[i][j]; 
                C[i] += Map[i][j]; 
            }
        }
        for(int i = 1; i <= n; i++)
        {
            for(int  j = 1; j <= n; j++)
            {
                R[i] += Map[j][i];
            }
            int cnt = C[i] - R[i];
            if(cnt > 0)
            {
                res += cnt;
            }
        }
        printf("%d. %d %d\n",++k,ans,res);
    }
    return 0;
}
