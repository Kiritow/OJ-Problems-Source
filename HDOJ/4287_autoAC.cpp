#include<stdio.h>
#include<string.h>
int hash[128];
struct TrieNode{
    int no;
    TrieNode *next[10];
}node[30005];
TrieNode *root = &node[0];
int cnt,result[5005];
char word[10],s[10];
void init()
{
    hash['a']=hash['b']=hash['c']=2;
    hash['d']=hash['e']=hash['f']=3;
    hash['g']=hash['h']=hash['i']=4;
    hash['j']=hash['k']=hash['l']=5;
    hash['m']=hash['n']=hash['o']=6;
    hash['p']=hash['q']=hash['r']=hash['s']=7;
    hash['t']=hash['u']=hash['v']=8;
    hash['w']=hash['x']=hash['y']=hash['z']=9;
}
void initRoot()
{
    int i;
    for(i=0;i<10;i++)
    {
        root->next[i]=NULL;
    }
}
void insert(char str[],int num)
{
    TrieNode *p = root;
    int len=strlen(str),i,j;
    for(i=0;i<len;i++)
    {
        if(p->next[str[i]-'0']==NULL)
        {
            p->next[str[i]-'0']=&node[cnt];
            for(j=0;j<10;j++)node[cnt].next[j]=NULL;
            node[cnt].no=-1;
            cnt++;
        }
        p=p->next[str[i]-'0'];
    }
    p->no=num;
}
void query(char str[])
{
    int len=strlen(str),i;
    TrieNode *p=root;
    for(i=0;i<len;i++)
    {
        p=p->next[hash[str[i]]];
        if(p==NULL)break;
    }
    if(p==NULL)return;
    else{
        if(p->no!=-1)result[p->no]++;
    }
}
int main()
{
    int t,m,n,i;
    scanf("%d",&t);
    init();
    while(t--)
    {
        cnt=1;
        initRoot();
        memset(result,0,sizeof(result));
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
        {
            scanf("%s",word);
            insert(word,i);
        }
        for(i=0;i<m;i++)
        {
            scanf("%s",s);
            query(s);
        }
        for(i=0;i<n;i++)
        {
            printf("%d\n",result[i]);
        }
    }
    return 0;
}
