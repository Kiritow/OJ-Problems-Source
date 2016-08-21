#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cctype>
#include<iomanip>
using namespace std;
const int maxn=100000;
int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
bool isleap(int x){
    if(x%400==0)return true;
    if(x%100!=0&&x%4==0)return true;
    return false;
}
int f(int y,int m,int d){
    if(isleap(y))a[2]=29;
    int ret=d;
    for(int i=1;i<m;++i)
        ret+=a[i];
    a[2]=28;
    return ret;
}
bool isno(int y,int m,int d){
    if(isleap(y))a[2]=29;
    if(m>12||m<1)return true;
    if(d>a[m]||d<1)return true;
    a[2]=28;
    return false;
}
int main(){
    int y,m,d;
    while(cin>>y>>m>>d){
        if(isno(y,m,d)){
            cout<<"illegal"<<endl;
            continue;
        }
        int x=f(y,m,d)%7-1;
        if(y<2008){
            for(int i=y;i<2008;++i)
                if(isleap(i))x+=5;
                else x+=6;
        }
        else {
            for(int i=2008;i<y;++i)
                if(isleap(i))x+=2;
                else x+=1;
        }
        x%=7;
        if(x<0)x+=7;
        switch(x){
            case 0:cout<<"Tuesday"<<endl;break;
            case 1:cout<<"Wednesday"<<endl;break;
            case 2:cout<<"Thursday"<<endl;break;
            case 3:cout<<"Friday"<<endl;break;
            case 4:cout<<"Saturday"<<endl;break;
            case 5:cout<<"Sunday"<<endl;break;
            case 6:cout<<"Monday"<<endl;break;
        }
    }
    return 0;
}
