#include<iostream>
#include<string>
#include<queue>
using namespace std;
typedef struct node
{
    int count;
    node* fail;
    node* next[26];
    node()
    {
        count=0;
        fail=NULL;
        for(int i=0;i<26;++i)
            next[i]=NULL;
    }
}*Pnode;
Pnode insert(Pnode root,string s)
{
    Pnode p=root;
    int len=s.size();
    for(int i=0;i<len;++i)
    {
        if(!p->next[s[i]-'a'])
            p->next[s[i]-'a']=new node();
        p=p->next[s[i]-'a'];
    }
    p->count++;
    return root;
}
void build_AC(Pnode root)
{
    Pnode p,temp;
    queue<Pnode> q;
    q.push(root);
    while(!q.empty())
    {
        p=q.front();
        q.pop();
        for(int i=0;i<26;++i)
            if(p->next[i])
            {
                if(p==root)
                    p->next[i]->fail=root;
                else
                {
                    temp=p->fail;
                    while(temp)
                    {
                        if(temp->next[i])
                        {
                            p->next[i]->fail=temp->next[i];
                            break;
                        }
                        temp=temp->fail;
                    }
                    if(!temp)
                        p->next[i]->fail=root;
                }
                q.push(p->next[i]);
            }
    }
}
int match(Pnode root,string s)
{
    int result=0,len=s.size();
    Pnode p=root,temp;
    for(int i=0;i<len;++i)
    {
        while(!p->next[s[i]-'a']&&p!=root)
            p=p->fail;
        p=p->next[s[i]-'a'];
        if(!p)
            p=root;
        temp=p;
        while(temp!=root&&temp->count!=-1)
        {
            result+=temp->count;
            temp->count=-1;
            temp=temp->fail;
        }
    }
    return result;
}
int main()
{
    int t,n;
    string keyword,s;
    Pnode root;
    cin>>t;
    while(t--)
    {
        root=new node();
        cin>>n;
        while(n--)
        {
            cin>>keyword;
            root=insert(root,keyword);
        }
        build_AC(root);
        cin>>s;
        cout<<match(root,s)<<endl;
    }
    return 0;
}
