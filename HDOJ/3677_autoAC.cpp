#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int L,N,i,T,a[10];
        int t=0,time;
        while(cin>>L>>N>>T)
        { 
                if(L==0) break;
                for(i=0;i<N;i++)
                        cin>>a[i];
                sort(a,a+N);
      time=T*(N-1)+L/a[0];
          cout<<"Case "<<++t<<": "<<time<<endl;
        }
        return 0;
}
