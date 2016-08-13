#include<iostream>
#include<cstring>
using namespace std;
short x[5][2008];
int main()
{
    int n,i,j;
    while(cin>>n)
    {
        if(n<=4)
        {
            cout<<1<<endl;
            continue;
        }
        memset(x,0,sizeof(x));
        x[1][0]=1;
        x[2][0]=1;
        x[3][0]=1;
        x[4][0]=1;
        for(i=5;i<=n;++i)
        {
            memset(x[i%5],0,sizeof(x[i%5]));       
            for(j=0;j<=2005;++j)
            {
                x[i%5][j]+=x[(i-1)%5][j]+x[(i-2)%5][j]+x[(i-3)%5][j]+x[(i-4)%5][j];
                if(x[i%5][j]>=10)
                {
                    x[i%5][j+1]+=x[i%5][j]/10;
                    x[i%5][j]%=10;
                }
            }
        }
        i=2005;
        while(x[n%5][i]==0)
            --i;
        while(i>=0)
        {
            cout<<x[n%5][i];
            --i;
        }
        cout<<endl;
    }
    return 0;
}
