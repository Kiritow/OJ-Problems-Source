#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<string>
using namespace std;
const int N = 3005;
const int M = 1000005;
int head[N];
struct node
{
    int to,next;
}e[M];
bool vis[N];
int num,id;
char s1[10005],s[9][100];
map<string,int>non,verb;
bool flag;
void build(int s,int ed)
{
    e[num].to = ed;
    e[num].next = head[s];
    head[s] = num ++;
}
void gofind(int cur,int tag)
{
    vis[cur] = true;
    if(flag)
        return;
    if(cur == tag)
    {
        flag = true;
        return;
    }
    int i;
    for(i = head[cur];~i;i = e[i].next)
        if(vis[e[i].to] == false)
            gofind(e[i].to,tag);
}
int main()
{
    int t,cas = 0;
    scanf("%d",&t);
    gets(s1);
    while(t --)
    {
        non.clear();verb.clear();
        memset(head,-1,sizeof(head));
        num = id = 1;
        printf("Case #%d:\n",++cas);
        while(gets(s1))
        {
            int len = strlen(s1);
            if(s1[len - 1] == '!')
                break;
            else if(s1[len - 1] == '.')
                {
                    s1[len - 1] = '\0';
                    if(sscanf(s1,"%s%s%s%s%s%s",s[0],s[1],s[2],s[3],s[4],s[5]) != 6)
                    {
                        sscanf(s1,"%s%s%s",s[2],s[3],s[4]);
                        string a,b;
                        a = s[2];b = s[4];
                        if(non.find(a) == non.end())
                            non[a] = id ++;
                        if(s[3][0] == 'a')
                        {
                            if(non.find(b) == non.end())
                                non[b] = id ++;
                            build(non[a],non[b]);
                        }
                        else
                        {
                            if(verb.find(b) == verb.end())
                                verb[b] = id ++;
                            build(non[a],verb[b]);
                        }
                    }
                    else
                    {
                        sscanf(s1,"%s%s%s%s%s%s",s[2],s[2],s[2],s[2],s[3],s[4]);
                        string a,b;
                        a = s[2];b = s[4];
                        if(verb.find(a) == verb.end())
                            verb[a] = id ++;
                        if(s[3][0] == 'a')
                        {
                            if(non.find(b) == non.end())
                                non[b] = id ++;
                            build(verb[a],non[b]);
                        }
                        else
                        {
                            if(verb.find(b) == verb.end())
                                verb[b] = id ++;
                            build(verb[a],verb[b]);
                        }
                    }
                }
                else if(s1[len -1] == '?')
                {
                    memset(vis,false,sizeof(vis));
                    s1[len - 1] = '\0';
                    if(sscanf(s1,"%s%s%s%s%s%s",s[0],s[1],s[2],s[3],s[4],s[5]) != 6)
                    {
                        sscanf(s1,"%s%s%s",s[3],s[2],s[4]);
                        string a,b;
                        a = s[2];b = s[4];
                        if(non.find(a) == non.end())
                            non[a] = id ++;
                        if(s[3][0] == 'a')
                        {
                            if(non.find(b) == non.end())
                                non[b] = id ++;
                            flag = false;
                            gofind(non[a],non[b]);
                            if(flag)
                                putchar('Y');
                            else
                                putchar('M');
                        }
                        else
                        {
                            if(verb.find(b) == verb.end())
                                verb[b] = id ++;
                            flag = false;
                            gofind(non[a],verb[b]);
                            if(flag)
                                putchar('Y');
                            else
                                putchar('M');
                        }
                    }
                    else
                    {
                        sscanf(s1,"%s%s%s%s%s%s",s[3],s[3],s[3],s[3],s[2],s[4]);
                        string a,b;
                        a = s[2];b = s[4];
                        if(verb.find(a) == verb.end())
                            verb[a] = id ++;
                        sscanf(s1,"%s",s[3]);
                        if(s[3][0] == 'a')
                        {
                            if(non.find(b) == non.end())
                                non[b] = id ++;
                            flag = false;
                            gofind(verb[a],non[b]);
                            if(flag)
                                putchar('Y');
                            else
                                putchar('M');
                        }
                        else
                        {
                            if(verb.find(b) == verb.end())
                                verb[b] = id ++;
                            flag = false;
                            gofind(verb[a],verb[b]);
                            if(flag)
                                putchar('Y');
                            else
                                putchar('M');
                        }
                    }
                }
        }
        putchar(10);
    }
    return 0;
}
