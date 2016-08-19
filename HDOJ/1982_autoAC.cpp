#include<iostream>
#include<sstream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
void process(string s)
{
    replace(s.begin(),s.end(),'-',' ');
    stringstream m(s);
    int t;
    while(m>>t)
    {
        cout<<(char)('A'+t-1);
    }
}
void run()
{
    string s,t="";
    cin>>s;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='#')
        {
            if(t!="")
            {
                process(t);
                t="";
            }
            cout<<" ";
        }
        else
        {
            t+=s[i];
        }
    }
    process(t);
    cout<<endl;
}
int main()
{
    int T;
    cin>>T;
    while(T--) run();
    return 0;
}
