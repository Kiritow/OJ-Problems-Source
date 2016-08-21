#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;
int main()
{
    int n;
    while(cin>>n&&n!=0)
    {
        cin.get();
        for(int i=1;i<=(n+1)/2;++i)
            cout<<i<<" ";
        cout<<"Score\n";
       vector<char> v1;
       vector<char> v2;
       int sum1=0,sum2=0;
       int i=0;
       int m=n;
       while(n--)
       {
           string temp;
           vector<string> v;
           getline(cin,temp);
           istringstream is(temp);
           string str;
           while(is>>str)
            v.push_back(str);
           str=v[v.size()-2];
            if(i%2==0&&str=="no")
                v1.push_back('X');
            else if(i%2==0&&str!="no")
            {
                v1.push_back('O');
                ++sum1;
            }
            else if(i%2==1&&str=="no")
                v2.push_back('X');
            else
            {
                v2.push_back('O');
                ++sum2;
            }
            ++i;
       }
       for(int j=0;j!=v1.size();++j)
        cout<<v1[j]<<" ";
       cout<<sum1<<endl;
       for(int j=0;j!=v2.size();++j)
        cout<<v2[j]<<" ";
       if(m%2==1)
        cout<<"- ";
       cout<<sum2<<endl;
    }
return 0;
}
