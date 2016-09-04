#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#define MAXN 11
#define MOD 40007
using namespace std;
const int n=8;
int a[MAXN][MAXN];
int x;
int DX[MAXN][MAXN]=
{
{0,1,1,0,1,0,0,0},
{1,0,0,1,0,1,0,0},
{1,0,0,1,0,0,1,0},
{0,1,1,0,0,0,0,1},
{1,0,0,0,0,1,1,0},
{0,1,0,0,1,0,0,1},
{0,0,1,0,1,0,0,1},
{0,0,0,1,0,1,1,0}
};
void print(int a[MAXN][MAXN])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++) cout<<a[i][j]<<" ";
        cout<<endl;
    }
}
void mult(int x[MAXN][MAXN],int y[MAXN][MAXN],int z[MAXN][MAXN])
{
    int t[MAXN][MAXN];
    memset(t,0,sizeof(t));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<n;k++) t[i][k]=(t[i][k]+x[i][j]*y[j][k])%MOD;
    for(int i=0;i<n;i++)                
        for(int j=0;j<n;j++) z[i][j]=t[i][j];
}
void calc(int x[MAXN][MAXN],int y,int z[MAXN][MAXN])
{
    int t[MAXN][MAXN];
    int a[MAXN][MAXN];
    memset(a,0,sizeof(a));
    memset(t,0,sizeof(t));
    for(int i=0;i<n;i++) a[i][i]=1;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) t[i][j]=x[i][j];
    if(y%2==1)
        mult(a,t,a);
    y=y/2;
    while(y>0)
    {
        mult(t,t,t);
        if(y%2==1) mult(a,t,a);
        y=y/2;
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) z[i][j]=a[i][j];
}
void solve()
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) a[i][j]=DX[i][j];
    calc(a,x,a);
    cout<<a[0][0]<<" "<<(a[3][0]+a[5][0]+a[6][0])%MOD<<" "<<(a[1][0]+a[2][0]+a[4][0])%MOD<<" "<<a[7][0]<<endl;
}
int main()
{
    int casen;
    scanf("%d",&casen);
    while(casen--)
    {
        cin>>x;
        solve();
    }
    return 0;
}
