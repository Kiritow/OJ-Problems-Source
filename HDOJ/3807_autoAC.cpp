#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#define INF 0x7f7f7f7f
using namespace std;
int num[1010];
vector<int> ans;
int main()
{
    int t, n, x, A, B;
    scanf("%d", &t);
    while(t--)
    {
        memset(num, 0, sizeof(num));
        ans.clear();
        scanf("%d", &n);
        for(int i = 0; i < n; ++ i)
        {
            scanf("%d",&x);
            num[x]++;
        }
        scanf("%d%d", &A, &B);
        for(int i = 1; i <= n; ++ i)
        {
            for(int j = 0; j <= A; ++ j)
            {
                int lie = n-num[i];
                if(i-j >= 0 && lie-j >= 0 && (n-(i-j+lie) >= 0 && n-(i-j+lie) <= B))
                {
                    ans.push_back(i);
                    break;
                }
            }
        }
        if((int)ans.size() == 0)
            printf("impossible\n");
        else
        {
            int len = ans.size();
            for(int i = 0; i < len-1; ++ i)
                printf("%d ", ans[i]);
            printf("%d\n", ans[len-1]);
        }
    }
    return 0;
}
