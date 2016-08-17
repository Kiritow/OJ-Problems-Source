#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f
#define NINF 0xc0c0c0c0
struct _device
{
    int b,p;
};
_device info[105][205];
int infocnt[105];

int GlobalMin=INF;
int GlobalLinerMin;

int LinerMax[105];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        /// Input & Find Global Min
        for(int i=0;i<n;i++)
        {
            scanf("%d",&infocnt[i]);
            LinerMax[i]=NINF;
            for(int j=0;j<infocnt[i];j++)
            {
                scanf("%d %d",&info[i][j].b,&info[i][j].p);
                GlobalMin=min(GlobalMin,info[i][j].b);
                LinerMax[i]=max(LinerMax[i],info[i][j].b);
            }
        }
        /// Find GlobalLinerMin in LinerMax
        GlobalLinerMin=INF;
        for(int i=0;i<n;i++)
        {
            GlobalLinerMin=min(GlobalLinerMin,LinerMax[i]);
        }

        /// Enumerate B from GlobalMin to GlobalLinerMin
        double MaxRate=-1;
        for(int B=GlobalMin;B<=GlobalLinerMin;B++)
        {
            int PSUM=0;
            int BMIN=INF;
            /// Enumerate in each type
            for(int i=0;i<n;i++)
            {
                /// Find A Device whose Bi > B and P is the min.
                int minp=INF;
                int minb=INF;
                for(int j=0;j<infocnt[i];j++)
                {
                    if(info[i][j].b>=B)
                    {
                        if(minp>info[i][j].p)
                        {
                            minp=info[i][j].p;
                            minb=min(minb,info[i][j].b);
                        }
                    }
                }
                PSUM+=minp;
                BMIN=min(BMIN,minb);
            }
            MaxRate=max(MaxRate,(double)BMIN/PSUM);
        }
        printf("%.3f\n",MaxRate);
    }
    return 0;
}
