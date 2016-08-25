#include <iostream>
using namespace std;
int main(int argc, const char * argv[])
{
    int a,b,set(int, const int = 10,const int = 9, const int = 1);
    while (cin >>a>>b) {
        cout<<set(set(a)-set(b),9,10,0)<<endl;
    }
    return 0;
}
int set(int s, const int x, const int y, const int z)
{
    int sum=0;
    for(int i=1;s>0;s/=x,i*=y) {
        sum+=(z||(s%x)?s%x:((s-=9),9))*i;
    }
    return sum;
}
