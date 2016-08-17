#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;
const long long INF = 1e18;
const int maxn = 105;
long long map[maxn][maxn];
long long L1, L2, L3, L4;
long long C1, C2, C3, C4;
int n;
long long cost(long long dis)
{
    if(dis > 0 && dis <= L1)return C1;
    if(dis > L1 && dis <= L2)return C2;
    if(dis > L2 && dis <= L3)return C3;
    if(dis > L3 && dis <= L4)return C4;
    return INF;
}
void floyd()
{
    int i, j, k;
    for(k=1; k<=n; k++)
    for(i=1; i<=n; i++)
    for(j=1; j<=n; j++)
    {
        if(map[i][j] > map[i][k] + map[k][j])
            map[i][j] = map[i][k] + map[k][j];
    }
}
int main()
{
    int ncase, k=1;
    cin >> ncase;
    while(ncase--)
    {
        int m, a, b, i, j;
        long long f[maxn]={0};
        cin >> L1 >> L2 >> L3 >> L4;
        cin >> C1 >> C2 >> C3 >> C4;
        cin >> n >> m;
        for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            map[i][j] = INF;
        for(i=1; i<=n; i++)
            cin >> f[i];
        for(i=1; i<n; i++)
        for(j=i+1; j<=n; j++)
            map[i][j] = map[j][i] = cost(abs(f[i]-f[j]));
        floyd();
        cout << "Case " << k++ << ":" <<endl;
        for(i=0; i<m; i++)
        {
            cin >> a >> b;
            if(map[a][b] != INF)
                cout <<"The minimum cost between station "<< a <<" and station "<< b <<" is "<< map[a][b] <<"."<<endl;
            else
                cout <<"Station "<< a <<" and station "<< b <<" are not attainable."<<endl;
        }
    }
    return 0;
}
