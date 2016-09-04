#include<algorithm>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
#define eps 1e-10
#define N 100015
#define db double
db ans,p1,p2,win1,win2,win_num[2][2][2],dp[2][2][2];
int sign(db x){
    return (x > eps) - (x < -eps);
}
void dfs(int pl1,db p,int pl2,int v,int s){
    if((pl1 == 6&&pl2 <= 4)||pl1 == 7){
        win_num[s][0][v] += p*(pl1+pl2)*5.;
        dp[s][0][v] += p;
        return ;
    }
    if((pl2 == 6&&pl1 <= 4)||pl2 == 7){
        win_num[s][1][v] += p*(pl1+pl2)*5.;
        dp[s][1][v] += p;
        return ;
    }
    if(v) dfs(pl1,p*p2,pl2+1,v^1,s),dfs(pl1+1,p*(1.-p2),pl2,v^1,s);
    else dfs(pl1+1,p*p1,pl2,v^1,s),dfs(pl1,p*(1.-p1),pl2+1,v^1,s);
}
void dfs2(int l1,int l2,db pl1,db p,db pl2,int v){
    if(l1 == 3||l2 == 3){
        ans += p*(pl1+pl2);
        return ;
    }
    dfs2(l1+1,l2,pl1+win_num[v][0][0],dp[v][0][0]*p,pl2,0);
    dfs2(l1+1,l2,pl1+win_num[v][0][1],dp[v][0][1]*p,pl2,1);
    dfs2(l1,l2+1,pl1,dp[v][1][0]*p,pl2+win_num[v][1][0],0);
    dfs2(l1,l2+1,pl1,dp[v][1][1]*p,pl2+win_num[v][1][1],1);
}
char s[256];
int main()
{
    int T,cas = 1;
    int i,j,k;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s%s%lf",&s,&s,&p1);
        scanf("%s%s%lf",&s,&s,&p2);
        p1 /= 100.;
        p2 /= 100.;
        ans = 0.;
        for(i = 0; i < 2; i ++) for(j = 0; j < 2; j ++) for(k = 0; k < 2; k ++) win_num[i][j][k] = dp[i][j][k] = 0.;
        dfs(0,1.,0,0,0);
        dfs(0,1.,0,1,1);
        for(i = 0; i < 2; i ++) for(j = 0; j < 2; j ++) for(k = 0; k < 2; k ++) if(sign(dp[i][j][k])) win_num[i][j][k] /= dp[i][j][k];
        dfs2(0,0,0.,1.,0.,0);
        printf("Case #%d: %.6lf\n",cas++,ans);
    }
    return 0;
}
