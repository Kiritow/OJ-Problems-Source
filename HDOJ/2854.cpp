#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

/*
int main()
{
    /// Test Program
    int N;
    for(N=1;N<5005;N++)
    {
        bool isOK=false;
        for(int A=1;A<=N;A++)
        {
            for(int B=1;B<=N;B++)
            {
                if((A*A*B+1)%N==0)
                {
                    if((A*A+B)%N==0)
                    {
                        //printf("A=%d B=%d\n",A,B);
                        isOK=true;
                    }
                    else
                    {
                        goto OUT;
                    }
                }
            }
        }
        if(isOK)
        {
            printf("%d,",N);
        }
        OUT:continue;
    }
}
//*/
int a[]={1,2,3,4,5,6,8,10,12,15,16,20,24,30,40,48,60,80,120,240};
const int sza=sizeof(a)/sizeof(int);

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int x;
        scanf("%d",&x);
        bool isFound=false;
        for(int i=0;i<sza;i++)
        {
            if(a[i]==x)
            {
                printf("YES\n");isFound=true;break;
            }
        }
        if(!isFound)
        {
            printf("NO\n");
        }
    }
    return 0;
}
