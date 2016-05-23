#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

void draw(int c)
{
    for(int L=1;L<=c;L++)
    {
        for(int i=0;i<(c-L);i++)
        {
            printf(" ");
        }
        printf("/");
        for(int i=0;i<2*L-2;i++)
        {
            printf(" ");
        }
        printf("\\");
        for(int i=0;i<(c+(c-L)*2);i++)
        {
            printf(" ");
        }
        printf("/");
        for(int i=0;i<2*L-2;i++)
        {
            printf(" ");
        }
        printf("\\");
        printf("\n");
    }
    for(int i=0;i<c-1;i++)
    {
        printf("\n");
    }
    for(int i=0;i<2*c;i++)
    {
        printf(" ");
    }
    for(int i=0;i<c;i++)
    {
        printf("_");
    }
    printf("\n");
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        draw(n);
        printf("\n");
    }
    return 0;
}
