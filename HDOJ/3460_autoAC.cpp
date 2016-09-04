#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct dic
{
    struct dic *child[26];
};
struct dic *root;
int max;
int ans;
void insert(char *source)
{
    struct dic *now,*newnode;
    int i,j;
    int len;
    len=strlen(source);
    max=max>len?max:len;
    now=root;
    for(i=0;i<len;i++)
    {
        if(now->child[source[i]-'a']!=NULL)    now=now->child[source[i]-'a'];
        else
        {
            newnode=(struct dic*)malloc(sizeof(struct dic));
            for(j=0;j<26;j++)    newnode->child[j]=NULL;
            now->child[source[i]-'a']=newnode;
            now=newnode;
        }
    }
}
void count(struct dic *now)
{
    int j;
    for(j=0;j<26;j++)
    {
        if(now->child[j]==NULL)    continue;
        else
        {
            ans++;
            count(now->child[j]);
        }
    }
}
int main()
{
    int n;
    int i,j;
    char str[55];
    while(scanf("%d",&n)!=-1)
    {
        root=(struct dic *)malloc(sizeof(struct dic));
        for(j=0;j<26;j++)    root->child[j]=0;
        max=0;
        for(i=0;i<n;i++)
        {
            scanf("%s",str);
            insert(str);
        }
        ans=0;
        count(root);
        ans*=2;
        ans-=max;
        ans+=n;
        printf("%d\n",ans);
    }
    return 0;
}
