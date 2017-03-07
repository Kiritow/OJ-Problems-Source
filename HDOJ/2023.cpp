#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

#include <cstdio>
#include <cstdlib>
#include <cstring>

/// This Contest and Compile does not support C++11.
//#include <thread>
//#include <mutex>
//#include <condition_variable>
//#include <functional>

using namespace std;



int main()
{
    int n,m;
    while(cin>>n)
    {
        cin>>m;
        vector< vector<double> > vec(n);
        vector<double> stuav;
        vector<double> clsav;
        for(int i=0;i<n;i++)
        {
            double sum=0;
            for(int j=0;j<m;j++)
            {
                double temp;
                cin>>temp;
                vec.at(i).push_back(temp);
                sum+=temp;
            }
            sum/=m;
            stuav.push_back(sum);
        }

        for(int i=0;i<m;i++)
        {
            double sum=0;
            for(int j=0;j<n;j++)
            {
                sum+=vec.at(j).at(i);
            }
            sum/=n;
            clsav.push_back(sum);
        }

        int cc=0;

        for(int i=0;i<n;i++)
        {
            bool yes=true;
            for(int j=0;j<m;j++)
            {
                if(vec.at(i).at(j)<clsav.at(j))
                {
                    yes=false;
                    break;
                }
            }
            if(yes)
            {
                ++cc;
            }
        }

        for(int i=0;i<n-1;i++)
        {
            printf("%.2f ",stuav.at(i));
        }
        printf("%.2f\n",stuav.at(n-1));

        for(int i=0;i<m-1;i++)
        {
            printf("%.2f ",clsav.at(i));
        }
        printf("%.2f\n",clsav.at(m-1));

        cout<<cc<<endl<<endl;
    }

    return 0;
}
