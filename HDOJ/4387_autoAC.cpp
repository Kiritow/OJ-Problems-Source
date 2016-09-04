#include <cstdio>
#include <algorithm>
using namespace std;
int n,k;
int main(void)
{
    int cas = 1;
    while(scanf("%d %d",&n,&k)!=EOF){
        printf("Case %d: ",cas++);
        int r = n - 2 * k;
        int ans = 1;
        bool sig = true;
        if(r&1){
            if(k == 1) sig = false;
            else if(r == 1) ans = k;
        }
        if(sig)
            printf("Alice %d\n",ans);
        else
            puts("Bob");
    }
    return 0;
}
