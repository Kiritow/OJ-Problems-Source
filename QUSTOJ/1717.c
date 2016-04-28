#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 256
int bucket[MAXN];

int main()
{
    int t;
    scanf("%d",&t);
    int tmp;
    for(int i=0;i<t;i++)
    {
        scanf("%d",&tmp);
        if(bucket[tmp]==0)
        {
            ++bucket[tmp];
            printf("%d ",tmp);
        }
    }
    printf("\n");
    return 0;
}
