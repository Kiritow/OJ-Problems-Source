#include<iostream>
#include<string>
#include<cctype>
#include<stack>
using namespace std;
struct Node{
    int k1,k2;
};
Node find(string s){
    Node k;
    int i,k1,k2;
    for(i=s.size()-1;i>=0;i--){
        if(s[i]=='('){
            k1=i; break;
        }
    }
    if(i==-1) k.k1=0;
    else k.k1=k1;
    for(i=0;i<s.size();i++){
        if(s[i]==')'&&i>k1){
            k2=i; break;
        }
    }
    if(i==s.size()) k.k2=0;
    else k.k2=k2;
    return k;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        Node k=find(s);
        if(k.k1+k.k2==0){
            string s2;
            for(int i=0;i<s.size();i++){
                if(!i&&islower(s[i])) s2+=s[i];
                else if(isdigit(s[i])){
                    for(int j=0;j<s[i]-'0';j++){
                        s2+=s[i+1];
                    }
                }
                else if(islower(s[i-1])&&islower(s[i])){
                    s2+=s[i];
                }
            }
            cout<<s2<<endl;
            continue;
        }
        while(k.k1+k.k2){
            string s1;
            for(int i=0;i<k.k1-1;i++){
                s1+=s[i];
            }
            if(k.k1==0||!isdigit(s[k.k1-1])){
                string s2;
                if(k.k1==0);
                else if(!isdigit(s[k.k1-1])) s2+=s[k.k1-1];
                for(int j=0;j<1;j++){
                    for(int p=k.k1+1;p<k.k2;p++){
                        if(isdigit(s[p])){
                            for(int j=0;j<s[p]-'0';j++){
                                s2+=s[p+1];
                            }
                        }
                        if(!isdigit(s[p-1])&&islower(s[p])){
                            s2+=s[p];
                        }
                    }
                    s1+=s2;
                }
            }
            else if(isdigit(s[k.k1-1])){
                for(int j=0;j<s[k.k1-1]-'0';j++){
                    string s2;
                    for(int p=k.k1+1;p<k.k2;p++){
                        if(isdigit(s[p])){
                            for(int j=0;j<s[p]-'0';j++){
                                s2+=s[p+1];
                            }
                        }
                        if(!isdigit(s[p-1])&&islower(s[p])){
                            s2+=s[p];
                        }
                    }
                    s1+=s2;
                }
            }
            for(int i=k.k2+1;i<s.size();i++){
                s1+=s[i];
            }
            s=s1;
            k=find(s);
        }
        cout<<s<<endl;
    }
    return 0;
}
