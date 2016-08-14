#include<stdio.h>
#include<iostream>
#include<queue>
#include<cstdlib>
using namespace std;
int i,j,n,t,dist,pep,stat;
int way[35][35];
char req[5];
struct passeger
{
    int end;
    passeger *next;
}*p1,*p2;
void UP()
{
    int k;
    scanf("%d",&k);
    if(stat==k||pep==7)return ;
    if(p1==NULL){p1=new passeger;p1->end=k;p2=p1;pep++;p1->next=NULL;}
    else{p2->next=new passeger;p2=p2->next;p2->end=k;pep++;p2->next=NULL;}
}
void GO()
{
    int k,z;
    passeger *p,*q,*r;
    if(!pep)return ;
    k=p1->end;
    z=pep;
    p=p1;
    while(z--)
    {
        if(p->end==k)
        {
            if(p==p1)
            {
                p1=p->next;
                delete p;
                p=p1;
                pep--;
            }
            else
            {
                r=q->next;
                q->next=p->next;
                delete r;
                p=q->next;
                pep--;
            }
        }
        else q=p,p=p->next;
    }
    dist+=way[stat][k];
    stat=k;
    if(pep)
    {
        p=p1;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p2=p;
    }
    else p1=p2=NULL;
}
int main()
{
    while(scanf("%d",&n),n)
    {
        dist=0,stat=0,pep=0;
        p1=p2=NULL;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)scanf("%d",&way[i][j]);
        scanf("%d",&t);
        while(t--)
        {
            scanf("%s",req);
            if(req[0]=='U')UP();
            else GO();
        }
        printf("%d\n",dist);
        while(pep--)
        {
            p2=p1->next;
            delete p1;
            p1=p2;
        }
    }
    return 0;
}
