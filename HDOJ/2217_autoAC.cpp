#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
using namespace std;
int place[200010] ;
int main()
{
    int n, m;
    while(scanf("%d%d", &n, &m)!=EOF)
    {
        memset(place, 0, sizeof(place) );
        bool flag1 ,flag2;
        flag1 = flag2 = 0;
        for(int i=0; i<n; i++)
        {
            scanf("%d", &place[i]);
            if(place[i] < 0 )    flag1 = 1;
            else    flag2 = 1;
        }
        sort(place, place+n);
        if(flag1 && !flag2)
        {
            int max = 0, t_m = m;
            for(int i=0; i<n; i++)
            {
                if(abs(place[i]) <= m)
                {max = n -i;    break;}
            }
            printf("%d\n", max);
        }
        else if(!flag1 && flag2)
        {
            int max = n, t_m = m;
            for(int i=0; i<n; i++)
            {
                if((place[i]) > m)
                {max = i;    break;}
            }
            printf("%d\n", max);
        }
        else if(flag1 && flag2)
        {
            int max = 0, t_m = m;
            int turn;
            for(int i=0; i<n; i++)
                if(place[i] >= 0)    {turn = i;    break;}
            for(int i=0; i<turn; i++)
            {
                int t_max = 0;
                for(int j=turn; j<n; j++)
                {
                    if(2*abs(place[i]) + place[j] <= m)
                        t_max = j-i+1;
                    if(t_max > max)        max = t_max;
                }
            }
            for(int i=0; i<turn; i++)
            {
                int t_max = 0;
                for(int j=turn; j<n; j++)
                {
                    if(abs(place[i]) + 2*place[j] <= m)
                        t_max = j-i+1;
                    if(t_max > max)        max = t_max;
                }
            }
            printf("%d\n", max);
        }
    }
}
