#include<iostream>
#include<algorithm>
#include<queue>
#define MAXN 10010
using namespace std;
struct node
{
    int pri,num;
    bool friend operator<(const node a,const node b)
    {
        if(a.pri!=b.pri)
            return a.pri>b.pri;
        return a.num>b.num;
    }
};
int hash1[MAXN],h;
priority_queue<node> Q[MAXN];
int main()
{
    int n,x,y,r,cc;
    char str[10];
    while(scanf("%d",&n)==1)
    {
        h=0;
        cc=1;
        for(int i=0;i<=n;i++)
            while(!Q[i].empty())
                Q[i].pop();    
        memset(hash1,-1,sizeof(hash1));
        while(n--)
        {
            node temp;
            scanf("%s",str);
            if(str[0]=='R')
            {
                scanf("%d %d",&x,&y);
                if(hash1[x]==-1)
                    hash1[x]=h++;
                temp.num=cc++;
                temp.pri=y;
                Q[hash1[x]].push(temp);
            }
            else {
                scanf("%d",&r);
                if(hash1[r]==-1)
                    hash1[r]==h++;
                if(Q[hash1[r]].empty())
                    printf("No one fits!\n");
                else
                {
                    temp = Q[hash1[r]].top();
                    printf("%s gets Num %d: %d %d!\n",str,temp.num,r,temp.pri);
                    Q[hash1[r]].pop();
                }
            }
        }
    }
    return 0;
}
