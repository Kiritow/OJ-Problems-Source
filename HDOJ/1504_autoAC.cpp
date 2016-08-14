#include<stdio.h>
#include<string.h>
struct node{  
    node *child;
    node *brother;
    char key[10]; 
};
int n,m;
node *root;
void getname(char *str,char *key,int &j)
{
    int i;
    for(i=0;str[j]!='\0'&&str[j]!='\\';i++,j++)
        key[i]=str[j];
    key[i]='\0';
}
node *insert(node *parent,char *key)
{
    node *p,*q,*t;
    if(!parent->child||strcmp(parent->child->key,key)>0)
    {
        t=new node;
        strcpy(t->key,key);
        t->child=NULL;
        t->brother=parent->child;
        parent->child=t;
        return t;
    }
    if(strcmp(parent->child->key,key)==0)
        return parent->child;
    for(p=parent->child,q=p->brother;q&&strcmp(q->key,key)<0;p=q,q=q->brother);
    if(!q||strcmp(q->key,key)>0)
    {
        t=new node;
        strcpy(t->key,key);
        t->brother=p->brother;
        p->brother=t;
        t->child=NULL;
        return t;
    }
    return q;
}
void read()
{
    char str[90],key[9];
    int i,cur;
    node *p;
    root=new node;
    root->child=NULL;
    scanf("%d",&n);
    for(i=m=0;i<n;i++)
    {
        cur=0;
        scanf("%s",str);
        getname(str,key,cur);
        for(p=insert(root,key);str[cur]!='\0';)
        {
            getname(str,key,++cur);
            p=insert(p,key);
        }
    }
}
void find(node *p,int k)
{
    int i;
    for(;p;p=p->brother)
    {
        for(i=0;i<k;i++)
            putchar(' ');
        puts(p->key);
        if(p->child)
            find(p->child,k+1);
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        read();
        find(root->child,0);
        if(t)
            printf("\n");
    }
    return 0;
}
