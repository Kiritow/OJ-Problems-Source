#include <stdio.h>
#include <math.h>
double LogAN(double a, double N)
{
    return log(N) / log(a);
}
int main()
{
    int N = 0;
    while (scanf("%d", &N) != EOF)
    {
        double fBitNum = LogAN(2, N+3);
        int nBitNum = ceil(fBitNum);
        unsigned int nBitIP = ~((1<<nBitNum) - 1);
        printf("%u.%u.%u.%u\n",
            (nBitIP >> 24),
            ((nBitIP >> 16) & 0xFF),
            ((nBitIP >> 8) & 0xFF),
            nBitIP & 0xFF);
    }
    return 0;
}
