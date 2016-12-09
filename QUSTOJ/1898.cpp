#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

struct btree
{
    btree* l;
    btree* r;
    char v;
    int depth;
};

btree _node;
btree* root=&_node;
int maxdepth=0;

void deal(btree* n)
{
    scanf("%c",&n->v);
    if(n->v=='#')
    {
        n->l=n->r=NULL;
        return ;
    }
    else
    {
        maxdepth=max(n->depth,maxdepth);
        n->l=new btree;
        n->l->depth=n->depth+1;
        deal(n->l);
        n->r=new btree;
        n->r->depth=n->depth+1;
        deal(n->r);
    }
}

int main()
{
    root->depth=1;
    deal(root);
    printf("%d\n",maxdepth);
    return 0;
}
