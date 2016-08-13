#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int t, c, n, m, i, time, ln[2], lt[2], ont, bt, temp, llt;
    bool bleft, tleft;
    char ch[10];
    cin >> c;
    while (c--)
    {
        ln[0] = ln[1] = lt[0] = lt[1] = 0, bleft = 1, ont = 0, bt = 0;
        cin >> n >> t >> m;
        for (i = 0; i < m; i++)
        {
                    scanf("%d%s", &time, ch);
            if (ch[0] == 'l')
                tleft = 1;
            else
                tleft = 0;
            if (bt + ont <= time)
            {
                bleft = (bleft + ont / t) % 2;
                bt = time;
                if (bleft == tleft)
                {
                    ln[tleft] = 0;
                    ont = t;
                }
                else
                {
                    ln[tleft] = 1;
                    ont = 2 * t;
                }
                ln[(tleft + 1) % 2] = 0;
                lt[0] = lt[1] = 0;
                printf("%d\n", bt + ont);
            }
            else
            {
                llt = 0;
                if (time >= bt + t)
                {
                    temp = (time - bt) / t;
                    bt += temp * t;
                    ont -= temp * t;
                    bleft = (bleft + temp) % 2;
                    if (temp % 2) 
                        lt[bleft]--;
                    lt[0] -= temp / 2;
                    lt[1] -= temp / 2;
                    lt[bleft] -= temp % 2;
                    lt[bleft]++; 
                    if (lt[0] < 0)
                    {
                        ln[0] = 0;
                        lt[0] = 0;
                    }
                    if (lt[1] < 0)
                    {
                        ln[1] = 0;
                        lt[1] = 0;
                    }
                }
                if (time > bt)
                    llt = 2 * t;
                ln[tleft]++;
                if (bleft == tleft)
                {
                    cout << bt + 2 * t * lt[tleft] + t + llt << endl;
                    if (2 * t * lt[tleft] + t + llt > ont)
                        ont = 2 * t * lt[tleft] + t + llt;
                }
                else
                {
                    cout << bt + 2 * t + 2 * t * lt[tleft] << endl;
                    if (2 * t * lt[tleft] + 2 * t > ont)
                            ont = 2 * t * lt[tleft] + 2 * t;
                }
                if (ln[tleft] == n)
                {
                    ln[tleft] = 0;
                    lt[tleft]++;
                }
            }
        }
        if (c)
            printf("\n");
    }
    return 0;
}
