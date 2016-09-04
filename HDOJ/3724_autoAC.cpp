#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
struct dictree{
    int num;
    dictree *child[30];
};
dictree *root;
int ans;
struct node
{
    double val;
    int iid;
}p[8];
void insert(char *s){
    int len,i,j;
    dictree *current,*newnode;
    len=strlen(s);
    current=root;
    for(i=0;i<len;i++){
        if(current->child[s[i]-'a']!=0){
            current=current->child[s[i]-'a'];
            current->num++;
        }
        else{
            newnode=(struct dictree *)malloc(sizeof(struct dictree));
            for(j=0;j<=26;j++){
                newnode->child[j]=NULL;
            }
            newnode->num=1;
            current->child[s[i]-'a']=newnode;
            current=current->child[s[i]-'a'];
        }
    }
    return;
}
void search(char *s){
    dictree *current;
    int i,j,len;
    current=root;
    len=strlen(s);
    for(i=0;i<len;i++){
        if(current->child[s[i]-'a']!=0){
            current=current->child[s[i]-'a'];
        }
        else{
            return;
        }
    }
    ans+=current->num;
}
int cmp(node a,node b)
{
    if(a.val==b.val)return a.iid<b.iid;
    return a.val<b.val;
}
int pow(int x){
    int ans,i;
    ans=1;
    for(i=1;i<=x;i++)ans*=2;
    return ans;
}
int main()
{
    double key=105.0/95;
    int n,m,i,j,asc;
    char s[120],s1[120];
    while(scanf("%d%d",&n,&m)!=EOF){
        root=(struct dictree *)malloc(sizeof(struct dictree));
        for(i=0;i<=26;i++)root->child[i]=0;
        root->num=0;
        for(i=1;i<=n;i++){
            scanf("%s",s);
            insert(s);
        }
        ans=0;
        int k,t;
        for(i=1;i<=m;i++)
        {
            scanf("%d",&k);
            for(j=0;j<k;j++)
            {
                int kk=0;
                for(t=0;t<8;t++)
                {
                    scanf("%lf",&p[t].val);
                    p[t].iid=7-t;
                }
                int pp,qq;node tem;
                for(pp=0;pp<7;pp++)
                for(qq=pp+1;qq<8;qq++)
                    if(p[pp].val>p[qq].val){
                        tem=p[pp];
                        p[pp]=p[qq];
                        p[qq]=tem;
                    }
                int tto=1;
                while(p[tto].val/p[tto-1].val<=key)tto++;
                asc=0;
                for(t=tto;t<8;t++){
                    asc+=pow(p[t].iid); 
                }
                s1[j]=asc;
            }
            s1[k]='\0';
            search(s1);
        }
        printf("%d\n",ans);
    }
    return 0;
}
