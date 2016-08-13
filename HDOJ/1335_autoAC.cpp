#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;
int powe(int,int);
int main()
{
    string s;
    short b,e;
    while(cin>>s>>b>>e)
    {
        vector<char> v;
        string str="";
        int sum=0;
        for(int i=s.size()-1,c=0;i>=0;--i,++c)
        {
            if(s[i]>='0'&&s[i]<='9')
                sum+=(s[i]-48)*powe(b,c);
            if(s[i]>='A'&&s[i]<='F')
                sum+=(s[i]-55)*powe(b,c);
        }
        int r;
        while(sum!=0)
        {
            r=sum%e;
            if(r>=0&&r<=9)
                v.push_back(r+48);
            else if(r==10)
                v.push_back('A');
            else if(r==11)
                v.push_back('B');
            else if(r==12)
                v.push_back('C');
            else if(r==13)
                v.push_back('D');
            else if(r==14)
                v.push_back('E');
            else
                v.push_back('F');
            sum/=e;
        }
        for(int i=v.size()-1;i>=0;--i)
            str+=v[i];
        if(str.size()>7)
            cout<<setw(7)<<right<<"ERROR"<<endl;
        else
            cout<<setw(7)<<right<<str<<endl;
    }
    return 0;
}
int powe(int m,int n)
{
    int sum=1;
    while(n--)
        sum*=m;
    return sum;
}
