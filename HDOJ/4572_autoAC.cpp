#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int main()
{
    int N,M;
    while(scanf("%d%d",&M,&N)!=EOF)
    {
        printf("%d\n",(M+(M-(N-1)/2)+1)*(N-1)/4+(M+(M-(N+1)/2)+1)*(N+1)/4);
    }
    return 0;
}
