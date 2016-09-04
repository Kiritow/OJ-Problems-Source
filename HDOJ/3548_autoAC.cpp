#include <math.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define min(a,b) a < b ? a : b
struct TT
{
    int x,y;
    bool operator <(const TT& s)const
    {
        return x < s.x;
    }
}A[1002];
bool One_Line(const TT& s1,const TT& s2,const TT& s3)
{
    return (s2.y-s1.y)*(s3.x-s2.x) == (s3.y-s2.y)*(s2.x-s1.x);
}
double dis(const TT& s1,const TT& s2)
{
    return sqrt( (double)(s1.x-s2.x)*(s1.x-s2.x) + (s1.y-s2.y)*(s1.y-s2.y) );
}
int main()
{
    int z,n,ncase=0;
    scanf("%d",&z);
    while(z--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d%d",&A[i].x,&A[i].y);
        sort(A,A+n);
        double ans = 1e7;
        for(int i=0;i<n-2;i++)
        {
            for(int j=i+1;j<n-1;j++)
            {
                if(ans <= 2*(A[j].x-A[i].x))
                    break;
                double a = dis(A[i],A[j]);
                if(ans <= 2*a)
                    continue;
                for(int k=j+1;k<n;k++)
                {
                    if(ans <= 2*(A[k].x-A[i].x))
                        break;
                    if(One_Line(A[i],A[j],A[k]))
                        continue;
                    double b = dis(A[j],A[k]);
                    double c = dis(A[k],A[i]);
                    ans = min(ans,a+b+c);
                }
            }
        }
        printf("Case %d: ",++ncase);
        if(ans == 1e7)
            puts("No Solution");
        else
            printf("%.3f\n",ans);
    }
    return 0;
}
