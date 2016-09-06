#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
const int N=10;
int f1[65],f2[65],f3[65];
class Trie
{
    public:
       int v;
       int flag;
       Trie *next[N];
       Trie()
       {
           v=-1;
           memset(next,NULL,sizeof(next));
       }
};
Trie *root;
void Insert(char *S,int ans)
{
    int len=strlen(S);
    Trie *p=root;
    for(int i=0;i<len;i++)
    {
        int id=S[i]-'0';
        if(p->next[id]==NULL)
            p->next[id]=new Trie();
        p=p->next[id];
        if(p->v<0) p->v=ans;
    }
}
int Find(char *S)
{
    Trie *p=root;
    int count;
    int len=strlen(S);
    for(int i=0;i<len;i++)
    {
        int id=S[i]-'0';
        p=p->next[id];
        if(p==NULL) return -1;
        else  count=p->v;
    }
    return count;
}
void Init()
{
    int h;
    char str[65]="1";
    memset(f1,0,sizeof(f1));
    memset(f2,0,sizeof(f2));
    memset(f3,0,sizeof(f3));
    f1[0]=1;f2[0]=1;
    Insert(str,0);
    for(int i=2;i<100000;i++)
    {
        memset(str,0,sizeof(str));
        int r=0;
        for(int j=0;j<60;j++)
        {
            f3[j]=f1[j]+f2[j]+r;
            r=f3[j]/10;
            f3[j]%=10;
        }
        for(int j=59;j>=0;j--)
        if(f3[j])
        {
            h=j;
            break;
        }
        int k=0;
        for(int j=h;j>=0;j--)
        {
            str[k++]=f3[j]+'0';
            if(k>=40) break;
        }
        Insert(str,i);
        if(h>55)
        {
            for(int j=1;j<59;j++)
                f3[j-1]=f3[j];
            for(int j=1;j<59;j++)
                f2[j-1]=f2[j];
        }
        for(int j=0;j<60;j++)
            f1[j]=f2[j];
        for(int j=0;j<60;j++)
            f2[j]=f3[j];
    }
}
int main()
{
    root=new Trie();
    Init();
    char str[105];
    int t,i,j,k=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",str);
        printf("Case #%d: ",k++);
        int tmp=Find(str);
        printf("%d\n",tmp);
    }
    return 0;
}
