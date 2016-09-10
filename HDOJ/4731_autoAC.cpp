#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
char str[10000];
int main()
{
    int T;
    int m,n;
    int iCase = 0;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&m,&n);
        iCase++;
        printf("Case #%d: ",iCase);
        if(m == 1)
        {
            for(int i = 0;i < n;i++)printf("a");
            printf("\n");
            continue;
        }
        if(m >= 3)
        {
            int index = 0;
            for(int i = 0;i < n;i++)
            {
                printf("%c",index + 'a');
                index = (index + 1)%3;
            }
            printf("\n");
            continue;
        }
        if(n == 1)printf("a");
        else if(n == 2)printf("ab");
        else if(n == 3)printf("aab");
        else if(n == 4)printf("aabb");
        else if(n == 5)printf("aaaba");
        else if(n == 6)printf("aaabab");
        else if(n == 7)printf("aaababb");
        else if(n == 8)printf("aaababbb");
        else if(n == 9)printf("aaaababba");
        else
        {
            printf("aaaa");
            n -= 4;
            while(n >= 6)
            {
                printf("babbaa");
                n -= 6;
            }
            if(n == 1)printf("a");
            else if(n == 2)printf("aa");
            else if(n == 3)printf("bab");
            else if(n == 4)printf("babb");
            else if(n == 5)printf("babba");
        }
        printf("\n");
    }
    return 0;
}
