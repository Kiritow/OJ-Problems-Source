#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <algorithm>
using namespace std;
int bus[6];
int main()
{
    while(1)
    {
        for(int i=0;i<6;i++)
        {
            scanf("%d",&bus[i]);
        }
        if(!(bus[0]|bus[1]|bus[2]|bus[3]|bus[4]|bus[5])) /// Good way
            return 0;
        sort(bus,bus+6);
        int sum=bus[1]+bus[2]+bus[3]+bus[4];
        double ans=sum/4.0;
        printf("%g\n",ans);
    }
    return 0;
}
