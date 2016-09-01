#include <cstdio>
#include <cstring>
int main()
{
    double n, m;
    char s[17];
    double time;
    while(~scanf("%lf%lf",&n,&m))
    {
        double sum1 = 0;
        double sum2 = 0;
        double v1 = 0;
        double v2 = 0;
        for(int i =  0; i < 20; i++)
        {
            scanf("%s%lf",s,&time);
            if(s[0]=='A' || s[0]=='a')
            {
                sum1 += time;
                v1 += n/time;
            }
            else
            {
                sum2 += time;
                v2 += m/time;
            }
        }
        printf("Method 1\n");
        printf("African: %.2lf furlongs per hour\n",n*10.0/sum1);
        printf("European: %.2lf furlongs per hour\n",m*10.0/sum2);
        printf("Method 2\n");
        printf("African: %.2lf furlongs per hour\n",v1/10.0);
        printf("European: %.2lf furlongs per hour\n",v2/10.0);
    }
    return 0;
}
