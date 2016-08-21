#include<iostream>
const int MAX=200001;
int s[MAX];
using namespace std;
int main()
{
    int n,m,i,j,sum;
    while(cin>>n,n!=0)
    {
        sum=0;
        cin>>s[0];
        sum=s[0];
        for(i=1;i<n;i++)
        {
            cin>>s[i];
            sum^=s[i];
        }
        if(!sum)
        cout<<"No"<<endl;
        else
        {
            cout<<"Yes"<<endl;
            for(i=0;i<n;i++)
            {
                j=sum^s[i];
                if(j<s[i])
                cout<<s[i]<<" "<<j<<endl;
            }
        }
    }
    return 0;
}
