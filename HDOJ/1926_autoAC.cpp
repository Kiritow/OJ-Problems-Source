#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
int tran[]={0,2,4,6,30,32,34,36,40,42,44,46,50,52,54,56,60,62,64,66};
int main()
{
    int t,dig[15],pd,inp;
    while(scanf("%d",&inp),inp!=0)
    {
        pd=0;
        while(inp)
        {
            dig[pd++]=inp%20;
            inp/=20;
        }
        bool flag=false;
        if(pd>=8)
            flag=true;
        printf("%d",tran[dig[--pd]]);
        for(t=pd-1;t>=0;t--)
        {
            if(t==6 && flag)
                printf(",000,000");
            printf(",%.3d",tran[dig[t]]);
        }
        printf("\n");
    }
    return 0;
}
