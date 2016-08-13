#include<stdio.h>
int main ()
{
    int N;
        int i;
    while(scanf("%d", &N)!=EOF)
    {
        if(N==0)
            break;
        int num[1200], T, p=0;
        for(int i=0; i<N; i++)
        {
            scanf("%d", &num[i]);
        }
        scanf("%d", &T);
        for(i=0; i<N; i++)
        {
            if(num[i]==T)
                p++;
        }
        printf("%d\n", p);
    }
    return 0;
}
