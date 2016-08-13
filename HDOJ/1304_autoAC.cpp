#include <iostream>
#include <string>
using namespace std;
int main()
{
    string name1,name0;
    int n,i,submit,time;
    int solve1,solve0=0,penalty1,penalty0=0;
    cin>>n;
    while(n--)
    {
        cin>>name1;
        solve1=penalty1=0;
        for(i=0;i<4;i++)
        {
            cin>>submit>>time;
            if(time)
            {
                solve1++;
                penalty1=penalty1+time+(submit-1)*20;
            }
        }
        if(solve1>solve0||(solve1==solve0&&penalty1<penalty0))
        {
            name0=name1;
            solve0=solve1;
            penalty0=penalty1;
        }
    }
    cout<<name0<<" "<<solve0<<" "<<penalty0<<endl;
    return 0;
}
