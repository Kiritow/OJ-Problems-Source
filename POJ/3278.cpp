#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>
using namespace std;

struct treenode
{
    int value;
    treenode *plus,*reduce,*add;
};

typedef struct treenode tree;

tree* root=NULL;

stack<tree*> bus;
stack<tree*> tmpbus;
stack<tree*> answerbus;

bool vis[100001];

int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    root=new (nothrow) tree;
    root->value=n;
    bus.push(root);
    int currentstep=-1;
    while(answerbus.empty())
    {
        ++currentstep;
        while(!bus.empty())
        {
            tree* father=bus.top();
            vis[father->value]=true;
            if(father->value==k)
            {
                answerbus.push(father);
                break;
            }
            bus.pop();
            int vplus=father->value*2,vreduce=father->value-1,vadd=father->value+1;
            if(vplus<100001&&!vis[vplus])
            {
                tree* node=new (nothrow) tree;
                node->value=vplus;
                father->plus=node;
                tmpbus.push(node);
            }
            if(vadd<100001&&!vis[vadd])
            {
                tree* node=new (nothrow) tree;
                node->value=vadd;
                father->add=node;
                tmpbus.push(node);
            }
            if(vreduce>-1&&!vis[vreduce])
            {
                tree* node=new (nothrow) tree;
                node->value=vreduce;
                father->reduce=node;
                tmpbus.push(node);
            }
        }
        while(!tmpbus.empty())
        {
            bus.push(tmpbus.top());
            tmpbus.pop();
        }
    }
    printf("%d\n",currentstep);
    return 0;
}
