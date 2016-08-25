#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#define INF 99999999
using namespace std;
const int MAX=10;
int main(){
    int t,b,w;
    cin>>t;
    while(t--){
        cin>>b>>w;
        if(w&1)printf("0.00 1.00\n");
        else printf("1.00 0.00\n");
    }
    return 0;
}
