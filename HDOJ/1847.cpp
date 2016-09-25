#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n)==1)
    if(n%3) printf("Kiki\n");
    else printf("Cici\n");
    return 0;
}
