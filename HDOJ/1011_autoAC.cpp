#include <vector>
#include <string.h>   
using namespace std;  
#include<stdio.h>   
int roomNumber,trooperNumber;  
vector<int> path[101];  
int dp[101][101];  
bool visited[101];  
int cost[101];  
int max(int a,int b)  
{  
    return a>b?a:b;  
}  
void solve(int deep)  
{  
    visited[deep]=true;  
    for (int i=0;i<path[deep].size();i++)  
    {  
        int value=path[deep][i];  
        if(visited[value]) continue;  
        solve(value);  
        for(int j=trooperNumber-1;j>=cost[deep];j--)  
            for (int index=1;index+j<=trooperNumber;index++)  
                if(dp[value][index])   
                    dp[deep][j+index]=max(dp[deep][j+index],dp[deep][j]+dp[value][index]);  
    }  
}  
int main()  
{  
    while (scanf("%d%d",&roomNumber,&trooperNumber)!=EOF)  
    {  
        if(roomNumber==-1&&trooperNumber==-1)  
            break;  
        for (int i=0;i<=roomNumber;i++)  
        {  
            path[i].clear();  
        }  
        memset(dp,0,sizeof(dp));  
        memset(visited,0,sizeof(visited));  
        int tempA;  
        for(int i=1;i<=roomNumber;i++)  
        {  
            scanf("%d%d",&cost[i],&tempA);  
            cost[i]=(cost[i]+19)/20;  
            for (int j=cost[i];j<=trooperNumber;j++)  
                dp[i][j]=tempA;  
        }  
        int tempB;  
        for(int i=1;i<=roomNumber-1;i++)  
        {  
            scanf("%d%d",&tempB,&tempA);  
            path[tempB].push_back(tempA);  
            path[tempA].push_back(tempB);  
        }  
        if(trooperNumber==0)  
            printf("0\n");  
        else   
        {  
            solve(1);  
            printf("%d\n",dp[1][trooperNumber]);  
        }  
    }  
    return 0;  
}
