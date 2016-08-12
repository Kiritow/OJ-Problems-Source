#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    unsigned int STEP,MOD;
    while(cin>>STEP>>MOD)
    {
        int count = 1;
        int seed = 0;
        do 
        {
            seed = (seed + STEP)%MOD;
            ++count;
        } while(seed != 0);
        --count;
        printf("%10d%10d    ",STEP,MOD);
        if(count == MOD)
            printf("%s\n","Good Choice");
        else
            printf("%s\n","Bad Choice");
        printf("\n");
    }
    return 0;
}
