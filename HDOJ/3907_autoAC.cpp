#include <iostream>
#include <string.h>
using namespace std;
struct e{
    int data;
    int weight;
    e *next;
};
e edge[1001];
int n;
void add(int s,int t,int weight){
    e *p=new e;
    p->data=t;
    p->next=edge[s].next;
    p->weight=weight;
    edge[s].next=p;
}
int s[1001],q[1001];
int f[1001][1001];
int solve(int s1,int t1,int w){
    int ans1=0;
    int ans2=0;
    int i,j,k;
    if(f[s1][t1]!=-1) return f[s1][t1];
    e *p=edge[s1].next;
    e *q1=p;
    if(w>q[s1])
    {
        while(p)
        {
            solve(p->data,s1,p->weight);
            ans1+=f[p->data][s1];
            p=p->next;
        }
        f[s1][t1]=ans1+s[s1];
    }
    else
    {
        while(p)
        {
            solve(p->data,s1,p->weight);
            ans1+=f[p->data][s1];
            p=p->next;
        }
        while(q1)
        {
            solve(q1->data,t1,w+q1->weight);
            ans2+=f[q1->data][t1];
            q1=q1->next;
        }
        f[s1][t1]=min(ans2,ans1+s[s1]);
    }
    return f[s1][t1];
}
void read(){
    int i,j,k,s1,t,root;
    int cas;
    cin>>cas;
    while(cas--)
    {
        cin>>n;
        memset(edge,0,sizeof(edge));
        memset(f,-1,sizeof(f));
        for(i=1;i<=n;i++)
        {
            cin>>j>>k>>s1>>t;
            if(j!=0) add(j,i,t);
            else root=i;
            q[i]=k;
            s[i]=s1;
        }
        e *p=edge[root].next;
        int ans=0;
        while(p)
        {
            ans+=solve(p->data,root,p->weight);
            p=p->next;
        }
        cout<<ans<<endl;
    }
}
int main(){
    read();
    return 0;
}
