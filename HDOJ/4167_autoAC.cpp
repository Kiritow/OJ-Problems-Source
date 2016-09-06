#include<iostream>  
#include<sstream>  
#include<algorithm>  
#include<set>  
using namespace std;  
int main()  
{  
    cin.sync_with_stdio(false);  
    int n,maxlen,cas=1;  
    while(cin>>n>>maxlen)  
    {  
        if(n==0&&maxlen==0) break;  
        cout<<"Case "<<cas++<<endl;  
        string s,a,b,ss;  
        set<string>myset;  
        getline(cin,s);  
        for(int i=0;i<n;i++)  
        {  
            getline(cin,ss);  
            for(int j=0;j<ss.length();j++)  
                while(ss[j]==39||ss[j]==45) ss.erase(j,1);  
            istringstream oss(ss);  
            oss>>a;while(oss>>b);  
            s=a[0]+b;  
            for(int i=0;i<s.length();i++) s[i]=tolower(s[i]);             
            string add;int id=1;  
            if(s.length()>maxlen) s.erase(maxlen);  
            while(myset.find(s+add)!=myset.end())  
            {  
                add.clear();  
                if(id>9) add+=48+id/10;add+=48+id%10;  
                if(add.length()+s.length()>maxlen)   
                    s.erase(maxlen-add.length());  
                id++;  
            }  
            myset.insert(s+add);cout<<s+add<<endl;  
        }  
    }  
    return 0;  
}
