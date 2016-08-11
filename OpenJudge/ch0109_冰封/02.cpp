#include<map>
#include<iostream>
#include<string>
#include<stdio.h>

using namespace std;

map<int,string> _m_a_p_;

int main(void){
    int a,b;
    scanf("%d",&a);
    for(int i = 0; i < a; i++){
        int ssd;
        string fafafa;
        cin>>ssd>>fafafa;
        if(ssd > b){
            b = ssd;
        }
        _m_a_p_[ssd] = fafafa;
    }

    cout<<_m_a_p_[b];
    // getchar();
    // getchar();
    // getchar();
    // getchar();
    // getchar();
    return 0;
}