#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

double pool[300];

int main()
{
    pool[1]=0.5;
    for(int i=2;i<300;i++)
    {
        pool[i]=pool[i-1]+1.0/(i+1);
    }
    double inp;
    while(scanf("%lf",&inp)==1&&inp>0.01)
    {
        for(int i=1;i<300;i++)
        {
            if(pool[i]>inp)
            {
                printf("%d card(s)\n",i);
                break;
            }
        }
    }
    return 0;
}
