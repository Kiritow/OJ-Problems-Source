#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
char str[15];
int map[15];
int len;
int vis[3][3][3][3][3][3][3][3][3][3]; 
int cor[3];
int flag;
struct node
{
    int m[15];
    int step;
}now,temp;
void bfs()
{
    queue<node> q;
    for(int i=0; i<10; i++)
    {
        now.m[i] = map[i];
    }
    vis[map[0]][map[1]][map[2]][map[3]][map[4]][map[5]][map[6]][map[7]][map[8]][map[9]] = 1;
    now.step = 0;
    q.push(now);
    while(!q.empty())
    {
        now = q.front();
        q.pop();
        int k;
        for(k=0; k<len-1; k++)
        {
            if(now.m[k] != now.m[k+1])
                break;
        }
        if(k >= len-1)
        {
            cout<<now.step<<endl;
                flag = 1;
                return;
        }
        for(int i=0; i<len-1; i++)
        {
            cor[0] = cor[1] = cor[2] = 0;
            temp = now;
            if(temp.m[i] != temp.m[i+1])
            {
                cor[temp.m[i]] = 1;
                cor[temp.m[i+1]] = 1;
                for(int j=0; j<=2; j++)
                {
                    if(!cor[j])
                    {
                        temp.m[i] = temp.m[i+1] = j;
                        break;
                    }
                }
                if(!vis[temp.m[0]][temp.m[1]][temp.m[2]][temp.m[3]][temp.m[4]][temp.m[5]][temp.m[6]][temp.m[7]][temp.m[8]][temp.m[9]])
                {
                    temp.step += 1;
                    vis[temp.m[0]][temp.m[1]][temp.m[2]][temp.m[3]][temp.m[4]][temp.m[5]][temp.m[6]][temp.m[7]][temp.m[8]][temp.m[9]] = 1;
                    q.push(temp);
                }
            }
        }
    }
}
int main()
{
    int t;
    string a;
    scanf("%d",&t);
    while(t--)
    {
        memset(vis, 0, sizeof(vis));
        scanf("%s",str); 
        len = strlen(str);
        for(int i=0; i<10; i++)
        {
            if(i > len)
            {
                map[i] = 3;
            }
            if(str[i] == 'r')
                map[i] = 0;
            else if(str[i] == 'g')
                map[i] = 1;
            else
                map[i] = 2;
        }
        flag = 0;
        bfs();
        if(!flag)
            cout<<"No solution!"<<endl;
    }
    return 0;
}
