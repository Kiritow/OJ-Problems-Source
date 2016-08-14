#include <stdio.h>
#include <string.h>
#include <vector>
#include <set>
using namespace std;
typedef struct
{
    int v,step;
} node;
long long MOD1=10007;
long long MOD2=10000013;
vector <node> use[10010];
char s[10010];
int main()
{
    long long n;
    while (scanf("%lld",&n)&&n)
    {
        long long a,b;
        scanf("%lld%lld",&a,&b);
        bool stop=0;
        for (int i=0;i<10010;i++)
            use[i].clear();
        node temp;
        temp.v=0;
        temp.step=1;
        use[0].push_back(temp);
        long long pre=0;
        int step=1;
        while (!stop)
        {
            step++;
            long long now=(((a*pre)%n*pre)%n+b)%n;
            long long x1=now%MOD1;
            long long x2=now%MOD2;
            int len=use[x1].size();
            bool find=false;
            int stepp=0;
            for (int i=0;i<len;i++)
            {
                if (use[x1][i].v==x2)
                {
                    find=true;
                    stepp=use[x1][i].step;
                }
            }
            if (find)
            {
                long long total=step-stepp;
                stop=1;
                printf("%lld\n",n-total);
                break;
            }
            else
            {
                node temp;
                temp.v=x2;
                temp.step=step;
                use[x1].push_back(temp);
            }
            pre=now;
        }
    }
    return 0;
}
