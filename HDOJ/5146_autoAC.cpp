#include<iostream>
#include<cstring>
#define maxn 1000+5
using namespace std;
int n;
int mapp[maxn];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        memset(mapp,0,sizeof(mapp));
        cin>>n;
        int j=0,o=0;
        for(int i=1;i<=n;i++)
        {
            cin>>mapp[i];
            if(i%2) j+=mapp[i];
            else o+=mapp[i];
        }
        int flag=0;
        for(int i=1;i<=n/2;i++)
        {
            if(mapp[i]!=mapp[n-i+1])
            {
                flag=1;break;
            }
        }
        if(!flag||j!=o) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
    return 0;
}
