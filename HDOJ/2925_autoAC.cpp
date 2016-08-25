#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include <memory.h>
#include <math.h>
#include <string.h>
using namespace std;
int main()
{
    int n,d,w;
    while(cin>>n>>d)
    {
        if(n==0&&d==0) break;
        int ans=0;
        for(int i=2;i<=n;i++)
        ans=(ans+d)%i;
        cout<<n<<" "<<d<<" "<<ans+1<<endl;
    }
    return 0;
}
