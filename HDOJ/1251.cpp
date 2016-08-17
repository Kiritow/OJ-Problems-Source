/// HDU 1251
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

struct node
{
    node* next[26];
    int val;
    node(){val=0;memset(next,0,sizeof(next));}
};
char buffer[1024];
node _root;
node* root=&_root;
int main()
{
    while(gets(buffer))
    {
        if(strlen(buffer)<1)
        {
            break;
        }
        char* p=buffer;
        node* np=root;
        while(*p!=0)
        {
            if(np->next[*p-'a']==NULL) np->next[*p-'a']=new node;
            np=np->next[*p-'a'];
            p++;
            np->val++;
        }
    }
    while(gets(buffer))
    {
        char* p=buffer;
        node* np=root;
        bool undone=true;
        while(*p!=0)
        {
            if(np->next[*p-'a']==NULL)
            {
                printf("0\n");undone=false;break;
            }
            np=np->next[*p-'a'];
            p++;
        }
        if(undone)
        {
            printf("%d\n",np->val);
        }
    }
    return 0;
}

