#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int T,N;
    int array[8] = {1,9,18,54,90,174,258};
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        printf("%d\n",array[N]);
    }
    return 0;
}
