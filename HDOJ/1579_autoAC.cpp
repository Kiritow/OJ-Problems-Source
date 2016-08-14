#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int w[23][23][23];
int get(int i,int j,int k)
{
    if(w[i][j][k]!=-1)
        return w[i][j][k];
    if(i<=0||j<=0||k<=0)  return 1;
    if(i>=20||j>=20||k>=20) return 1048576;
    if(i<j&&j<k)
    {
        return get(i,j,k-1)+get(i,j-1,k-1)-get(i,j-1,k);
    }
    else
    {
        return get(i-1,j,k)+get(i-1,j-1,k)+get(i-1,j,k-1)-get(i-1,j-1,k-1);
    }
}
int main()
{
    memset(w,-1,sizeof(w));
    w[0][0][0]=1;
    for(int i=0;i<=21;i++)
    {
        for(int j=0;j<=21;j++)
        {
            for(int k=0;k<=21;k++)
            {
                w[i][j][k]=get(i,j,k);
            }
        }
    }
    int a,b,c;
    while(cin>>a>>b>>c)
    {
        if(a==-1&&b==-1&&c==-1)  break;
        printf("w(%d, %d, %d) = ",a,b,c);
        if(a<=0||b<=0||c<=0) printf("%d\n",w[0][0][0]);
        else if(a>20||b>20||c>20) printf("%d\n",w[20][20][20]);
        else
        printf("%d\n",w[a][b][c]);
    }
    return 0;
}
