#include <iostream>
using namespace std;
#define MAXN 128

int c[MAXN];
int d[MAXN];

int main()
{
    int N;
    while(cin>>N)
    {
        for(int i=0;i<=N;i++)
        {
            c[i]=1;
            d[i]=0;
        }
        for(int i=2;i<=N;i++)
        {
            for(int j=0;j<=N;j++)
            {
                for(int k=0;k+j<=N;k+=i)
                {
                    d[j+k] += c[j];
                }
            }
            for(int j=0;j<=N; ++j)
            {
                c[j] = d[j];
                d[j] = 0;
            }
        }
        cout<<c[N]<<endl;
    }
    return 0;
}
