#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int MAX = 100 + 10;
char Plant[MAX];
int P, M;
int Flag;
int E;
int MozNum;
void init(char plant[])
{
    MozNum = 0;
    E = strlen(plant) - 1;
    P = M = 0;
    for(int i = 0; i <= E; ++i)
    {
        if(plant[i] == 'P')
            ++P;
        else
            ++M;
    }
}
int run(int apNum, int ppNum, int mozNum)
{
    int flag = Flag;
    int pLife = 10, mozLife = 50;
    while(ppNum > 0 && mozNum > 0)
    {
        if(flag > 0)
        {
            --flag;
            mozLife -= apNum;
        }
        else
        {
            pLife -= mozNum;
            mozLife -= apNum;
        }
        if(pLife <= 0)
        {
            pLife = 10;
            apNum--;
            ppNum--;
            flag = 1;
        }
        if(mozLife <= 0)
        {
            mozLife = 50;
            mozNum--;
        }
    }
    if(ppNum <= 0 && mozNum > 0)
        return 1;
    if(ppNum <= 0 && mozNum <= 0)
        return 0;
    if(ppNum > 0)
        return -1;
}
int main()
{
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t)
    {
        scanf("%s", Plant);
        init(Plant);
        if(Plant[E] == 'M')
        {
            E--;
            MozNum++;
            Flag = 2;
        }
        else
            Flag = 1;
        while(E >= 0)
        {
            if(Plant[E] == 'M')
            {
                if(Flag > 1)
                {
                    --Flag;
                    if(P >= 50)
                        ++MozNum;
                    continue;
                }
                else
                    MozNum++;
                M--;
                E--;
                Flag = 2;
            }
            else
            {
                int pNum = 0;
                for(int i = E; i >= 0; --i)
                {
                    if(Plant[i] == 'M')
                        break;
                    else
                        pNum++;
                }
                int left = 1, right = 2 * MAX, mid;
                while(left < right)
                {
                    mid = (left + right) >> 1;
                    if(run(P, pNum, mid) > 0)
                        right = mid;
                    else
                        left = mid + 1;
                }
                MozNum += left;
                P -= pNum;
                E -= pNum + 1;
                Flag = 2;
            }
        }
        if(Plant[0] == 'M')
            ++MozNum;
        printf("Case %d: %d\n", t, MozNum);
    }
    return 0;
}
