#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

struct STX
{
    double height,weight;
};

bool comp(const STX& a,const STX& b)
{
    return a.height<b.height;
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int tt=0;tt<t;tt++)
    {
        int n;
        scanf("%d",&n);
        vector<STX> vec;
        for(int i=0;i<n;i++)
        {
            STX s;
            scanf("%lf %lf",&s.height,&s.weight);
            vec.push_back(s);
        }
        sort(vec.begin(),vec.end(),comp);
        double red=0;
        double blue=0;
        for(int i=0;i<n;i++)
        {
            //printf("## vec.at(i).height= %f\n",vec.at(i).height);
            if((i+1)%2)
            {
                //printf("## red\n");
                red+=vec.at(i).weight;
            }
            else
            {
                //printf("## blue\n");
                blue+=vec.at(i).weight;
            }
        }
        if(blue>red)
        {
            printf("blue\n");
        }
        else if(blue<red)
        {
            printf("red\n");
        }
        else
        {
            printf("fair\n");
        }
    }
    return 0;
}
 
