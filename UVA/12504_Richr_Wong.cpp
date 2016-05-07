#include <iostream>
#include <strstream>
#include <sstream>
#include <map>
#include <set>
#include <cstdio>
#include <cstring>
using namespace std;
char bufold[1000],bufnnew[1000];
string key,value;
map<string,string>old,nnew;
map<string,string>::iterator it;
set<string>add,sub,cha;
set<string>::iterator itt;
inline void filter(char *str,int n){
    for(int i=0;i<n;i++)if(str[i]=='{'||str[i]==':'||str[i]==','||str[i]=='}')str[i]=' ';
}
int main()
{
    int n;
    cin>>n;
    getchar();
    while(n--)
    {
        gets(bufold);
        gets(bufnnew);
        filter(bufold,strlen(bufold));
        filter(bufnnew,strlen(bufnnew));
        istringstream oldin(bufold);
        istringstream nnewin(bufnnew);
        old.clear();nnew.clear();
        while(oldin>>key>>value)old[key]=value;
        while(nnewin>>key>>value)nnew[key]=value;
        add.clear();sub.clear();cha.clear();
        for(it=nnew.begin();it!=nnew.end();it++)
            if(old.find(it->first)==old.end())add.insert(it->first);
        for(it=old.begin();it!=old.end();it++)
            if(nnew.find(it->first)==nnew.end())sub.insert(it->first);
        for(it=nnew.begin();it!=nnew.end();it++)
            if(old.find(it->first)!=old.end()&&old[it->first]!=it->second)
                cha.insert(it->first);
        if(add.empty()&&sub.empty()&&cha.empty()){
            cout<<"No changes"<<endl;
        }
        if(!add.empty()){
            cout<<"+"<<*(add.begin());
            for(itt=add.begin(),itt++;itt!=add.end();itt++)cout<<","<<*itt;cout<<endl;
        }
        if(!sub.empty()){
            cout<<"-"<<*(sub.begin());
            for(itt=sub.begin(),itt++;itt!=sub.end();itt++)cout<<","<<*itt;cout<<endl;
        }
        if(!cha.empty()){
            cout<<"*"<<*(cha.begin());
            for(itt=cha.begin(),itt++;itt!=cha.end();itt++)cout<<","<<*itt;cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}
