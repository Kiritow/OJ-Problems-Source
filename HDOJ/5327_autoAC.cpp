#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int num[111111];
bool vis[10];
int main()
{
    int i,j = 10,t,l,r;
    num[0] = 0;
    for(i = 1; i <= 100000; ++i)
    {
        memset(vis,0,sizeof(vis));
        j = i;
        while(j)
        {
            if(!vis[j%10]) vis[j%10] = 1;
            else break;
            j /= 10;
        }
        num[i] = num[i-1];
        if(!j) num[i]++;
    }
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&l,&r);
        printf("%d\n",num[r]-num[l-1]);
    }
    return 0;
}
