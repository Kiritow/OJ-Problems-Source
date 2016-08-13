#include <iostream>
#include <cstring>
using namespace std;

class node
{
public:
    node* next[26];
    bool value;
    node() : value(false)
    {
        memset(next,0,sizeof(next));
    }
};
node _headnode;
node* head=&_headnode;

void insert(const char* str)
{
    int L=strlen(str);
    node* p=head;
    for(int i=0;i<L;i++)
    {
        if(p->next[str[i]-'a']==nullptr)
        {
            p->next[str[i]-'a']=new node;
        }
        p=p->next[str[i]-'a'];
    }
    p->value=true;
}

bool search(const char* str)
{
    int L=strlen(str);
    node* p=head;

    for(int i=0;i<L;i++)
    {
        if(p->next[str[i]-'a']!=nullptr)
        {
            p=p->next[str[i]-'a'];
            if(p->value)
            {
                bool isFound=true;
                node* q=head;
                for(int j=i+1;j<L;j++)
                {
                    if(q->next[str[j]-'a']!=nullptr)
                    {
                        q=q->next[str[j]-'a'];
                    }
                    else
                    {
                        isFound=false;
                        break;
                    }
                }
                if(isFound)
                {
                    if(q->value)
                    {
                        return true;
                    }
                }
            }
        }
        else
        {
            break;
        }
    }

    return false;
}

#define MAXN 50005
#define MAXLEN 1005
char input[MAXN][MAXLEN];




int main()
{
    int i=0;
    while(cin>>input[i])
    {
        insert(input[i++]);
    }
    for(int ci=0;ci<i;ci++)
    {
        if(search(input[ci]))
        {
            cout<<input[ci]<<endl;
        }
    }

    return 0;
}
