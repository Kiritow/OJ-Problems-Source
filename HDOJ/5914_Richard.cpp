#include <iostream>
using namespace std;
int fbnq[20]={1,2,3,5,8,13,21};
bool remain[21]={0};
void init()
{
    for(int i=0;i<7;i++)
        remain[fbnq[i]]=true;
}
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        init();
        cout<<"Case #"<<i<<": ";
        int n;
        cin>>n;
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            if(remain[i]==true)sum++;
        }
        cout<<n-sum<<endl;
    }
}
