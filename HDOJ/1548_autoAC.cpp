#include<cstdio>  
#include<iostream>  
#include<cstring>  
#include<cmath>  
#include<queue>  
#define maxn 200 + 10  
bool vis[maxn];  
int n, a, b,dis[maxn];  
using namespace std;  
struct node 
{  
    int now;  
    int step;  
};  
int bfs(int aa, int bb) 
{  
    queue<node>q;  
    vis[aa] = 1;  
    node start,next;  
    start.now = aa;  
    start.step = 0;  
    q.push(start);  
    while (!q.empty()) 
    {  
        node s = q.front();  
        q.pop();  
        if (s.now == b)
        {  
            return s.step;  
        }  
        for (int i = 0; i < 2; i++)
        {  
            if(i==0)  
                next.now = s.now+dis[s.now];  
            else  
                next.now = s.now-dis[s.now];  
            if(!vis[next.now]&&next.now>=1&&next.now<=n)
            {  
                if(next.now==b)  
                    return s.step+1;  
                vis[next.now] = 1;  
                next.step = s.step+1;  
                q.push(next);  
            }  
        }  
    }  
    return -1;  
}  
int main() {  
    while (scanf("%d", &n) != EOF && n)
    {  
        memset(vis, 0, sizeof(vis)); 
        cin >> a >> b;  
        for(int i = 1;i<=n;i++)  
            cin>>dis[i];  
        int ans = bfs(a, 0);  
        cout<<ans<<endl;  
    }  
    return 0;  
}
