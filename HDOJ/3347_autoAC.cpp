#include<iostream>
#include<map>
#include<string.h>
using namespace std;
const int MAX=1000000;
string str,var;
int n;
int Str2Int(string s)
{
    int end=0,a=1;
    if(s[0]=='-')
        end=1;
    int res=0;
    for(int i=s.size()-1;i>=end; i--)
    {
        res += (s[i]-'0')*a;
        a *= 10;
    }
    if(end) return -res;
    return res;
}
int main()
{
    map<string,int> m;
    int T,i,value;
    char c;
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(i=0;i<n-1;i++)
        {
            cin>>var>>c>>value;
            m[var]=value;
        }
        int tmp,ans=0;
        bool plus=true; 
        while(cin>>str)
        {
            if(str=="?") break;
            else if(str=="+") plus=true;
            else if(str=="-") plus=false;
            else if(str=="=") continue;
            else if(str[0]>='a' && str[0]<='z')
            {
                if(plus) ans += m[str];
                else ans -= m[str];
            }
            else
            {
                tmp=Str2Int(str);
                if(plus) ans += tmp;
                else ans -= tmp;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
