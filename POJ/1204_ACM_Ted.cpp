#include<cstdio>
#include<cstring>
using namespace std;
struct node
{
    node *next[26];
    int id;
    node()
    {
        memset(next,0,sizeof(next));
        id=0;
    }
}*head;
int dir[][2]={-1,0,-1,1,0,1,1,1,1,0,1,-1,0,-1,-1,-1};//方向
char mat[1005][1005];//地图
char s[1005];
int out[1005][3];
int cnt,x,y;
int n,m,w;
void build(char *s,node *head,int id)//建树
{
    int len=strlen(s),k;
    for(int i=0;i<len;++i)
    {
        k=s[i]-'A';
        if(head->next[k]==NULL)
           head->next[k]=new node();
        head=head->next[k];
    }
    head->id=id;
}
void dfs(node *p,int a,int b,int c)//深搜
{
    if(p==NULL) return;
    if(p->id>0)
    {
        out[p->id][0]=x;out[p->id][1]=y;out[p->id][2]=c;
        p->id=0;
        //这里不能return
    }
    if(a<0||n<=a||b<0||m<=b) return;
    dfs(p->next[mat[a][b]-'A'],a+dir[c][0],b+dir[c][1],c);
}
int main()
{
    head=new node();
    node *p;
    scanf("%d%d%d",&n,&m,&w);
    //输入地图
    for(int i=0;i<n;++i)
        scanf("%s",mat[i]);
    for(int i=1;i<=w;++i)
    {
        scanf("%s",s);
        build(s,head,i);
    }
    //枚举地图上每个点
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            for(int k=0;k<8;++k)
            {
                x=i;y=j;
                p=head;
                dfs(p,i,j,k);
            }
    //输出
    for(int i=1;i<=w;++i)
        printf("%d %d %c\n",out[i][0],out[i][1],out[i][2]+'A');
    return 0;
}
