#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<vector>
using namespace std;
const int N = 210;
int n,num,m,dp[N][N],w[N],in[N];
char s[20110];
bool vis[N];
vector<int> g[N];
typedef struct node    
{    
    int cnt;    
    struct node *next[52];   
}*tree,Trie;    
tree root;  
inline int GetNum(char *t){  
    tree p = root,newnode;  
    for(int i = 0;i < strlen(t); ++i){  
        int u = t[i] - 'a';  
        if(u<0) u=t[i]-'A'+26;
        if(p->next[u]==NULL)  
        {     
            newnode=(tree)malloc(sizeof(Trie));  
            newnode->cnt=-1;  
            for(int j=0;j<52;j++)  
                newnode->next[j]=NULL;  
            p->next[u]=newnode;  
            p=newnode;  
        }  
        else 
        p = p->next[u];  
    }  
    if(p->cnt == -1)   
        p->cnt = num ++;  
    return p->cnt;  
}  
void init()
{
    root=(tree)malloc(sizeof(Trie));  
    root->cnt=-1; 
    for(int j=0;j<52;j++)  
        root->next[j]=NULL; 
    num=1;
    memset(in,0,sizeof(in));
    for(int i=0;i<=n;i++)
        g[i].clear();
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            dp[i][j]=INT_MAX;
}
int dfs(int u)
{
    int size=g[u].size();
    dp[u][0]=0;
    int t=0;
    for(int i=0;i<size;i++)
    {
        int v=g[u][i];
        int now=dfs(v);
        for(int j=t;j>=0;j--)
        {
            for(int k=0;k<=now;k++)
                dp[u][j+k]=min(dp[u][j+k],dp[u][j]+dp[v][k]);
        }
        t+=now;
    }
    for(int i=1;i<=t+1;i++)
        dp[u][i]=min(dp[u][i],w[u]);
    return t+1;
}
int main()
{
    char str[100],c[110];
    while(scanf("%s",str)==1)
    {
        if(strcmp(str,"#")==0)
            break;
        n=atoi(str);
        scanf("%d",&m);
        getchar();
        init();
        for(int i=0;i<n;i++)
        {
            gets(s);
            int len=strlen(s),cc=0,t=0,a,b;
            for(int j=0;j<=len;j++)
            {
                if(s[j]!=' ' && s[j]!='\0')
                  c[t++]=s[j];
                if(s[j]==' '||s[j]=='\0')
                {
                    cc++;
                    c[t]='\0';
                    t=0;
                    if(cc==1)
                        a=GetNum(c);
                    else if(cc==2)
                        w[a]=atoi(c);
                    else {
                        b=GetNum(c);
                        g[a].push_back(b);
                        in[b]++;
                    }
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(in[i]==0)
                g[0].push_back(i);
        }
        w[0]=INT_MAX;
        dfs(0);
        printf("%d\n",dp[0][m]);
    }
    return 0;
}
