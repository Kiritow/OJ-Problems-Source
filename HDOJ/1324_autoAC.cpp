#include<iostream>
using namespace std;
int record[100000];
int main()
{
        int z,i,m,l,j;
        int key=1;
        while(cin>>z>>i>>m>>l)
        {
            if(z==0&&i==0&&m==0&&l==0)
                break;
            int k=1;
            record[0]=l;
            int flag=0;
            while(1)
            {
                l=(z*l+i)%m;
                  for( j=0;j<k;j++)
                  {
                      if(record[j]==l)
                      {
                          flag=1;
                          break;
                      }
                  }
                  record[k++]=l;
                  if(flag)
                      break;
            }
            cout<<"Case "<<key<<':'<<' ';
            cout<<k-j-1<<endl;
            key++;
        }
        return 0;
}
