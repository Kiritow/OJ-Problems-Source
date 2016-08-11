#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int main()
{
    long long sum=0;
    int n;
    scanf("%d",&n);
    int tmp;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&tmp);
        sum=sum+tmp-1;
        printf("%d\n",2-!!(sum&1));
    }
    return 0;
}
