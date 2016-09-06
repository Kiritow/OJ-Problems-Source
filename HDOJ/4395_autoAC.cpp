#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int N = 2e5 + 2e4;
const int shift = 2e5;
bool reach[N];
int w[205];
inline int read(){
    double x;
    scanf("%lf",&x);
    if(x > 0)
        return x * 10000 + 1e-8;
    else
        return x * 10000 - 1e-8;
}
int main()
{
    int T,n;
    scanf("%d",&T);
    while(T--)
    {
        memset(reach,false,sizeof(reach));
        int goal = read();
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            w[i] = read();
        sort(w,w+n);
        reach[ 0 + shift ] = true;
        for(int i=0;i<n;i++)
        {
            bool f = w[i] > 0;
            if(f)
            {
                for(int j=N-1-w[i];j>=0;j--)
                    if(reach[j])
                        reach[ j + w[i] ] = true;
            }
            else
            {
                for(int j=-w[i];j<N;j++)
                    if(reach[j])
                        reach[ j + w[i] ] = true;
            }
        }
        int i = goal + shift , j = 0;
        int ans = -1;
        while(1)
        {
            if(i-j >= 0 && reach[i-j])
            {
                ans = i - j;
                break;
            }
            if(i+j < N && reach[i+j])
            {
                ans = i + j;
                break;
            }
            ++j;
        }
        printf("%.4f\n",(ans-shift)/10000.0);
    }
    return 0;
}
