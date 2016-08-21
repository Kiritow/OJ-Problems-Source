#include<iostream>
using namespace std;
int a[1001];
int main()
{
    int t,n,m,i,j,k;
    cin>>t;
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        int sum=0;
        for(i=1;i<=n;i++)
        {
            if(a[i]>a[m]) sum++;
        }
        cout<<sum<<endl;
    }
    return 0;
}
