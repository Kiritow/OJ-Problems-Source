#include<map>
#include<string>
#include<iostream>
using namespace std;
int main(){
    string s;
    map<string,int>Map;
    while(getline(cin,s)&&s!="#")
    {
        int a=0;
        string str;
        Map.clear();
        int len=s.length();
        for(int i=0;i<len;i++){
            if(s[i]=='#')
                break;
            str.clear();
            while(s[i]>='a'&&s[i]<='z'){
                str+=s[i];
                i++;
                a=1;
            }
            if(a==1)
            {
                Map[str]++;
                a=0;
            }
        }
        int ans=Map.size();
        cout<<ans<<endl;
    }
    return 0;
}
