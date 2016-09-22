#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

char buff[1024];
struct node
{
    node* next[26];
    //int flag;/// If this is the end of some word
    int step;/// Depth.
};
node _root;
node* root=&_root;
int main()
{
    int maxstep=0;
    int n;
    scanf("%d%*c",&n);
    for(int i=0;i<n;i++)
    {
        gets(buff);
        int L=strlen(buff);
        node* p=root;
        for(int j=0;j<L;j++)
        {
            if(p->next[buff[j]-'a'])
            {
                p=p->next[buff[j]-'a'];
            }
            else
            {
                node* q=new node;
                memset(q,0,sizeof(node));
                q->step=p->step;
                p->next[buff[j]-'a']=q;
                p=q;
            }
        }
        p->step++;
        maxstep=max(maxstep,p->step);
    }

    printf("%d\n",maxstep);
    return 0;
}
