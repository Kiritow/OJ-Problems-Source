#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

double v[1010];

int main()
{
    int n;
    while(scanf("%d",&n)==1&&n)
    {
        double sum=0;
        for(int i=0;i<n;i++)
        {
            scanf("%lf",&v[i]);
            sum+=v[i];
        }
        double ave=sum/n;

        /// Why?
        int c=ave*100;
        double ave_x=c/100+c%100*0.01;

        double ave_f;
        if(ave==ave_x)
        {
            ave_f=ave_x;
        }
        else
        {
            ave_f=ave_x+0.01;
        }

        double totalA=0;
        double totalB=0;
        for(int i=0;i<n;i++)
        {
            if(v[i]<=ave)
            {
                totalA+=ave_x-v[i];
            }
            else
            {
                totalB+=v[i]-ave_f;
            }
        }

        double total=max(totalA,totalB);

        printf("$%.2f\n",total);
    }

    return 0;
}
