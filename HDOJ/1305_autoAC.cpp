#include<stdio.h>
#include<malloc.h>
#include<string.h>
typedef struct Trie
{
    int v;
    Trie* next[2];
};
Trie* root;
void creatTrie(char str[])
{
    Trie* p=root,*q;
    int i;
    for(i=0;i<strlen(str);i++)
    {
        int id=str[i]-'0';
        if(p->next[id]==NULL)
        {
            q=(Trie*)malloc(sizeof(Trie));
            q->next[0]=q->next[1]=NULL;
            q->v=1;
            p->next[id]=q;
        }
        p=p->next[id];
    }
    p->v=-1;
}
int findTrie(char str[])
{
    Trie* p=root;
    for(int i=0;i<strlen(str);i++)
    {
        int id=str[i]-'0';
        if(i<strlen(str)-1)
        {
            if(p->next[id]->v==-1)
            {
                return 1;
            }
        }
        p=p->next[id];
    }
    return 0;
}
int main()
{
        char s[10][20];
        int c=1;
        while(scanf("%s",s[0])!=EOF)
        {
            root=(Trie*)malloc(sizeof(Trie));
            root->next[0]=NULL;
            root->next[1]=NULL;
            root->v=1;
            creatTrie(s[0]);
            int k=1;
            while(scanf("%s",s[k])!=EOF&&s[k][0]!='9')
            {
                creatTrie(s[k++]);
            }
            int i;
            for( i=0;i<k;i++)
            {
                int flag=findTrie(s[i]);
                if(flag)
                {
                    printf("Set %d is not immediately decodable\n",c++);
                    break;
                }
            }
            if(i>=k)
            {
                printf("Set %d is immediately decodable\n",c++);
            }
    }
    return 0;
}
