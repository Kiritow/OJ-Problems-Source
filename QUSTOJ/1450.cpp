#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int main()
{
    int inc;
    int five,two,one;
    int five_max,two_max,one_max;
    int ans=0;
    scanf("%d",&inc);
    five_max=inc/5;
    two_max=inc/2;
    one_max=inc;
    for(five=1;five<=five_max;five++)
    {
        for(two=1;two<=two_max;two++)
        {
            for(one=1;one<=one_max;one++)
            {
                if(5*five+2*two+one==inc) ans++;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
