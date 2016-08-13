#include<iostream>
#include<algorithm>
using namespace std;
int cmp(int x,int y)
{
    return x>y;
    }
int main()
{
    int n,i,j,k;
    int a[60];
    i=0;
    while(cin>>n>>k&&(n||k))
    {
        i++;
        for(j=0;j<k;j++)
            cin>>a[j];
    sort(a,a+k,cmp);
        int max=n*k;
        int count=0;
        for(j=0;j<k;j++)
      if(a[j]==max)
      {
          count++;
          max--;
      }
      else max-=2;
                  cout<<"Case "<<i<<':'<<' '<<count<<endl;
    }
    return 0;
}
