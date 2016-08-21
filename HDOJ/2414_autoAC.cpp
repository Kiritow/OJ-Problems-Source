#include <cstdio>  
#include <cstdlib>  
#include <cstring>  
#include <climits>  
#include <cctype>  
#include <cmath>  
#include <string>  
#include <sstream>  
#include <iostream>  
#include <algorithm>  
#include <iomanip>  
using namespace std;  
#include <queue>  
char mp[10][10];  
int xx[4]={-1,1,0,0};  
int yy[4]={0,0,-1,1};  
char fff[4]={'^','v','<','>'};  
int main()  
{  
    while(scanf("%s",mp[0])!=EOF)  
    {  
        if(strcmp(mp[0],"--")==0) break;  
        for(int i=1;i<8;i++)  
            scanf("%s",mp[i]);  
        int x,y,fx;  
        for(int i=0;i<8;i++)  
            for(int j=0;j<8;j++)  
            {  
                if(mp[i][j]=='^')  
                    x=i,y=j,fx=0;  
                if(mp[i][j]=='v')  
                    x=i,y=j,fx=1;  
                if(mp[i][j]=='<')  
                   x=i,y=j,fx=2;  
                if(mp[i][j]=='>')  
                    x=i,y=j,fx=3;  
            }  
            getchar();  
            char s[2001];  
            while(1)  
            {  
                gets(s);  
                if(s[0]=='#') break;  
                if(s[0]=='m')  
                {  
                    int step=s[5]-'0';  
                    if(s[6]>='0'&&s[6]<='9')  
                       step=8;  
                    int dx=x,dy=y;  
                    x+=xx[fx]*step;  
                    y+=yy[fx]*step;  
                    if(x>=8)x=7;  
                    if(y>=8)y=7;  
                    if(x<0)x=0;  
                    if(y<0)y=0;  
                    queue<char > q;  
                    while(!q.empty())   q.pop();  
                    int num=step;  
                    while(dx>=0&&dy>=0&&dx<8&&dy<8&&num) 
                    {  
                        num--;  
                        mp[dx][dy]='.';  
                        dx+=xx[fx],dy+=yy[fx];  
                        if((mp[dx][dy]>='a'&&mp[dx][dy]<='z')||mp[dx][dy]>='A'&&mp[dx][dy]<='Z')  
                        {  
                            q.push(mp[dx][dy]);  
                        }  
                    }  
                    mp[x][y]=fff[fx];  
                    dx=x,dy=y;  
                    while(dx>=0&&dy>=0&&dx<8&&dy<8) 
                    {  
                        dx+=xx[fx],dy+=yy[fx];  
                         if((mp[dx][dy]>='a'&&mp[dx][dy]<='z')||mp[dx][dy]>='A'&&mp[dx][dy]<='Z')  
                            q.push(mp[dx][dy]);  
                        if(!q.empty())  
                        {  
                            mp[dx][dy]=q.front();  
                            q.pop();  
                        }  
                    }  
                }  
                else  
                {  
                    if(s[5]=='l')  
                    {  
                        if(fx==0) fx=2;  
                        else if(fx==1) fx=3;  
                        else if(fx==2) fx=1;  
                        else if(fx==3) fx=0;  
                    }  
                    if(s[5]=='r')  
                   {  
                        if(fx==0) fx=3;  
                        else if(fx==1) fx=2;  
                        else if(fx==2) fx=0;  
                       else if(fx==3) fx=1;  
                   }  
                    if(s[5]=='b')  
                    {  
                        if(fx==0) fx=1;  
                       else if(fx==1) fx=0;  
                       else if(fx==2) fx=3;  
                        else if(fx==3) fx=2;  
                    }  
                    mp[x][y]=fff[fx];  
                }  
            }  
           for(int i=0;i<8;i++)  
            {  
                for(int j=0;j<8;j++)  
                    printf("%c",mp[i][j]);  
                printf("\n");  
            }  
           printf("\n");  
           memset(mp,0,sizeof(mp));  
    }  
    return 0;  
}
