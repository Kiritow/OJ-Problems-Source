#include <iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<cctype>
#include<map>
#include<string>
#include<set>
#include<queue>
#include<vector>
using namespace std;
const int N = 100005;
const int M = 8;
const int INF = 0x3f3f3f3f;
const double eps = 1e-5;
const double PI = acos(-1.0);
typedef __int64 ll;
map<int,int> mp[M][M];
struct node
{
    int num[3];
    string ans;
}ss,now;
int lcm[3][3];
int sa,sb,sc,ea,eb,ec;
struct wocao
{
    struct node t[N];
    int head,tail;
    void init()
    {
        head = tail = 0;
    }
    bool empty()
    {
        return head == tail;
    }
    void push(struct node a)
    {
        t[tail] = a;
        tail ++;
        if(tail >= N)
            tail -= N;
    }
    struct node front()
    {
        return t[head];
    }
    void pop()
    {
        head ++;
        if(head >= N)
            head -= N;
    }
}q;
void bfs()
{
    ss.ans.clear();
    ss.num[0] = sa;ss.num[1] = sb;ss.num[2] = sc;
    for(int i = 0;i < M;i ++)
        for(int j = 0;j < M;j ++)
            mp[i][j].clear();
    mp[sa][sb][sc] = 1;
    q.init();
    q.push(ss);
    while(!q.empty())
    {
        now = q.front();
        q.pop();
        int i;
        for(i = 0;i < 3;i ++)
        {
            ss = now;
            if(ss.num[i])
            {
                ss.num[i] --;
                ss.num[0] += lcm[i][0];
                ss.num[1] += lcm[i][1];
                ss.num[2] += lcm[i][2];
                if(ss.num[0] >= M || ss.num[1] >= M || ss.num[2] >= M)
                    continue;
                if(mp[ss.num[0]][ss.num[1]].find(ss.num[2]) == mp[ss.num[0]][ss.num[1]].end())
                {
                    mp[ss.num[0]][ss.num[1]][ss.num[2]] = 1;
                    ss.ans += 'A' + i;
                    if(ss.num[0] == ea && ss.num[1] == eb && ss.num[2] == ec)
                    {
                        cout<<ss.ans.length()<<" "<<ss.ans<<endl;
                        return;
                    }
                    q.push(ss);
                }
            }
        }
        for(i = 0;i < 3;i ++)
        {
            ss = now;
            if(ss.num[0] >= lcm[i][0] && ss.num[1] >= lcm[i][1] && ss.num[2] >= lcm[i][2])
            {
                ss.num[0] -= lcm[i][0];
                ss.num[1] -= lcm[i][1];
                ss.num[2] -= lcm[i][2];
                ss.num[i] ++;
                if(ss.num[0] >= M || ss.num[1] >= M || ss.num[2] >= M)
                    continue;
                if(mp[ss.num[0]][ss.num[1]].find(ss.num[2]) == mp[ss.num[0]][ss.num[1]].end())
                {
                    mp[ss.num[0]][ss.num[1]][ss.num[2]] = 1;
                    ss.ans += 'a' + i;
                    if(ss.num[0] == ea && ss.num[1] == eb && ss.num[2] == ec)
                    {
                        cout<<ss.ans.length()<<" "<<ss.ans<<endl;
                        return;
                    }
                    q.push(ss);
                }
            }
        }
    }
    puts("NO SOLUTION");
}
int main()
{
    int cas,t,n;
    int i,j;
    scanf("%d",&t);
    while(t --)
    {
        scanf("%d%d",&cas,&n);
        for(i = 0;i < 3;i ++)
        {
            for(j = 0;j < 3;j ++)
            {
                scanf("%d",&lcm[i][j]);
            }
        }
        int ca;
        printf("%d %d\n",cas,n);
        while(n --)
        {
            scanf("%d%d%d%d%d%d%d",&ca,&sa,&sb,&sc,&ea,&eb,&ec);
            printf("%d ",ca);
            bfs();
        }
    }
    return 0;
}
