#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
using namespace std;
struct node
{
    char name[20];
    int  par,pri,id;
    friend bool operator < (node a,node b)
    {
        if(a.pri!=b.pri)
        {
            return a.pri>b.pri;
        }
        else return a.id>b.id;
    }
};
int main()
{
    char c[5],na[20];
    int pout,cnt=0,pcmp;
    node t;
    priority_queue<node> q;
    while(scanf("%s",c)!=EOF)
    {
        if(c[0]=='P')
        {
            scanf("%s %d %d",na,&pout,&pcmp);
            strcpy(t.name,na);
            t.par=pout;
            t.pri=pcmp;
            t.id=++cnt;
            q.push(t);
        }
        else 
        {
            if(!q.empty())
            {
                t=q.top();
                q.pop();
                printf("%s %d\n",t.name,t.par);
            }
            else 
            {
                printf("EMPTY QUEUE!\n");
            }
        }
    }
    return 0;
}
