#include<iostream>
#include<string.h>
using namespace std;
const int Max = 100000 + 10;
char a[Max];
char b[Max];
struct Node
{
    char *suf;
    bool flag;
};
Node suffix[Max * 2];
int com(const void * a, const void *b)
{
    return strcmp(((Node *)a)->suf, ((Node *)b)->suf);
}
int comLen(char *a, char *b)
{
    int len = 0;
    while(*a++ == *b++) len ++;
    return len;
}
int main()
{
    int max;
    while(scanf("%s %s", a, b) != EOF)
    {
        int lenA = strlen(a);
        int lenB = strlen(b);
        for(int i=0; i<lenA; i++) suffix[i].suf = a+i, suffix[i].flag = false;
        for(int i=0; i<lenB; i++) suffix[i+lenA].suf = b+i, suffix[i+lenA].flag = true;
        qsort(suffix, lenA+lenB, sizeof(Node), com);
        max = 0;
        int temp;
        for(int i=0; i<lenA+lenB-1; i++)
            if((suffix[i].flag != suffix[i+1].flag) && (temp = comLen(suffix[i].suf, suffix[i+1].suf)) > max)
                max = temp;
        printf("%d\n", max);
    }
    return 0;
}
