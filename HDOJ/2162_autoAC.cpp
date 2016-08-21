#include <iostream>
using namespace std;
int main()
{
    int n,k=1;
    while((cin>>n)&&n>0)
    {
        int sum=0,x;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            sum+=x;
        }
        cout<<"Sum of #"<<k++<<" is "<<sum<<endl;
    }
    return 0;
}
