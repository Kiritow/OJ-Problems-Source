#include<iostream>
using namespace std;
int main(){
    int a[100],k,n,i;
    while(cin>>n){
        k=0;
        while(n>0){
            if(n&1)a[k++]=1;
            else a[k++]=0;
            n>>=1;
        }
    for(i=k-1;i>=0;--i)
    if(i==0)
    cout<<a[i]<<endl;
    else
    cout<<a[i];    
    }
    return 0;
}
