#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
const double eps = 1e-9;
const double pi = 3.1415926535897932384626;
#define INF 1e18
const int maxn = 2017;
int main()
{
    int s[maxn], t[maxn];
    int S, T, M;
    int ID, P, Q;
    int cas = 0;
    while(scanf("%d%d%d",&S,&T,&M))
    {
        if(S==0 && T==0 && M==0)
            break;
        memset(s,0,sizeof(s));
        memset(t,0,sizeof(t));
        int sum = 0;
        for(int i = 1; i <= S; i++)
        {
            scanf("%d%d%d",&ID,&P,&Q);
            sum+=P+Q;
        }
        int Sid, Tot;
        for(int i = 1; i <= T; i++)
        {
            scanf("%d%d",&Sid,&Tot);
            if(Tot >= M && t[Sid] == 0)
            {
                sum++;
                t[Sid] = 1;
            }
        }
        printf("Case %d: %d\n",++cas,sum);
    }
    return 0;
}
