#include <iostream>
using namespace std;
bool a[1000001]={false};
int main()
{
    int i,j,sum=0;
    for(i=1;i<=1000000;i++)
    {
        j=i;
        for(sum=j;j;j/=10)
            sum+=j%10;
        a[sum]=true;
        if(!a[i])
            printf("%d\n",i);    
    }
    return 0;
}
