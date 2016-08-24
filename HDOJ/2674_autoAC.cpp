#include <stdio.h>
#include <stdlib.h>
int arr[41];
void init()
{
    int i;
    arr[0] = 1;
    for(i = 1; i<41; i++)
        arr[i] = (i*arr[i-1])%2009;
}
int main(int argc, char* argv[])
{
    int t;
    init();
    while(1)
    {
        if(scanf("%d", &t)==EOF)
            break;
        if(t>=41)
        {
            printf("0\n");
            continue;
        }
        printf("%d\n", arr[t]);
    }
    return 0;
}
