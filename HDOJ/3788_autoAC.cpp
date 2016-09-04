#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#define INF 999999999
using namespace std;
int main(){
    string s;
    while(cin>>s){
        int a=0,b=0,c=0,z=0,i=0;
        bool flag=true;
        for(;s[i] != 'z' && s[i] != '\0';++i){
            if(s[i] != 'o'){cout<<"Wrong Answer"<<endl;flag=false;break;}
            else ++a;
        }
        ++i;
        for(;s[i] != 'j' && s[i] != '\0' && flag;++i){
            if(s[i] != 'o'){cout<<"Wrong Answer"<<endl;flag=false;break;}
            else ++b;
        }
        ++i;
        for(;s[i] != '\0' && flag;++i){
            if(s[i] != 'o'){cout<<"Wrong Answer"<<endl;flag=false;break;}
            else ++c;
        }
        if((!b || (a == 0 && c !=0) || (a !=0 && c == 0)) && flag){cout<<"Wrong Answer"<<endl;flag=false;}
        if(flag){
            if(a ==0 && c == 0 || (c%a == 0 && c/a == b))cout<<"Accepted"<<endl;
            else cout<<"Wrong Answer"<<endl;
        }
    }
    return 0;
}
