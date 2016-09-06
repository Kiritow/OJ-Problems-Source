#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int getOneNumber(int x)
{
    int count = 0;
    for(int i=0;(1<<i)<=x;++i)
    {
        if(x & (1 << i))
        {
            ++ count;
        }
    }
    return count;
}
int main()
{
    int caseNumber;
    int n, m, a;
    scanf("%d", &caseNumber);
    for(int cas=1;cas<=caseNumber;++cas)
    {
        scanf("%d", &n);
        int a = 0;
        while(n--)
        {
            scanf("%d", &m);
            if(!(getOneNumber(m) & 1))
            {
                ++ a;
            }
        }
        printf("Case %d: ", cas);
        if(a & 1)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}
