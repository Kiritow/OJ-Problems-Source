#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int g[14][14];
int visited[14];
int vec[14];
int t,n;
int path[14];
int rear;
int flag;
void DFS(int start,int sum)
{
    int j;
    visited[start]=1;
    path[rear]=vec[start];
    if(sum>t)return ;
    if(sum==t)
    {
        flag=1;
        for(j=0;j<rear;j++)
            cout<<path[j]<<"+";
        cout<<path[j]<<endl;
        return ;
    }
    for(j=start+1;j<=n;j++)
    {
        if(j!=start&&0==visited[j])
        {
            sum+=vec[j];
            rear++;
            DFS(j,sum);
            sum-=vec[j];
            rear--;
            visited[j]=0;
        }
        while(j+1<=n&&vec[j]==vec[j+1])
            j++;
    }
}
int main()
{
    int i,j,w;
    while(cin>>t>>n&&!(0==t&&0==n))
    {
        for(i=1;i<=n;i++)
        {    
            cin>>w;
            vec[i]=w;
            for(j=1;j<=n;j++)
                g[i][j]=w;
        }
        i=1;
        cout<<"Sums of "<<t<<":"<<endl;
        flag=0;
        for(i=1;i<=n;i++)
        {
        rear=0;
        memset(visited,0,sizeof(visited));
        DFS(i,vec[i]);
        while(i+1<=n&&vec[i]==vec[i+1])
            i++;
        }
        if(flag==0)
            cout<<"NONE"<<endl;
    }
    return 0;
}
