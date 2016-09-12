#include <iostream>
using namespace std;
int main(){             
    int n,m,a,b,sign;   
    while(cin>>n>>m){   
        sign=0;       
        while(m--){     
            cin>>a>>b;
            if((a==1&&b==n)||(b==1&&a==n))
            sign=1;     
        }
        n=n*(n-1)/2;
        if(sign)
        cout<<"1 "<<n<<endl;
        else
        cout<<"1 1"<<endl;
    }
    return 0;
}
