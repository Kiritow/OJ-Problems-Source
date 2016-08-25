#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
struct node
{
    int id;   
    int cnt;
    int al[26];
};
int ptr=0;
node word[1000000];
void Init(int z)
{     
    for(int i=0;i<26;i++)
        word[z].al[i]=-1;      
}      
void Insert(char*s,int len,int x)
{
    int now=0;
    for(int i=0;i<len;i++)  
    {
        if(word[now].al[s[i]-'a']==-1)
        {
            word[now].al[s[i]-'a']=++ptr;
            Init(ptr); now=ptr;
        }
        else now=word[now].al[s[i]-'a'];
        if(word[now].id!=x) word[now].cnt++;
        //cout<<now<<endl;
        word[now].id=x;
    }
}
int find(char*s)
{
    int now=0;
    int len=strlen(s);
    for(int i=0;i<len;i++)
    {
        if(word[now].al[s[i]-'a']==-1)
            return 0;
        now=word[now].al[s[i]-'a'];
    }
    return word[now].cnt;
}
int main()
{
    int n,m,len;
    char s[21];
    Init(0);
    scanf("%d",&n);
    while(n--)
    {      
        scanf("%s",&s);
        len=strlen(s);
        for(int i=0;i<len;i++)
            Insert(s+i,len-i,n+1);
    }
    scanf("%d",&m);
    while(m--)
    {
        scanf("%s",&s);
        printf("%d\n",find(s));
    }                            
    return 0;
}
