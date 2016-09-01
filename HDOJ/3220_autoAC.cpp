#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
using namespace std;
const int MAX=1<<17;
const int x[32]={0,1,3,11,10,8,10,2,8,9,9,0,0,1,3,11,10,8,9,2,12,13,13,4,14,6,12,4,5,7,15,14};
const int y[32]={1,3,11,10,8,0,2,3,9,1,11,2,4,5,7,15,14,12,13,6,13,5,15,6,6,7,4,5,7,15,14,12};
const int aim=((1<<8)-1);
int dist[MAX];
struct Node
{
    int st;
    int depth;
};
int has(const int& st,const int& op)
{
    return st^((1<<(15-x[op]))|(1<<(15-y[op])));
}
void bfs()
{
    Node node,next;
    queue<Node> q;
    node.st=aim;
    node.depth=0;
    dist[aim]=0;
    q.push(node);
    while(!q.empty())
    {
        node=q.front();
        q.pop();
        if(node.depth>3)
            break;
        next.depth=node.depth+1;
        for(int i=0;i<32;i++)
        {
            if((node.st&(1<<(15-x[i])))!=(node.st&(1<<(15-y[i]))))
            {
                next.st=has(node.st,i);
                if(dist[next.st]==1000)
                {
                    dist[next.st]=next.depth;
                    q.push(next);
                }
            }
        }
    }
}
int main()
{
    int t,cnt=0;
    int a;
    int st;
    for(int i=0;i<MAX;i++)
    {
        dist[i]=1000;
    }
    bfs();
    scanf("%d",&t);
    while(t--)
    {
        cnt++;
        st=0;
        for(int i=0;i<16;i++)
        {
            scanf("%d",&a);
            if(a==1)
                st|=(1<<(15-i));
        }
        a=dist[st];
        if(a>3)
        {
            printf("Case #%d: more\n",cnt);
        }
        else
        {
            printf("Case #%d: %d\n",cnt,a);
        }
    }
    return 0;
}
