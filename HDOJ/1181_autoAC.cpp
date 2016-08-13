#include <iostream>
#include <cstdio>
#include <string.h>
#include <cmath>
#include <vector>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
int main ()
{
    char com[100][100];
    int vis[10000];
    int i,j,k=0,flag,fk,cot;
    while(gets(com[k]))
    {
        flag=0;
        while(com[k][0]!='0')
        {
            int num=strlen(com[k]);
            if(com[k][0]=='b'){flag++;fk=k;}
            if(com[k][num-1]=='m')flag++;
            k++;
            gets(com[k]);
        }
        if(flag<2)
            cout<<"No."<<endl;
        else
        {
            flag=0;
            memset(vis,0,sizeof(vis));
            queue<string>s;
            string t;
            vis[fk]=1;
            s.push(com[fk]);
            while(!s.empty())
            {
                t=s.front();
                s.pop();
                int num=t.length();
                char c=t[num-1];
                if(c=='m')
                {
                    flag=1;
                    break;
                }
                else
                {
                    for(i=0;i<k;i++)
                {
                    if(vis[i]==0&&com[i][0]==c)
                    {
                        vis[i]=1;
                        s.push(com[i]);
                        continue;
                    }
                }
                }
            }
            if(flag)cout<<"Yes."<<endl;
            else cout<<"No."<<endl;
        }
        k=0;
    }
    return 0;
}
