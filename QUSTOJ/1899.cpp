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
};

btree _node;
btree* root=&_node;

int counter=0;

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
        n->l=new btree;
        deal(n->l);
        n->r=new btree;
        deal(n->r);
        if(n->l->v=='#'&&n->r->v=='#') ++counter;
    }
}

int main()
{
    deal(root);
    printf("%d\n",counter);
    return 0;
}
