#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 13
int cmp(const void *p, const void *q)
{
    return *(int *)p > *(int *)q ? -1 : 1;
}
int main()
{
    int i, j;
    int n, grey, count, max, colors[N];
    while(scanf("%d", &n) && n)
    {
        memset(colors, 0, sizeof(colors));
        max = 0;
        for(i=0; i<n; i++)
        {
            scanf("%d", &colors[i]);
            if(colors[i] > max)
                max = colors[i];
        }
        scanf("%d", &grey);
        if(max % 50)
            count = max / 50 + 1;
        else count = max / 50;
        for(i=0; i<n; i++)
        {
            colors[i] = count * 50 - colors[i];
        }
        qsort(colors, n, sizeof(colors[0]), cmp);
        while(1)
        {
            if(colors[2] == 0 && grey > 0)
            {
                count++;
                for(i=0; i<n; i++)
                    colors[i] += 50;
            }
            grey --;
            if(grey <= 0)
                break;
            else {
            colors[0]--;
            colors[1]--;
            colors[2]--;
            qsort(colors, n, sizeof(colors[0]), cmp);
            }
        }
        printf("%d\n", count);
    }
    return 0;
}
