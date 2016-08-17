#include<iostream>
#include<set>
#include<string>
using namespace std;
int main(){
    set<string> Set;
    int t,n,nc;
    string str;
    cin>>t;
    while(t--){
        cin>>n>>nc>>str;
        int size=str.size();
        for(int i=0;i<size-n+1;i++){
            string tmp(str,i,n);
            Set.insert(tmp);
        }
        cout<<Set.size()<<endl;
    }
    return 0;
}
