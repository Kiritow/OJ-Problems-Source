#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int v1,v2,d,r;
int main()
{
    int T;
    cin>>T;
    while(T--){
        scanf("%d%d%d%d",&v1,&v2,&r,&d);
        double ans = r/(double)v1*v2*asin(v1/(double)(v2));
        if(ans>d)printf("Why give up treatment\n");
        else printf("Wake up to code\n");
    }
    return 0;
}
