#include<iostream>
const int MAX=11;
int s[MAX];
using namespace std;
int main()
{
    int n,m,i,sum;
    while(cin>>n)
    {
        while(n--)
        {
            cin>>m;
            sum=0;
            for(i=0;i<m;i++)
            {
                cin>>s[i];
                sum+=s[i];
            }
            cout<<sum-m+1<<endl;
        }
    }
    return 0;
}
