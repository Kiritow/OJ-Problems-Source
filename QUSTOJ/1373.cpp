#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
char buff[1024];
int main()
{
    int n;
    scanf("%d%*c",&n);
    gets(buff);
    scanf("%d",&n);
    printf("%s\n",buff+n-1);
    return 0;
}
