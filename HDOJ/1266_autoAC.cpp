#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        string temp;
        while(n--)
        {
            cin>>temp;
            auto b=temp.begin();
            if(*b=='-')
            {
                cout<<'-';
                temp.erase(b);
            }
            int c=0;
            auto d=temp.crbegin();
            for(;d!=temp.crend();++d)
            {
                if(*d=='0')
                    c++;
                else
                    break;
            }
            for(d;d!=temp.crend();++d)
                cout<<*d;
            for(int i=0;i!=c;++i)
                cout<<'0';
            cout<<endl;
        }
    }
    return 0;
}
