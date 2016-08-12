#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
    int n;
    int c1[125], c2[125];
    while(~scanf("%d", &n))
    {
        for(int i = 0; i <= n; ++i)
        {
            c1[i] = 1; 
            c2[i] = 0;
        }
        for(int i = 2; i <= n; ++i)
        {
            for(int j = 0; j <= n; ++j)
            {
                for(int k = 0; k <= n/i*i; k += i)
                    c2[j+k] += c1[j];
            }
            for(int j = 0; j <= n; ++j)
            {
                c1[j] = c2[j];
                c2[j] = 0;
            }
        }
        printf("%d\n", c1[n]);
    }
    return 0;
}
