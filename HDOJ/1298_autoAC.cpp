#include<iostream>
#include<algorithm>
#include<string>
#include<cstdio>
using namespace std;
struct node
{
    int count;
    struct node*next[26];
    int temp;
};
struct node*newnode()
{
    int i;
    struct node *r;
    r=new struct node;
    for(i=0;i<26;i++)
        r->next[i]=NULL;
    r->count=0;
    r->temp=0;
    return r;
}
void build(struct node *root,string str,int v)
{
    struct node*r,*s;
    int i;
    r=root;
    for(i=0;i<str.length();i++)
    {
        if(r->next[str[i]-'a']==NULL)
        {
            s=newnode();
            s->count=v;
            r->next[str[i]-'a']=s;
            r=s;
        }
        else
        {
           r=r->next[str[i]-'a'];
           r->count+=v;
        }
    }
    r->temp=1;
}
char tel[8][5]={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
struct pa
{
    char c;
    int sum;
};
int cmp(struct pa a,struct pa b)
{
    if(a.sum==b.sum)
        return a.c<b.c;
    return a.sum>b.sum;
}
char ans[105]="";
char temp[105]="";
int flag;
char sum[105];
void search(struct node*root,string str,int v)
{
    int i;
    struct node *r;
    r=root;
    if(v==str.length())
    {
        if(r->count>flag)
        {
            flag=r->count;
            sum[v]='\0';
            strcpy(ans,sum);
        }
      return ;
    }
    int t=0;
    struct pa a[4];
    int L=strlen(tel[str[v]-'2']);
    int k=0;
    for(i=0;i<L;i++)
    {
        if(r->next[tel[str[v]-'2'][i]-'a']!=NULL)
        {
            a[k].sum=r->next[tel[str[v]-'2'][i]-'a']->count;
            a[k].c=tel[str[v]-'2'][i];
            k++;
        }
    }
    sort(a,a+k,cmp);
    for(i=0;i<k;i++)
    {
            sum[v]=a[i].c;
            search(root->next[a[i].c-'a'],str,v+1);
    }
    return ;
}
int main()
{
    int T;
    cin>>T;
    for(int w=1;w<=T;w++)
    {
        printf("Scenario #%d:\n",w);
        int N;
        char p[105];
        struct node*root;
        root=newnode();
        cin>>N;
        while(N--)
        {
            int v;
            scanf("%s%d",p,&v);
            build(root,p,v);
        }
        int M;int L;
        cin>>M;
        int tag=0;
        while(M--)
        {
            scanf("%s",p);
            L=strlen(p);
            char q[105];
            int i;
            for(i=1;i<L;i++)
            {
                strcpy(q,p);
                q[i]='\0';
                flag=0;
                search(root,q,0);
                if(!flag)
                    printf("MANUALLY\n");
                else
                    puts(ans);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
