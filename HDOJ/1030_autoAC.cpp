#include <iostream>
#include <cmath>
using namespace std;
struct Note
{
    int x;
    int y;
    int z;
};
int main()
{
    Note a,b;
    int m,n;
while(cin>>m>>n)
{
    int sa=0;
    int sb=0;
    int k;
    int t=ceil(sqrt(m));
    a.x=t;
    k=(m-(t-1)*(t-1))/2;
    a.y=t-k;
    k=((2*t-1)-m+(t-1)*(t-1))/2;
    a.z=t-k;
    if((2*t-1-m+(t-1)*(t-1))%2==0)  sa=1;
    if(sa==0) a.z=a.z-1;
    t=ceil(sqrt(n));
    b.x=t;
    k=(n-(t-1)*(t-1))/2;
    b.y=t-k;
    k=((2*t-1)-n+(t-1)*(t-1))/2;
    b.z=t-k;
    if((2*t-1-n+(t-1)*(t-1))%2==0)  sb=1;;
    if(sb==0)  b.z=b.z-1;
    int ans=0;
    ans=abs(a.x-b.x)+abs(a.y-b.y)+abs(a.z-b.z);
    cout<<ans<<endl;
}
    return 0;
}
