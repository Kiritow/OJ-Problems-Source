#include <iostream>
#include <cmath>
using namespace std;
const int MAX = 16000;
int mod = 10000;
int fiblast[MAX] = {0, 1, 1}, fib[MAX] = {0, 1, 1};
double N1 = (1.0 + sqrt(5.0)) / 2.0;
void pre_init()
{
    for(int i = 3; i < MAX; i++)
    {
        fiblast[i] = (fiblast[i - 1] + fiblast[i - 2]) % mod;
        if(fiblast[i] == fiblast[1] && fiblast[i - 1] == fiblast[0])
            break;
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    return ;
}
int main(void)
{
    pre_init();
    int n;
    while(scanf("%d", &n) == 1)
    {
        if(n < 40)
        {
            printf("%d\n", fib[n]);
            continue;
        }
        double k = log10(1.0/sqrt(5.0)) + (double)n * log10(N1);
        double tmp = k;
        tmp = k - (int)tmp;
        printf("%d...%0.4d\n", (int)(1000.0 * pow(10.0, tmp)), fiblast[n % 15000]);
    }
    return 0;
}
