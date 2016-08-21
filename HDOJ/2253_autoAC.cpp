#include <stdio.h>
#include <string.h>
#define M 30005
#define SIZE 128
#define WORDMAX 3200
#define BIT 32
char s1[M], s2[M];
int nword;
unsigned int str[SIZE][WORDMAX];
unsigned int tmp1[WORDMAX], tmp2[WORDMAX];
void pre(int len)
{
    int i, j;
    memset(str, 0, sizeof(str));
    for(i = 0; i < len; i ++)
        str[s1[i]][i / BIT] |= 1 << (i % BIT);
}
void cal(unsigned int *a, unsigned int *b, char ch)
{
    int i, bottom = 1, top;
    unsigned int x, y;
    for(i = 0; i < nword; i ++)
    {
        y = a[i];
        x = y | str[ch][i];
        top = (y >> (BIT - 1)) & 1;
        y = (y << 1) | bottom;
        if(x < y) top = 1;
        b[i] = x & ((x - y) ^ x);
        bottom = top;
    }
}
int bitcnt(unsigned int *a)
{
    int i, j, res = 0, t;
    unsigned int b[5] = {0x55555555, 0x33333333, 0x0f0f0f0f, 0x00ff00ff, 0x0000ffff}, x;
    for(i = 0; i < nword; i ++)
    {
        x = a[i];
        t = 1;
        for(j = 0; j < 5; j ++, t <<= 1)
            x = (x & b[j]) + ((x >> t) & b[j]);
        res += x;
    }
    return res;
}
void process()
{
    int i, j, len1, len2;
    unsigned int *a, *b, *t;
    len1 = strlen(s1);
    len2 = strlen(s2);
    nword = (len1 + BIT - 1) / BIT;
    pre(len1);
    memset(tmp1, 0, sizeof(tmp1));
    a = &tmp1[0];
    b = &tmp2[0];
    for(i = 0; i < len2; i ++)
    {
        cal(a, b, s2[i]);
        t = a; a = b; b = t;
    }
    printf("%d\n", bitcnt(a));
}
int main()
{
    while(scanf("%s%s", s1, s2) != EOF)
        process();
    return 0;
}
