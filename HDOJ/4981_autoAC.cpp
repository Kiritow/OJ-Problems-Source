#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int N,array[1050];
    while(~scanf("%d",&N))
    {
        int sum = 0;
        for(int i = 0; i < N; i++)
        {
            scanf("%d",&array[i]);
            sum += array[i];
        }
        sort(array,array+N);
        double aver = (double)sum/N;
        if(aver >= (double)array[(N-1)/2])
        printf("NO\n");
        else
        printf("YES\n");
    }
    return 0;
}
