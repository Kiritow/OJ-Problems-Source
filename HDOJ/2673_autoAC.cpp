#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
   int n;
   while(cin>>n)
   {
      vector<int>v(n),vv(n);
      int i,j;
      for(i=0;i<n;i++)
      {
         cin>>v[i];
      }
      sort(v.begin(),v.end());
       int k=0;
     for(i=0,j=n-1;i<j;)
     {
         vv[k++]=v[j--];
         vv[k++]=v[i++];
     }
     if(i==j)
       vv[k]=v[i];
     for(i=0;i<n;i++)
       {
            if(i!=n-1)cout<<vv[i]<<" ";
            else cout<<vv[i]<<endl;
       }
    }
    return 0;
}
