#include<iostream>
#include<climits>
using namespace std;
const int maxn=85;
int N,M,K,X,Y;
int matrix[maxn][maxn][maxn];
int t[maxn][maxn];                                 
int dis[maxn][maxn];
bool judge(int a,int b,int c) 
{
    int i,j,k;
    for(i=1;i<=M;++i)
    {
        t[0][i]=0;                                  
        for(j=1;j<=M;++j)
            t[0][i]+=matrix[a][i][j]*t[b][j];
    }
    for(i=1;i<=M;++i)
        if(t[0][i]!=t[c][i])                     
            return false;
    return true;
}
int main()
{
    int i,j,k;
    while(cin>>N>>M&&(M+N))
    {
        for(i=1;i<=N;++i)
            for(j=i+1;j<=N;++j)
                dis[i][j]=dis[j][i]=INT_MAX;
        for(i=1;i<=N;++i)                                       
            for(j=1;j<=M;++j)                                   
            {
                t[i][j]=0;                                      
                for(k=1;k<=M;++k)                               
                {
                    cin>>matrix[i][j][k];
                    t[i][j]+=matrix[i][j][k]*k;                
                }
            }
        for(i=1;i<=N;++i)
            for(j=1;j<=N;++j)
            {
                if(i==j)
                    continue;
                for(k=1;k<=N;++k)
                {
                    if(i==k||j==k||dis[i][k]==1)
                        continue;
                    if(judge(i,j,k))                           
                        dis[i][k]=1;
                }
            }
        for(k=1;k<=N;++k)                                          
            for(i=1;i<=N;++i)
            { 
                if(dis[i][k]==INT_MAX)
                    continue;
                for(j=1;j<=N;++j)
                    if(dis[k][j]<INT_MAX&&dis[i][k]+dis[k][j]<dis[i][j])
                        dis[i][j]=dis[i][k]+dis[k][j];
            }
        cin>>K;
        for(i=1;i<=K;++i)
        {
            cin>>X>>Y;
            if(dis[X][Y]==INT_MAX)
                cout<<"Sorry"<<endl;
            else
                cout<<dis[X][Y]<<endl;
        }
    }
    return 0;
}
