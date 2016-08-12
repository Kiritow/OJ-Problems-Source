#include<iostream>
#include <iomanip>
using namespace std;
int main(){
    const float pi = 3.1415927;
    float diameter_inch;
    int circle;
    float time_sec;
    int count = 1;
    while(cin>>diameter_inch>>circle>>time_sec && circle != 0){
        float distance;
        float time_hour;
        float speed;
        distance = pi * diameter_inch * circle / 5280 / 12;
        time_hour = time_sec / 3600;
        speed = distance / time_hour;
        cout<<"Trip #"<<count++<<": ";
        cout<<fixed<<setprecision(2)<<distance<<" "<<speed<<endl;
    }
}
