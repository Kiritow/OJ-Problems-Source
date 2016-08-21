#include<iostream>
#include<vector>
#include<algorithm>
struct point
{
    int x;
    int y;
};
using namespace std;
int main()
{
    int m,n;
    while(cin>>m>>n)
    {
        vector<point> v1;
        vector<int> v2;
        while(m--)
        {
            point temp;
            cin>>temp.x>>temp.y;
            v1.push_back(temp);
        }
        int **p=new int*[n];
        for(int i=0;i!=n;++i)
            p[i]=new int[4];
        for(int i=0;i!=n;++i)
            for(int j=0;j!=4;++j)
            cin>>p[i][j];
        for(auto b=v1.cbegin();b!=v1.cend();++b)
        {
            int temp,i;
            for(i=0;i!=n;++i)
            {
                if(b->x>=p[i][0]&&b->x<=p[i][2]&&b->y>=p[i][1]&&b->y<=p[i][3])
                {
                    temp=2*(p[i][2]-p[i][0]+p[i][3]-p[i][1]);
                    break;
                }
            }
            if(i==n)
                temp=0;
            v2.push_back(temp);
        }
        sort(v2.begin(),v2.end());
        for(int i=v2.size()-1;i>=0;--i)
            cout<<v2[i]<<endl;
    }
    return 0;
}
