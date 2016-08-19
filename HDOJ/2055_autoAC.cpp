#include<iostream>
using namespace std;
int main(){
    int n,y,res;
    char x;
    cin>>n;
    while(n--){
        cin>>x>>y;
        y=(x>96)?96-x+y:x-64+y;
        cout<<y<<endl;
    }
    return 0;
}
