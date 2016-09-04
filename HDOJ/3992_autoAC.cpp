#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=100000;
struct Node
{
    int flag;
    int id;
    Node* next[26];
    Node* fail;
};
Node* root;
Node temp[maxn];
int tp;
void reset(Node* p)
{
    p->flag=0;p->id=tp-1;
    for(int i=0;i<26;i++) p->next[i]=NULL;
    p->fail=root;
    if(p==root) p->fail=NULL;
}
void init()
{
    tp=0;
    root=&temp[tp++];
    reset(root);
}
void insert(char* str)
{
    Node* p=root;
    for(int i=0;str[i];i++)
    {
        int x=str[i]-'a';
        if(p->next[x]==NULL)
        {
            p->next[x]=&temp[tp++];
            reset(p->next[x]);
        }
        p=p->next[x];
    }
    p->flag=1;
}
Node* que[maxn];
int front,rear;
void DFA()
{
    front=rear=0;
    que[rear++]=root;
    while(front<rear)
    {
        Node* t=que[front++];
        for(int i=0;i<26;i++)
        {
            Node* cnt=t->next[i];
            if(cnt!=NULL)
            {
                Node* fath=t->fail;
                while(fath!=NULL&&fath->next[i]==NULL)
                {
                    fath=fath->fail;
                }
                if(fath==NULL)
                {
                    cnt->fail=root;
                }
                else cnt->fail=fath->next[i];
                cnt->flag|=cnt->fail->flag;
                que[rear++]=cnt;
            }
        }
    }
}
double pet[26];
int n;
char str[maxn];
double a[1000][1000];
int equ,var;//浠0寮濮
void toMatrix()
{
    var=rear;
    equ=0;
    memset(a,0,sizeof(a));
    for(int i=0;i<rear;i++)
    {
        Node* p=&temp[i];
        if(p->flag)
        {
            a[equ][p->id]=1;
            a[equ++][var]=0;
            continue;
        }
        a[equ][p->id]=-1;
        a[equ][var]=-1;
        for(int j=0;j<26;j++)
        {
            Node* cnt=p->next[j];
            int k;
            if(cnt!=NULL)
            {
                k=cnt->id;
                a[equ][k]+=pet[j];
            }
            else
            {
                Node* fath=p->fail;
                while(fath!=NULL&&fath->next[j]==NULL)
                {
                    fath=fath->fail;
                }
                if(fath!=NULL)
                {
                    k=fath->next[j]->id;
                    a[equ][k]+=pet[j];
                }
                else
                {
                    k=0;
                    a[equ][0]+=pet[j];
                }
            }
        }
        equ++;
    }
}
const double eps=1e-10;
double x[1000];
void Gauss()
{
    for(int i=0;i<equ;i++)
    {
        int j;
        for(j=i;j<equ;j++)
        {
            if(fabs(a[j][i])>eps) break;
        }
        for(int k=i;k<=var;k++) swap(a[i][k],a[j][k]);
        for(j=i+1;j<equ;j++)
        {
            double p=-a[j][i]/a[i][i];
            for(int k=i;k<=var;k++) a[j][k]+=a[i][k]*p;
        }
    }
    for(int i=equ-1;i>=0;i--)
    {
        x[i]=a[i][var]/a[i][i];
        a[i][var]/=a[i][i];a[i][i]=1;
        for(int j=i-1;j>=0;j--)
        {
            a[j][var]+=-a[j][i]*a[i][var];
            a[j][i]=0;
        }
    }
}
int main()
{
    while(scanf("%d",&n)==1)
    {
        init();
        for(int i=0;i<26;i++) scanf("%lf",&pet[i]);
        int flag=0;
        for(int i=0;i<n;i++)
        {
            scanf("%s",str);
            insert(str);
            int f=1;
            for(int j=0;str[j];j++)
            {
                int x=str[j]-'a';
                if(fabs(pet[x])<eps)
                {
                    f=0;break;
                }
            }
            if(f) flag=1;
        }
        if(!flag)
        {
            printf("Infinity\n");
            continue;
        }
        DFA();
        toMatrix();
        Gauss();
        printf("%.6lf\n",x[0]);
    }
    return 0;
}
