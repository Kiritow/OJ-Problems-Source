#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
int main()
{
    int INF=99999999,N,K,d[30][30],i,j,k,x,y,z,dp[256][30],e[8],v[30],c,b;
    string s,t;    
    while (cin >> N >> K && N) {
        map<string,int> cityMap;
        for(i=0;i<N;i++) 
            for(j=0;j<N;j++) 
                d[i][j]=i==j?0:INF;
        for(i=0;i<N;i++) {
            cin >> s;
            cityMap[s]=i;
        }
        if (K)
            while(cin >> s >> t >> z, x=cityMap[s], 
                    y=cityMap[t], 
                    d[x][y]=d[y][x]=min(d[y][x],z), --K);
        for(k=0;k<N;k++)
            for(i=0;i<N;i++)
                for(j=0;j<N;j++)
                    d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
        for(i=0;i<8;i++) {
            cin >> s;
            e[i]=cityMap[s];
            for(j=0;j<N;j++)
                dp[1<<i][j]=d[j][e[i]];
        }        
        for(i=1;i<256;i++) {
            if (!(i&(i-1)))
                continue;
            for(k=0;k<N;k++) {
                dp[i][k]=INF;
                v[k]=0;
                for(j=1;j<i;j++)
                    if ((i|j)==i)
                        dp[i][k]=min(dp[i][k],dp[j][k]+dp[i-j][k]);
            }
            for(j=0;b=INF,j<N;j++) {
                for(k=0;k<N;k++)
                    if (dp[i][k]<=b && !v[k])
                        b=dp[i][c=k];
                for(k=0,v[c]=1;k<N;k++)
                    dp[i][c]=min(dp[i][c],dp[i][k]+d[k][c]);
            }
        }      
        for(i=0,b=INF;z=0,i<256;b=min(b,z),i++)
              for(j=0;y=0,j<4;z+=!!y*dp[y][x],j++)
                for(k=0;k<8;k+=2)
                      if ((i>>k&3)==j)
                        y+=3<<k,x=e[k];        
        cout << b << endl;     
    }
    return 0;
}
