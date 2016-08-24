#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
char s1[1000],s2[1000];
int T;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s%s",s1,s2);
        if(strcmp(s1,s2) == 0)    puts("OK");
        else    puts("ERROR");
    }
    return 0;
}
