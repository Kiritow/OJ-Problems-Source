#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        int h=0,m=0,s=0;
        for (int i = 0; i < 12 * 60 * 60; i = i + 10)
        {
            int time1 = (i * 1200) % 4320000;
            int time2 = (i * 100) % 4320000;
            int time;
            if (time1 > time2)
                time = time1 - time2;
            else
                time = time2 - time1;
            if (time > 2160000)
                time = 4320000 - time;
            if (time == n)
            {
                int h = i / (60 * 60);
                int m = (i - h * (60 * 60)) / 60;
                int s = (i % 60) - (i % 60) % 10;
                printf("%02d:%02d:%02d\n", h, m, s);
            }
        }
    }
    return 0;
}
