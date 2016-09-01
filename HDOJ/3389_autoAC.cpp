#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
int main()
{
    int T,tt=1;
    int n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        int ans = 0;
        for(int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            if(i%6==0 || i%6==2 || i%6==5)
                ans ^= x;
        }
        printf("Case %d: ",tt++);
        if(ans) puts("Alice");
        else puts("Bob");
    }
    return 0;
}
