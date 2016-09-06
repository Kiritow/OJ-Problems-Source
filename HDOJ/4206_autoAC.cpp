#include <iostream>
#include <cmath>
using namespace std;
int main(void)
{
    int cas;
    scanf("%d", &cas);
    while(cas--)
    {
        int n, a, b, z, y;
        scanf("%d", &n);
        int tempn = (int)sqrt((double)n);
        int ansY, ansZ;
        ansY = ansZ = INT_MAX;
        for(int i = 1; i <= tempn; i++)
        {
            if(n % i == 0)
            {
                a = n / i;
                b = i;
                if((a + b) % 2 == 0)
                {
                    z = (a + b) / 2;
                    y = z - min(a, b);
                    if(z < ansZ || y < ansY)
                    {
                        ansY = y, ansZ = z;
                    }
                }
            }
        }
        if(ansZ == INT_MAX)
        {
            printf("IMPOSSIBLE\n");
        }
        else
            printf("%d %d\n", ansY, ansZ);
    }
    return 0;
}
