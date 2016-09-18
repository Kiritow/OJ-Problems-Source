/*
 * HDU 5880 Family View
 * 把文本串中所有的模式串换为等长度的'*'
 * 
 * AC自动机
 * 将模式串建立AC自动机，然后进行文本串匹配，求出文本串的每个前缀
 * 所包含的最长后缀，并且是模式串，用pos数组记录位置，然后扫描一遍输出即可。
 */

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

const int MAXN = 1000000+100;
char str[MAXN];
int pos[MAXN];
struct Aho_Corasick
{
    const static int maxnode = 1000000+100;
    const static int type = 26;
    int next[maxnode][type],fail[maxnode],end[maxnode],l[maxnode];
    int root,L;
    int newnode()
    {
        for(int i = 0;i<type;i++)
            next[L][i] = -1;
        l[L]=0;
        end[L++] = -1;
        return L-1;
    }
    void init()
    {
        L = 0;
        root = newnode();
    }
    void insert(char* str)
    {
        int len = strlen(str);
        int now = root;
        for(int i = 0;i < len;i++)
        {
            int id=str[i]-'a';
            if(next[now][id] == -1)
                next[now][id] = newnode();
            now=next[now][id];
        }
        end[now]=1;
        l[now]=len;
    }
    void build()
    {
        queue<int>Q;
        fail[root] = root;
        for(int i = 0;i < type;i++)
            if(next[root][i] == -1)
                next[root][i] = root;
            else
            {
                fail[next[root][i]] = root;
                Q.push(next[root][i]);
            }
        while(!Q.empty())
        {
            int now = Q.front();
            Q.pop();
            for(int i = 0;i < type;i++)
                if(next[now][i] == -1)
                    next[now][i] = next[fail[now]][i];
                else
                {
                    fail[next[now][i]] = next[fail[now]][i];
                    Q.push(next[now][i]);
                }
        }
    }
    void work(char* str)
    {
        int id;
        int len = strlen(str);
        int now = root;
        memset(pos,0,sizeof(pos));
        for(int i = 0;i < len;i++)
        {
            if(str[i]>='A'&&str[i]<='Z') id=str[i]-'A';
            else if(str[i]>='a'&&str[i]<='z') id=str[i]-'a';
            else continue;
            now = next[now][id];
            int temp=now;
            while(temp != root)
            {
                if(end[temp] != -1)
                {
                    pos[i+1]-=1;
                    pos[i-l[temp]+1]+=1;
                    break;
                }
                temp = fail[temp];
            }
        }
        long long cnt=0;
        for(int i=0;i<len;i++)
        {
            cnt+=pos[i];
            if(cnt<=0) printf("%c",str[i]);
            else printf("*");
        }
        printf("\n");
    }
}AC;

int main()
{
    int T;
    int n;
    scanf("%d",&T);
    while(T--)
    {
        AC.init();
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%s",str);
            AC.insert(str);
        }
        AC.build();
        getchar();
        gets(str);
        AC.work(str);
    }
    return 0;
}
