#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int l,r;
    while(scanf("%d %d",&l,&r)==2)
    {
        /// Naive! What assume l < r?
        int ll=min(l,r);
        int rr=max(l,r);

        /// F^K. Why the problem does not show the REAL range?
        int maxcnt=-1;

        for(int i=ll;i<=rr;i++)
        {
            long long c=i;
            int cnt=1;
            while(c!=1)
            {
                if(c&1) c=c*3+1;
                else c=c/2;

                ++cnt;
            }

            maxcnt=max(maxcnt,cnt);
        }

        printf("%d %d %d\n",l,r,maxcnt);
    }
    return 0;
}
