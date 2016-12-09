#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <queue>
using namespace std;

struct btree
{
    btree* l;
    btree* r;
    char v;
};

btree _node;
btree* root=&_node;

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
    }
}
void NLR(btree* n)
{
    if(n->v!='#')
    {
        printf("%c ",n->v);
        if(n->l) NLR(n->l);
        if(n->r) NLR(n->r);
    }
}
void LNR(btree* n)
{
    if(n->v!='#')
    {
        if(n->l) LNR(n->l);
        printf("%c ",n->v);
        if(n->r) LNR(n->r);
    }
}

void LRN(btree* n)
{
    if(n->v!='#')
    {
        if(n->l) LRN(n->l);
        if(n->r) LRN(n->r);
        printf("%c ",n->v);
    }
}

void LEVEL(btree* n)
{
    queue<btree*> bus;
    bus.push(n);

    while(!bus.empty())
    {
        btree* p=bus.front();
        bus.pop();
        if(p->v!='#') printf("%c ",p->v);
        if(p->l) bus.push(p->l);
        if(p->r) bus.push(p->r);
    }
}

int main()
{
    deal(root);
    printf("Preorder:");
    NLR(root);
    printf("\nInorder:");
    LNR(root);
    printf("\nPostorder:");
    LRN(root);
    printf("\nLevelorder:");
    LEVEL(root);
    printf("\n");
    return 0;
}
