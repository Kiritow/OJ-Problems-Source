#include<cstdio>
#include<iostream>
#include<cstring>
#define L x->c[0]
#define R x->c[1]
#define KT root->c[1]->c[0]
using namespace std;
const int maxn = 300010;
const int inf = 1000000007;
int n,Type;
int gcd(int a,int b)
{
    if(a<0||a>=inf) return b;
    if(b<0||b>=inf) return a;
    return b == 0?a:gcd(b,a%b);
}
struct Node
{
    struct Node *c[2],*fa;
    int id,size,g,val,who;
}S[maxn],*null = &S[0];
Node* Q[maxn];
Node* ID[maxn];
int scnt;
struct snode
{
    int type;
    Node*root;
    inline Node *NewNode(int value,Node *p)
    {
        Node *e = S+(++scnt);
        e->val = value;
        e->id = scnt;
        e->size = 1;
        e->fa = p;
        e->g = value;
        e->c[0] = e->c[1] = null;
        ID[scnt] = e;
        return e;
    }
    inline void Update(Node *p)
    {
        p->size = p->c[0]->size+p->c[1]->size+1;
        p->g = gcd(p->c[0]->g,p->c[1]->g);
        p->g = gcd(p->val,p->g);
    }
    inline void Rotate(Node *x,int k)
    {
        Node *y=x->fa;
        y->c[k]=x->c[!k];
        y->c[k]->fa=y;
        x->fa=y->fa;
        if(y->fa->c[0]==y)
            y->fa->c[0]=x;
        else
            y->fa->c[1]=x;
        y->fa=x;
        x->c[!k]=y;
        Update(y);
        Update(x);
        if(root==y) root=x;
    }
    inline void Splay(Node *x,Node *y)
    {
        while(x->fa!=y)
        {
            if(x->fa->fa==y)
            {
                if(x->fa->c[0]==x)
                    Rotate(x,0);
                else
                    Rotate(x,1);
            }
            else if(x->fa->fa->c[0]==x->fa)
            {
                if(x->fa->c[0]==x)
                    Rotate(x->fa,0),Rotate(x,0);
                else
                    Rotate(x,1),Rotate(x,0);
            }
            else
            {
                if(x->fa->c[1]==x)
                    Rotate(x->fa,1),Rotate(x,1);
                else
                    Rotate(x,0),Rotate(x,1);
            }
        }
        Update(x);
    }
    inline void Select(int k,Node *y)
    {
        Node *x=root;
        while(k!=x->c[0]->size+1)
        {
            if(k<=x->c[0]->size)
                x=x->c[0];
            else
            {
                k-=x->c[0]->size+1;
                x=x->c[1];
            }
        }
        Splay(x,y);
    }
    inline void Init(int v)
    {
        root = NewNode(v,null);
        type = ++Type;
        root->who = type;
    }
    inline void Delete(Node *x)
    {
        Splay(x,null);
        Node *t = root;
        if(t->c[1]!=null)
        {
            root = t->c[1];
            Select(1,null);
            root->c[0] = t->c[0];
            if(root->c[0]!=null)
                root->c[0]->fa = root;
        }
        else
        {
            root = t->c[0];
        }
        root->fa = null;
        if(root!=null)Update(root);
    }
    inline void Insert(Node *x)
    {
        x->c[0] = x->c[1] = null;
        insert(root,x);
        Splay(x,null);
        x->who = type;
    }
    inline void insert(Node* &x,Node* y)
    {
        if(x == null)
        {
            x = y;
            return;
        }
        if(y->val<=x->val)
        {
            insert(x->c[0],y);
            x->c[0]->fa = x;
        }
        else
        {
            insert(x->c[1],y);
            x->c[1]->fa = x;
        }
        Update(x);
    }
    inline void Change(Node* tmp,int v)
    {
        Delete(tmp);
        tmp->val = v;
        Insert(tmp);
    }
    inline Node *FindSucc(Node *x,int v,int opt)
    {
        if(x == null)return x;
        if(x->val == v&&opt)return x;
        else if(x->val>v)
        {
            Node *tmp = FindSucc(x->c[0],v,opt);
            return tmp == null?x:tmp;
        }
        else
        {
            return FindSucc(x->c[1],v,opt);
        }
    }
    inline Node *FindSucc(int v,int opt)
    {
        Node *tmp = FindSucc(root,v,opt);
        Splay(tmp,null);
        return tmp;
    }
    inline Node *FindPre(Node *x,int v)
    {
        if(x == null)return x;
        if(x->val<v)
        {
            Node *tmp = FindPre(x->c[1],v);
            return tmp == null?x:tmp;
        }
        else return FindPre(x->c[0],v);
    }
    inline Node *FindPre(int v)
    {
        Node* tmp = FindPre(root,v);
        Splay(tmp,null);
        return tmp;
    }
    inline void Merge(snode &tree)
    {
        int head,tail;
        head = tail = 0;
        tree.Select(1,null);
        tree.Select(tree.root->size,tree.root);
        Q[++tail] = tree.KT;
        while(head<tail)
        {
            Node* f = Q[++head];
            if(f->c[0]!=null)Q[++tail] = f->c[0];
            if(f->c[1]!=null)Q[++tail] = f->c[1];
            Insert(f);
            f->who = type;
        }
        tree.KT = null;
        tree.Update(tree.root->c[1]);
        tree.Update(tree.root);
    }
    inline int SolveTri()
    {
        if(root->size<=4)return root->size-2;
        Select(2,null);
        int a = root->val;
        Select(3,null);
        int b = root->val;
        int ans = 2;
        while(true)
        {
            if(a+b>=inf)break;
            int c = FindSucc(a+b,1)->val;
            if(c>=inf||c == -1)break;
            a = b;
            b = c;
            ans++;
        }
        return ans;
    }
    inline int SolveGcd(int l,int r)
    {
        Node *pre = FindPre(l);
        Node *succ = FindSucc(r,0);
        Splay(pre,null);
        Splay(succ,root);
        return KT->g;
    }
    void vist(Node *x)
    {
        if(x != null)
        {
            printf("root %2d:  left-son: %2d    right-son: %2d  size:%2d val=%2d   gcd: %2d\n",x->id,x->c[0]->id,x->c[1]->id,x->size,x->val,x->g);
            vist(x->c[0]);
            vist(x->c[1]);
        }
    }
}spt[maxn];
void prepare()
{
    null->id = 0;
    null->c[0] = null->c[1] = null->fa = NULL;
    null->size = null->val = 0;
    null->g = -1;
    Type = 0;
    scnt = 0;
}
int main()
{
    int t,n,m,a,u,v,op,l,r,x,cas = 1;
    scanf("%d",&t);
    while(t--)
    {
        prepare();
        printf("Case #%d:\n",cas++);
        scanf("%d%d",&n,&m);
        for(int i = 1;i<=n;i++)
        {
            spt[i].Init(-1);
            Node *tmp = spt[i].NewNode(inf,null);
            spt[i].Insert(tmp);
        }
        for(int i = 1;i<=n;i++)
        {
            scanf("%d",&a);
            Node *tmp = spt[i].NewNode(a,null);
            spt[i].Insert(tmp);
        }
        int tot = 0;
        while(m--)
        {
            scanf("%d",&op);
            if(op == 1)
            {
                scanf("%d%d",&u,&v);
                Node *t1 = ID[u+2*n];
                Node *t2 = ID[v+2*n];
                int tree1 = t1->who;
                int tree2 = t2->who;
                if(tree1 == tree2)continue;
                int size1 = spt[tree1].root->size;
                int size2 = spt[tree2].root->size;
                if(size1>size2)spt[tree1].Merge(spt[tree2]);
                else spt[tree2].Merge(spt[tree1]);
            }
            else if(op == 2)
            {
                scanf("%d%d",&u,&v);
                Node *t1 = ID[u+2*n];
                Node *t2 = ID[v+2*n];
                int tree1 = t1->who;
                int tree2 = t2->who;
                spt[tree1].Delete(t1);
                spt[tree2].Insert(t1);
            }
            else if(op == 3)
            {
                scanf("%d%d",&u,&x);
                Node *tmp = ID[u+2*n];
                int tree = tmp->who;
                spt[tree].Change(tmp,x);
            }
            else if(op == 4)
            {
                scanf("%d",&u);
                Node *tmp = ID[u+2*n];
                int tree = tmp->who;
                printf("%d\n",spt[tree].SolveTri());
            }
            else
            {
                scanf("%d%d%d",&u,&l,&r);
                Node *tmp = ID[u+2*n];
                int tree = tmp->who;
                printf("%d\n",spt[tree].SolveGcd(l,r));
            }
        }
    }
    return 0;
}
