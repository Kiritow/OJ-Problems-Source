#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
typedef struct TNode{
    struct TNode *left,*right;
    int shit;
}Node;
Node p;
Node *root=&p;
Node *newnode()
{
    Node *u=(Node*) malloc(sizeof(Node));
    u->left=NULL;
    u->right=NULL;
    u->shit=0;
    return u;
}
int addnode(char *s,int n)
{
    int fuck=0,i;
    Node *u=root;
    for(i=0;i<n;i++)
    {
        if(s[i]=='0')
        {
            if(u->left==NULL)
                u->left=newnode();
            u=u->left;
            if(u->shit==0)    {fuck=1;u->shit=1;}
        }
        else if(s[i]=='1')
        {
            if(u->right==NULL)
                u->right=newnode();
            u=u->right;
            if(u->shit==0)    {fuck=1;u->shit=1;}
        }
    }
    return fuck;
}
int min(int x,int y)
{
    if(x<=y)
        return x;
    return y;
}
int huiliyi(char *s,int n)
{
    int i,j,k,t;
    i=0;j=1;k=0;
    while(i<n&&j<n&&k<n)
    {
        t=s[(i+k)%n]-s[(j+k)%n];
        if(t==0) ++k;
        else
        {
        if(t<0) j=j+k+1;
        else
            i=i+k+1;
        k=0;
        if(i==j)    ++j;
        }
    }
    return min(i,j);
}
void remove(Node *u)
{
    if(u==NULL)    return;
    remove(u->left);
    remove(u->right);
    u->shit=0;
}
int main()
{
    int t,sum,n,x,i,j;
    char s[105],c[105];
    while(scanf("%d",&t)==1)
    {
        getchar();
        sum=0;
        while(t--)
        {
            scanf("%s",s);
            n=strlen(s);
            x=huiliyi(s,n);
            j=0;
            for(i=x;i<n;i++)
                c[j++]=s[i];
            for(i=0;i<x;i++)
                c[j++]=s[i];
            sum=sum+addnode(c,n);
        }
        printf("%d\n",sum);
        remove(root->left);
        remove(root->right);
    }
    return 0;
}
