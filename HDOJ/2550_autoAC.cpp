#include<iostream>
#include<map>
using namespace std;
int main()
{
    int t;
    while(cin>>t)
    {
        while(t--)
        {
            int n;
            cin>>n;
            map<int,int> m;
            while(n--)
            {
                int a,b;
                cin>>a>>b;
                m.insert({a,b});
            }
            auto b=m.cbegin();
            for(;b!=m.cend();++b)
            {
                for(int i=0;i!=b->second;++i)
                {
                    cout<<">+";
                    for(int j=0;j!=b->first-2;++j)
                        cout<<"-";
                    cout<<"+>\n";
                }
                cout<<endl;
            }
        }
    }
    return 0;
}
