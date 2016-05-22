#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        vector<double> vec;
        double tmp;
        for(int i=0;i<n;i++)
        {
            scanf("%lf",&tmp);
            vec.push_back(tmp);
        }
        sort(vec.begin(),vec.end());
        double sum=0;
        for(int i=1;i<n-1;i++)
        {
            sum+=vec.at(i);
        }
        sum=sum/(n-2);
        printf("%.2f\n",sum);
    }
    return 0;
}
