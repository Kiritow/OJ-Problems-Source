#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

char buffA[80010];
char buffB[80010];

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int N,X,Y;
        scanf("%d %d %d%*c",&N,&X,&Y);
        gets(buffA);
        gets(buffB);

        int same=0;
        for(int j=0;j<N;j++)
        {
            if(buffA[j]==buffB[j]) ++same;
        }

        bool ly=false;

        if(X>=same&&Y>=same)
        {
            if(Y>N-X+same) ly=true;
        }
        else if(X>=same)
        {
            if(Y<X-N+same) ly=true;
        }
        else if(Y>=same)
        {
            if(Y>N-same+X) ly=true;
        }

        if(ly)
        {
            printf("Lying\n");
        }
        else
        {
            printf("Not lying\n");
        }
    }
    return 0;
}