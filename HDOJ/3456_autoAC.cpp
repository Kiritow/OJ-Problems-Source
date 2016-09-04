#include<iostream>
#include<string>
using namespace std;
string word;
string buf;
int main(){
    bool sign=true;
    while(cin>>word){
        if(sign){
            buf+="Forty-two";
            sign=false;
        }
        if(word[word.size()-1]=='.'){
            buf.clear();
            sign=true;
            continue;
        }
        if(word[word.size()-1]=='?'){
            buf+=" ";
            buf+=word;
            buf[buf.size()-1]='.';
            cout<<buf<<endl;
            buf.clear();
            sign=true;
            continue;
        }
        if(word != "What"){
            buf+=" ";
            buf+=word;
        }
    }
    return 0;
}
