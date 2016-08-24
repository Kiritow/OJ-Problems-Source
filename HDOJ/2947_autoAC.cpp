#include <iostream>
 using namespace std;
 __int64 p[21][21];
 __int64 gcd(__int64 a, __int64 b)
{
     return b ? gcd(b, a % b) : a;
 }
 void init()
 {
     int i, j;
     for (i = 0; i <= 20; ++i)
     {
         p[i][0] = 1;
         p[i][i] = 0;
     }
     for (i = 2; i <= 20; ++i)
         for (j = 1; j < i; ++j)
             p[i][j] = p[i - 1][j] + p[i - 1][j - 1] * (i - 1);
 }
 void solve(int s, int n)
 {
     __int64 sum = 0, total = 0 , g;
     int i;
     for (i = 0; i < s; ++i)
         sum += p[n][i];
     total = sum;
     for ( ; i < n; ++i)
        total += p[n][i];
     g = gcd(sum, total);
     sum /= g;
     total /= g;
     if (total == 1 && sum == 1)
         printf("1\n");
     else if (sum == 0)
         printf("0\n");
     else printf("%I64d/%I64d\n", sum, total);
}
int main()
{
     init();
     int tcase, w, h, n, s;
     scanf("%d", &tcase);
     while (tcase--)
     {
         scanf("%d%d%d", &w, &h, &s);
         solve(s, w * h);
     }
     return 0;
}
