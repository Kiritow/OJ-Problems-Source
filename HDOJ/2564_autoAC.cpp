#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int main(void)
{
    int n;
    char src2[15][15],src[150],*p;
    scanf("%d",&n);
    getchar();
    while(n--)
    {
        gets(src);
        p=strtok(src," ");
        while(p!=NULL)
        {
            printf("%c",toupper(p[0]));
            p=strtok(NULL," ");
        }
        printf("\n");
    }
}
