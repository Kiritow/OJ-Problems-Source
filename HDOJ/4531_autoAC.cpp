#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <iostream>
using namespace std;
char str[3][3][6];
char g[3][3][6];
map<int,int>mp;
queue<int>q;
bool mo[6];
int F[50];
int find(int x)
{
    if(F[x]==-1)return x;
    return F[x]=find(F[x]);
}
void bing(int x,int y)
{
    int t1=find(x);
    int t2=find(y);
    if(t1!=t2)F[t1]=t2;
}
bool judge(int state)
{
    char temp[10];
    int t[10];
    sprintf(temp,"%09d",state);
    for(int i=0;i<9;i++)t[i]=temp[i]-'0';
    for(int i=0;i<3;i++)
      for(int j=0;j<3;j++)
      {
          int p=t[3*i+j];
          int x=p/3;
          int y=p%3;
          strcpy(g[i][j],str[x][y]);
      }
    memset(F,-1,sizeof(F));
    for(int i=0;i<3;i++)
      for(int j=0;j<3;j++)
      {
          if(g[i][j][0]==g[i][j][2])bing(12*i+4*j,12*i+4*j+2);
          if(g[i][j][0]==g[i][j][3])bing(12*i+4*j,12*i+4*j+3);
          if(g[i][j][1]==g[i][j][2])bing(12*i+4*j+1,12*i+4*j+2);
          if(g[i][j][1]==g[i][j][3])bing(12*i+4*j+1,12*i+4*j+3);
      }
    for(int i=0;i<3;i++)
    {
        if(g[i][0][3]==g[i][1][2])bing(12*i+3,12*i+4+2);
        if(g[i][1][3]==g[i][2][2])bing(12*i+4+3,12*i+8+2);
    }
    for(int j=0;j<3;j++)
    {
        if(g[0][j][1]==g[1][j][0])bing(4*j+1,12+4*j+0);
        if(g[1][j][1]==g[2][j][0])bing(12+4*j+1,24+4*j+0);
    }
    int R=-1,G=-1,B=-1,O=-1;
    for(int i=0;i<3;i++)
      for(int j=0;j<3;j++)
        for(int k=0;k<4;k++)
        {
            int t1=find(12*i+4*j+k);
            if(g[i][j][k]=='R')
            {
                if(R==-1)R=t1;
                else if(t1!=R)return false;
            }
            else if(g[i][j][k]=='G')
            {
                if(G==-1)G=t1;
                else if(t1!=G)return false;
            }
            else if(g[i][j][k]=='B')
            {
                if(B==-1)B=t1;
                else if(t1!=B)return false;
            }
            else
            {
                if(O==-1)O=t1;
                else if(t1!=O)return false;
            }
        }
    return true;
}
int bfs()
{
    mp.clear();
    while(!q.empty())q.pop();
    int tmp,now;
    char ss1[10],ss2[10];
    tmp=12345678; 
    mp[tmp]=0;
    q.push(tmp);
    while(!q.empty())
    {
        tmp=q.front();
        q.pop();
        if(judge(tmp))return mp[tmp];
        sprintf(ss1,"%09d",tmp);
        for(int i=0;i<3;i++)
          for(int j=0;j<3;j++)
          {
              int t=ss1[3*i+j]-'0';
             strcpy(g[i][j],str[t/3][t%3]);
          }
        if(mo[0])
        {
            strcpy(ss2,ss1);
            ss2[0]=ss1[1];
            ss2[1]=ss1[2];
            ss2[2]=ss1[0];
            now=0;
            for(int i=0;i<9;i++)
            {
                now*=10;
                now+=ss2[i]-'0';
            }
            if(mp.find(now)==mp.end())
            {
                mp[now]=mp[tmp]+1;
                q.push(now);
            }
            ss2[0]=ss1[2];
            ss2[1]=ss1[0];
            ss2[2]=ss1[1];
            now=0;
            for(int i=0;i<9;i++)
            {
                now*=10;
                now+=ss2[i]-'0';
            }
            if(mp.find(now)==mp.end())
            {
                mp[now]=mp[tmp]+1;
                q.push(now);
            }
        }
        if(mo[1])
        {
            strcpy(ss2,ss1);
            ss2[3]=ss1[4];
            ss2[4]=ss1[5];
            ss2[5]=ss1[3];
            now=0;
            for(int i=0;i<9;i++)
            {
                now*=10;
                now+=ss2[i]-'0';
            }
            if(mp.find(now)==mp.end())
            {
                mp[now]=mp[tmp]+1;
                q.push(now);
            }
            ss2[3]=ss1[5];
            ss2[4]=ss1[3];
            ss2[5]=ss1[4];
            now=0;
            for(int i=0;i<9;i++)
            {
                now*=10;
                now+=ss2[i]-'0';
            }
            if(mp.find(now)==mp.end())
            {
                mp[now]=mp[tmp]+1;
                q.push(now);
            }
        }
        if(mo[2])
        {
            strcpy(ss2,ss1);
            ss2[6]=ss1[7];
            ss2[7]=ss1[8];
            ss2[8]=ss1[6];
            now=0;
            for(int i=0;i<9;i++)
            {
                now*=10;
                now+=ss2[i]-'0';
            }
            if(mp.find(now)==mp.end())
            {
                mp[now]=mp[tmp]+1;
                q.push(now);
            }
            ss2[6]=ss1[8];
            ss2[7]=ss1[6];
            ss2[8]=ss1[7];
            now=0;
            for(int i=0;i<9;i++)
            {
                now*=10;
                now+=ss2[i]-'0';
            }
            if(mp.find(now)==mp.end())
            {
                mp[now]=mp[tmp]+1;
                q.push(now);
            }
        }
        if(mo[3])
        {
            strcpy(ss2,ss1);
            ss2[0]=ss1[3];
            ss2[3]=ss1[6];
            ss2[6]=ss1[0];
            now=0;
            for(int i=0;i<9;i++)
            {
                now*=10;
                now+=ss2[i]-'0';
            }
            if(mp.find(now)==mp.end())
            {
                mp[now]=mp[tmp]+1;
                q.push(now);
            }
            ss2[0]=ss1[6];
            ss2[3]=ss1[0];
            ss2[6]=ss1[3];
            now=0;
            for(int i=0;i<9;i++)
            {
                now*=10;
                now+=ss2[i]-'0';
            }
            if(mp.find(now)==mp.end())
            {
                mp[now]=mp[tmp]+1;
                q.push(now);
            }
        }
        if(mo[4])
        {
            strcpy(ss2,ss1);
            ss2[1]=ss1[4];
            ss2[4]=ss1[7];
            ss2[7]=ss1[1];
            now=0;
            for(int i=0;i<9;i++)
            {
                now*=10;
                now+=ss2[i]-'0';
            }
            if(mp.find(now)==mp.end())
            {
                mp[now]=mp[tmp]+1;
                q.push(now);
            }
            ss2[1]=ss1[7];
            ss2[4]=ss1[1];
            ss2[7]=ss1[4];
            now=0;
            for(int i=0;i<9;i++)
            {
                now*=10;
                now+=ss2[i]-'0';
            }
            if(mp.find(now)==mp.end())
            {
                mp[now]=mp[tmp]+1;
                q.push(now);
            }
        }
        if(mo[5])
        {
            strcpy(ss2,ss1);
            ss2[2]=ss1[5];
            ss2[5]=ss1[8];
            ss2[8]=ss1[2];
            now=0;
            for(int i=0;i<9;i++)
            {
                now*=10;
                now+=ss2[i]-'0';
            }
            if(mp.find(now)==mp.end())
            {
                mp[now]=mp[tmp]+1;
                q.push(now);
            }
            ss2[2]=ss1[8];
            ss2[5]=ss1[2];
            ss2[8]=ss1[5];
            now=0;
            for(int i=0;i<9;i++)
            {
                now*=10;
                now+=ss2[i]-'0';
            }
            if(mp.find(now)==mp.end())
            {
                mp[now]=mp[tmp]+1;
                q.push(now);
            }
        }
    }
    return -1;
}
int main()
{
    int T;
    scanf("%d",&T);
    int iCase=0;
    while(T--)
    {
        iCase++;
        printf("Case #%d: ",iCase);
        for(int i=0;i<6;i++)mo[i]=true;
        for(int i=0;i<3;i++)
          for(int j=0;j<3;j++)
          {
              scanf("%s",&str[i][j]);
              if(str[i][j][4]=='1')
              {
                  mo[i]=false;
                  mo[3+j]=false;
              }
          }
        printf("%d\n",bfs());
    }
    return 0;
}
