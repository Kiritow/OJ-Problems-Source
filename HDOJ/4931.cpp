#include <bits/stdc++.h>
using namespace std;


int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        vector<int> vec;
        int s;
        for(int i=0; i<6; i++)
        {
            scanf("%d",&s);
            vec.push_back(s);
        }
        sort(vec.begin(),vec.end());
        int sum1=vec.at(5)+vec.at(4);
        int sum2=vec.at(1)+vec.at(2)+vec.at(3);
        if(sum1>sum2)
        {
            printf("Grandpa Shawn is the Winner!\n");
        }
        else
        {
            printf("What a sad story!\n");
        }
    }
    return 0;
}
