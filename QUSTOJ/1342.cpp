#include <cstdio>
#define STR_A "6 its factors are 1 2 3 "
#define STR_B "28 its factors are 1 2 4 7 14 "
#define STR_C "496 its factors are 1 2 4 8 16 31 62 124 248 "
#define STR_D "8128 its factors are 1 2 4 8 16 32 64 127 254 508 1016 2032 4064 "
int main()
{
    int n;
    scanf("%d",&n);
    if(n>=6) puts(STR_A);
    if(n>=28) puts(STR_B);
    if(n>=496) puts(STR_C);
    if(n>=8128) puts(STR_D);
    return 0;
}
