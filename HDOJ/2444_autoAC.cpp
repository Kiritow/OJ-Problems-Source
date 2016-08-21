#include <stdio.h>
#include <string.h>
bool map[210][210];
bool visit[210];
int link[210];
int judge[210];
int queue[210];
int n,m;
bool BFS()
{ 
    int v,start = 0,end = 1;
    queue[0] = 1; 
    for(int i=0;i<=n;i++) 
        judge[i] = -1;
    v = queue[start];
    judge[1] = 0;
    memset(visit,0,sizeof(visit));
    while(start<end)
    {
        v= queue[start];
        for(int i = 1;i <= n; i++)
        {
            if(map[v][i]){
                if(judge[i] == -1){
                    judge[i] = (judge[v]+1)%2;
                    queue[end++] = i;   
                }
                else{
                    if(judge[i] == judge[v])
                        return false;           
                }
            }
        }
        start++;
    }
    return true;
}
int can(int r)
{
    for(int i=1;i<=n;i++)
    {
        if(map[r][i] && visit[i] == 0){
            visit[i] = 1;
            if(link[i]==0 || can(link[i])){
                link[i] = r;
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(map,0,sizeof(map));
        int a,b;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            map[a][b] = 1;
            map[b][a] = 1;
        }
        if(!BFS()) {
            printf("No\n");continue;
        }
        int num = 0;
        memset(link,0,sizeof(link));
        for(int i=1;i<=n;i++)
        {
            memset(visit,0,sizeof(visit));          
            if(can(i)) num++;
        }
        printf("%d\n",num/2);
    }
    return 0;
}
