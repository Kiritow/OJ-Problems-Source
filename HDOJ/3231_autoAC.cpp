#include <queue>
#include <stdio.h>
#include <string.h>
using namespace std;
#define N 2005
struct T
{
    int v,next;
}E[3][N*100];
struct TT
{
    int head,rd,dep;
}V[3][N];
int top[3],ans,n,m;
void Add_Edge(int k,int u,int v)
{
    E[k][top[k]].v = v;
    E[k][top[k]].next = V[k][u].head;
    V[k][u].head = top[k]++;
    ++V[k][v].rd;
}
bool Top_Sort(int k)
{
    queue<int> Q;
    for(int i=1;i<=n;i++)
        if(V[k][i].rd == 0)
            Q.push(i);
    int cnt = 0;
    while(!Q.empty())
    {
        ++cnt;
        int p = Q.front();
        for(int i=V[k][p].head;i!=NULL;i=E[k][i].next)
        {
            int q = E[k][i].v;
            --V[k][q].rd;
            if(V[k][q].rd == 0)
            {
                Q.push(q);
                V[k][q].dep = V[k][p].dep + 1;
            }
        }
        Q.pop();
    }
    return cnt == n;
}
int main()
{
    int u,v,nn,ncase=0;
    char cmd;
    while(~scanf("%d%d%*c",&nn,&m),nn)
    {
        memset(V,0,sizeof(V));
        top[0] = top[1] = top[2] = 1;
        n = 2*nn;
        for(int k=0;k<3;k++)
            for(int i=1;i<=nn;i++)
                Add_Edge(k,i,i+nn);
        while(m--)
        {
            scanf("%c%d%d%*c",&cmd,&u,&v);
            if(cmd == 'I')
            {
                for(int k=0;k<3;k++)
                {
                    Add_Edge(k,u,v+nn);
                    Add_Edge(k,v,u+nn);
                }
            }
            else
                Add_Edge(cmd-'X',u+nn,v);
        }
        printf("Case %d: ",++ncase);
        if(!Top_Sort(0) || !Top_Sort(1) || !Top_Sort(2))
            puts("IMPOSSIBLE\n");
        else
        {
            puts("POSSIBLE");
            for(int i=1;i<=nn;i++)
                printf("%d %d %d %d %d %d\n",V[0][i].dep,V[1][i].dep,V[2][i].dep,V[0][i+nn].dep,V[1][i+nn].dep,V[2][i+nn].dep);
            puts("");
        }
    }
    return 0;
}
