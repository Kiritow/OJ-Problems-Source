#include<iostream>
#include<cstring>
using namespace std;
const int MAX=3000004;
long long e[MAX];
void euler()
{
    e[1]=0;
    for(int i=2;i<MAX;++i)
        e[i]=i;
    for(int i=2;i<MAX;++i)
        if(e[i]==i)
            for(int j=i;j<MAX;j+=i)
                e[j]=e[j]/i*(i-1);
    for(int i=2;i<MAX;++i)
        e[i]+=e[i-1];
}
int main()
{
    euler();
    int a,b;
    while(cin>>a>>b)
        cout<<e[b]-e[a-1]<<endl;
    return 0;
}
