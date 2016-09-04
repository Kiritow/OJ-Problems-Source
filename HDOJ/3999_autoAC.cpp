#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node{
    int num;
    struct node *left;
    struct node *right;
}*tree;
int tot=0;
node *build(node *root,int num)
{
    if(root==NULL)
    {
        root=new node;
        root->left=NULL;
        root->right=NULL;
        root->num=num;
        return root;
    }
    else 
    {
        int t=root->num-num;;
        if(t>0)
            root->left=build(root->left,num);
        else 
            root->right=build(root->right,num);
        return root;
    }
}
bool first;
void visit(node *root)
{
    if(root!=NULL&&!first)
         printf(" %d",root->num);
    else 
    {
        first=false;
        printf("%d",root->num);
    }
}
void preorder(node *root)
{
    if(root!=NULL)
    {  
        visit(root);
        preorder(root->left);
        preorder(root->right);
    }
}
int main()
{
    int n,num;
    while(scanf("%d",&n)!=EOF)
    {
        first=true;
        int num;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&num);
            tree=build(tree,num);
        }
        preorder(tree);
        puts("");
    }
    return 0;
}
