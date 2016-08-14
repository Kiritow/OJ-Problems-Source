#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
struct node
{
    int RP;
    char name[25];
    bool operator < (const node a) const    
    {
        if(RP==a.RP)                
        {
            if(strcmp(name,a.name)>0)
                return 0;
            else
                return 1;
        }
        return RP>a.RP;                    
    }
}t;
priority_queue <node> q[10011];            
int main()
{
    int M,N,k;
    int i,j,x1,x2;
    char ch[20];
    while(scanf("%d%d",&M,&N)!=EOF)
    {
        for(i=0;i<10011;i++)        
        {
            while(!q[i].empty())
                q[i].pop();
        }
        for(i=1;i<=M;i++)
        {
            scanf("%d",&k);
            for(j=0;j<k;j++)
            {
                scanf("%s%d",t.name,&t.RP);
                q[i].push(t);
            }
        }
        for(i=1;i<=N;i++)
        {
            scanf("%s",ch);
            if(strcmp(ch,"GETOUT")==0)
            {
                scanf("%d",&k);
                cout<<q[k].top().name<<endl;
                q[k].pop();
            }
            else if(strcmp(ch,"GETON")==0)
            {
                scanf("%d%s%d",&k,t.name,&t.RP);
                q[k].push(t);
            }
            else if(strcmp(ch,"JOIN")==0)
            {
                scanf("%d%d",&x1,&x2);
                while(!q[x2].empty())
                {
                    t=q[x2].top();
                    q[x1].push(t);
                    q[x2].pop();
                }
            }
        }
    }
    return 0;
}
