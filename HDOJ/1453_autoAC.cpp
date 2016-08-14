#include<cstdio>
#include<cstring>
#include <iostream>
using namespace std;
const int A=210;
int main()
{
    int m,n,i,j,ii,jj,c;
    cin>>m>>n;
    getchar();
    char p[A][A];
    int pp[A];
    for(i=0;i<m;i++)
    gets(p[i]);
    for(int k=m;k>=1;k--)
    {       
        int count=0;
        for(j=0;j<n;j++)
        for(i=0;i<m;i++)
        if(p[i][j]=='0')
        {
                          c=0;
                          for(jj=i;jj<m;jj++)
                          {
                                              if(p[jj][j]=='0') c++;
                                              else {jj--;break;}
                          }
                          if(c==k)
                          {
                                  count++;
                                  for(int jjj=i;jjj<=jj;jjj++) p[jjj][j]='1';                                 
                          }
                          i=jj;
        }
        pp[k-1]=count;
    }
    for(i=0;i<m;i++)
    {
                       if(pp[i]!=0) cout<<i+1<<" "<<pp[i]<<endl;                  
    }
    return 0;
}
