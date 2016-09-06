#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
const double PI = acos(-1.0);
const double e = 2.718281828459;
const double eps = 1e-8;
char s[10];
int main()
{
    int n;
    int flag = 0;
    while(cin>>n && n)
    {
        if(!flag)
            flag = 1;
        else
            printf("\n");
        int sum1, sum2, m;
        sum1 = sum2 = 0;
        while(n--)
        {
            cin>>s>>m;
            if(s[0] == 'D')
            {  
                printf("DROP 2 %d\n", m);
                sum2 += m;
            }
            else
            {
                if(sum1 >= m)
                {   
                    printf("TAKE 1 %d\n", m);
                    sum1 -= m;
                }
                else
                {   
                    if(sum1 > 0)
                    {   
                        printf("TAKE 1 %d\n", sum1);
                        m -= sum1;
                        sum1 = 0;
                    }   
                    printf("MOVE 2->1 %d\n", sum2);
                    sum1 = sum2;
                    sum2 = 0;  
                    if(m > 0)
                    {
                        printf("TAKE 1 %d\n", m);
                        sum1 -= m;
                    }
                }
            }
        }
    }
    return 0;
}
