#include<iostream>
#include<cstring>
#define maxn 100+5
using namespace std;
int mapp[maxn];
int main()
{
    int n;
    while(cin>>n)
    {
        int sum=0;
        memset(mapp,0,sizeof(mapp));
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            if(!mapp[x]) sum++;
            mapp[x]++; 
        }
        int k;
        cin>>k;
        k-=(n-sum);
        if(k<=0) cout<<sum<<endl;
        else cout<<sum-k<<endl;
    }
    return 0;
}
