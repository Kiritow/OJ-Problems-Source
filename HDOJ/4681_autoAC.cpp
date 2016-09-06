#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
char sta[1001];
char stb[1001];
char stc[1001];
int lena,lenb,lenc;
int dp[1001][1001];
int dpf[1001][1001];
struct list
{
    int x;
    int y;
}node,n1,n2;
vector<list>vec[5];
void dps()
{
    int i,j;
    for(i=0;i<lena;i++)
        if(sta[i]==stb[0])
            for(i;i<lena;i++)dp[i][0]=1;
    for(i=0;i<lenb;i++)
        if(sta[0]==stb[i])
            for(i;i<lenb;i++)dp[0][i]=1;
    for(i=1;i<lena;i++)
    {
        for(j=1;j<lenb;j++)
        {
            if(sta[i]==stb[j])dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
}
void dpfs()
{
    int i,j;
    for(i=lena-1;i>=0;i--)
        if(sta[i]==stb[lenb-1])
            for(i;i>=0;i--)dpf[i][lenb-1]=1;
    for(i=lenb-1;i>=0;i--)
        if(sta[lena-1]==stb[i])
            for(i;i>=0;i--)dpf[lena-1][i]=1;
    for(i=lena-2;i>=0;i--)
    {
        for(j=lenb-2;j>=0;j--)
        {
            if(sta[i]==stb[j])dpf[i][j]=dpf[i+1][j+1]+1;
            else dpf[i][j]=max(dpf[i+1][j],dpf[i][j+1]);
        }
    }
}
void init()
{
    memset(dp,0,sizeof(dp));
    memset(dpf,0,sizeof(dpf));
    vec[0].clear();
    vec[1].clear();
    gets(sta);
    gets(stb);
    gets(stc);
    lena=strlen(sta);
    lenb=strlen(stb);
    lenc=strlen(stc);
}
void sear(char str[],int pos)
{
    int lens=strlen(str);
    int i,j,k;
    for(i=0;i<lens;i++)
    {
        if(str[i]==stc[0])
        {
            for(k=0,j=i;j<lens;j++)
            {
                if(str[j]==stc[k])k++;
                if(k==lenc)break;
            }
            if(j<lens)
            {
                node.x=i;
                node.y=j;
                vec[pos].push_back(node);
            }
        }
    }
}
void prin(int cas)
{
    int l1=vec[0].size();
    int l2=vec[1].size();
    int maxx=0;
    int i,j;
    for(i=0;i<l1;i++)
    {
        for(j=0;j<l2;j++)
        {
            n1=vec[0][i];
            n2=vec[1][j];
            int c1,c2;
            c1=c2=0;
            if(n1.x-1>=0&&n2.x-1>=0)c1=dp[n1.x-1][n2.x-1];
            if(n1.y+1<lena&&n2.y+1<lenb)c2=dpf[n1.y+1][n2.y+1];
            maxx=max(maxx,c1+c2+lenc);
        }
    }
    printf("Case #%d: %d\n",cas,maxx);
}
int main()
{
    int T,t;
    scanf("%d%*c",&T);
    for(t=1;t<=T;t++)
    {
        init();
        dps();
        dpfs();
        sear(sta,0);
        sear(stb,1);
        prin(t);
    }
    return 0;
}
