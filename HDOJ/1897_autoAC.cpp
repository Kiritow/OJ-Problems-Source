#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <map>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <stack>
#include <functional>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <numeric>
#include <cassert>
#include <bitset>
#include <stack>
#include <ctime>
#include <list>
#define INF 0x7fffffff
#define max3(a,b,c) (max(a,b)>c?max(a,b):c)
#define min3(a,b,c) (min(a,b)<c?min(a,b):c)
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
int main()
{
    int t;
    scanf("%d", &t);
    multiset<int> Q;
    map<int, int> P;
    int n, q, y;
    int cnt = 0;
    while(t--)
    {
        cnt++;
        Q.clear();
        P.clear();
        scanf("%d%d%d", &n, &q, &y);
        int lp;
        for(int i = 0; i < n; ++i)
        {
            scanf("%d", &lp);
            P[lp]++;
            Q.insert(lp);
        }
        multiset<int>::iterator kp;
        printf("Case %d:\n", cnt);
        for(int i = 0; i < q; ++i)
        {
            int tp;
            scanf("%d", &tp);
            int tt = tp + y;
            multiset<int>::iterator it = Q.lower_bound(tp);
            if(it == Q.end())
                printf("-1\n");
            else
            {
                int tmp = (*it);
                if(tmp == tp)
                {
                    printf("%d\n", tp);
                    Q.erase(*it);
                    P[(*it)] --;
                    for(int kk = 0; kk < P[(*it)]; ++kk)
                    Q.insert(tp);
                }
                else
                {
                    int qq = (*it);
                    if(qq  <= (tt))
                    {
                        printf("%d\n", qq);
                        P[qq]--;
                        Q.erase(qq);
                        for(int kk = 0; kk < P[qq]; ++kk)
                        Q.insert(qq);
                    }
                    else
                        printf("-1\n");
                }
            }
        }
    }
    return 0;
}
