#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
    int n,p,m,t;
    while(cin >> n >> p >> m >> t)
    {
        long long s[110][110];
        memset(s,0,sizeof(s));
        s[0][p] = 1;
        for(int i = 1;i <= m;i++)
        {
            for(int j = 1;j <= n;j++)
            {
                s[i][j] = s[i-1][j-1] + s[i-1][j+1];
            }
        }
        cout << s[m][t] << endl;
    }
    return 0;
}
