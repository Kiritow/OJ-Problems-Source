#include<iostream>
#include<string>
using namespace std;
int a[100],b[100];
int main()
{
    int N,i,j;
    while(cin>>N&&N)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        char c;
        cin>>c;
        if(c=='P')
        {
            for(i=1;i<=N;i++)
                cin>>b[i];
            for(i=1;i<=N;i++)
            {
               for(j=1;j<i;j++)
                   if(b[j]>b[i])
                     a[b[i]]++;
            }
            for(i=1;i<N;i++)
                cout<<a[i]<<" ";
            cout<<a[N]<<endl;
        }
       if(c=='I')
       {
           for(i=1;i<=N;i++)
               cin>>a[i];
           for(i=1;i<=N;i++)
           {
               j=1;
               int k=1;
               while(1)
               {
                  if(b[k]==0&&j>a[i])
                    break;
                   if(b[k]==0)
                       j++;
                      k++;
               }
               b[k]=i;
           }
           for(i=1;i<N;i++)
               cout<<b[i]<<" ";
           cout<<b[N]<<endl;
       }
       }
    return 0;
}
