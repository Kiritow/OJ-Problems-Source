#include<iostream>
#include<cstring>
#include<cstdio>
const int MAX=1001;
int map[MAX][MAX];
int mark[MAX];
int pipei[MAX];
int n;
int m;
using namespace std;
bool find(int x)
{
    int i;
    for(i=1;i<=n;i++)
    {
        if(!mark[i]&&map[x][i])
        {
            mark[i]=1;
            if(pipei[i]==-1||find(pipei[i]))
            {
                pipei[i]=x;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int k,i,j,sum;
    while(cin>>k&&k)
    {
        cin>>m>>n;
        memset(map,0,sizeof(map));
        memset(pipei,-1,sizeof(pipei));
        sum=0;
        while(k--)
        {
            cin>>i>>j;
            map[i][j]=1;
        }
        for(i=1;i<=m;i++)
        {
            memset(mark,0,sizeof(mark));
            if(find(i))
            sum++;
        }
        cout<<sum<<endl;
    }
    return 0;
}
