#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int p[111];
int cmp(int x,int y)
{
    if(x>y)
        return 0;
    else return 1;
}
int main()
{
    int n;
    while(cin>>n&&n)
    {
        for(int i=0;i<n;i++)
        {
            cin>>p[i];
        }
        int sum=0;
        sort(p,p+n,cmp);
        for(int i=0;i<(n/2+1);i++)
        {
            sum+=p[i]/2+1;
        }
        cout<<sum<<endl;
    }
    return 0;
}
