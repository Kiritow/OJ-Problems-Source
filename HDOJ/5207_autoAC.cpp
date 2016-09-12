#include<iostream>
#include<cstring>
#include<algorithm>
#define maxn 100000+5
using namespace std;
int mapp[maxn],head[maxn];
int n;
int main()
{
    cin.sync_with_stdio(false);
    int t,casee=1;
    cin>>t;
    while(t--)
    {
        cin>>n;
        memset(mapp,0,sizeof(mapp));
        memset(head,0,sizeof(head));
        int maxx=-1;
        for(int i=0;i<n;i++){int x;cin>>x;mapp[x]++;maxx=max(maxx,x);}
        for(int i=2;i<=maxx;i++)
        {
            for(int j=i;j<=maxx;j+=i)
            {
                if(mapp[j]) head[i]+=mapp[j];
            }
        }    
        cout<<"Case #"<<casee++<<": ";
        for(int i=maxx;i>=1;i--)
        {
            if(head[i]>=2) {cout<<i<<endl;break;}
        }
    }
    return 0;
}
