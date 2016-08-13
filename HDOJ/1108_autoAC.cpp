#include <iostream>
using namespace std;
int main(){
    int a,b;
    while(cin>>a>>b){
        int aa,bb,tmp;
        if(a<b){ 
            tmp=a;
            a=b;
            b=tmp;
        }
        aa=a;
        bb=b;
        while(b!=0){ 
                         tmp=a%b;
           a=b;
           b=tmp;
        }
        int lcm;
        lcm=aa*bb/a;
        cout<<lcm<<endl;
    }
    return 0;
}
