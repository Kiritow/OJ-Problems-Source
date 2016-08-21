#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int n,i,j,k;
    char a[11][11],b[11][11];
    while((cin>>n>>k)>0)
    {
        getchar();
        for(i=1; i<=n; i++)
            for(j=1; j<=n; j++)
                cin>>a[i][j];
        k=k%4;
        while(k<=0)
            k+=4;
        while(k--)
        {
            for(i=1; i<=n; i++)
                for(j=1; j<=n; j++)
                    b[j][n-i]=a[i][j];
            for(i=1; i<=n; i++)
            {
                for(j=1; j<=n; j++)
                {
                    a[i][j]=b[i][j-1];
                    if(!k)
                        cout<<a[i][j];
                }
                if(!k)
                    cout<<endl;
            }
        }
    }
    return 0;
}
