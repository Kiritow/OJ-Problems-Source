#include<iostream>
#include<vector>
int rev(int );
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        vector<int> v;
        while(n!=rev(n))
        {
            v.push_back(n);
            n+=rev(n);
        }
        v.push_back(n);
        cout<<v.size()-1<<endl;
        int i;
        for(i=0;i<v.size()-1;++i)
            cout<<v[i]<<"--->";
        cout<<v[i]<<endl;
    }
    return 0;
}
int rev(int n)
{
    int sum=0;
    while(n!=0)
    {
        sum=sum*10+n%10;
        n/=10;
    }
    return sum;
}
