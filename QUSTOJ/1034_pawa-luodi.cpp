#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAX 100010
#define _MAX 50010
using namespace std;

struct ComplexAsk{
    int l,r,k;
    int from;
    bool operator <(const ComplexAsk& a)const{
        return l<a.l;
    } 
}asks[_MAX];
struct Complex{
    int random,val,cnt,size;
    Complex* son[2];
    Complex(){
        random=rand();
        cnt=size=1;
        son[0]=son[1]=NULL;
    }
    inline void Maintain(){
        size=cnt;
        if(son[0]!=NULL)    size+=son[0]->size;
        if(son[1]!=NULL)    size+=son[1]->size;
    }
    inline int Compare(int x){
        if(x==val)  return -1;
        return x>val;
    }
}*root;

int total,step;
int source[MAX];
int ans[_MAX];

inline void Rotate(Complex*& a,int dir);
void Insert(Complex*& a,int x);
void Delete(Complex*& a,int x);
int FindK(Complex*& a,int k);

int main()
{
    cin>>total>>step;
    for(int i=1;i<=total;i++)
        scanf("%d",&source[i]);
    for(int i=1;i<=step;i++)
        scanf("%d%d%d",&asks[i].l,&asks[i].r,&asks[i].k),asks[i].from=i;
    sort(asks+1,asks+step+1);
    for(int i=1;i<=step;i++){
        if(asks[i-1].r>=asks[i].l){
            for(int j=asks[i-1].l;j<asks[i].l;j++)
                Delete(root,source[j]);
            for(int j=asks[i-1].r+1;j<=asks[i].r;j++)
                Insert(root,source[j]);
        }
        else{
            if(i-1)
                for(int j=asks[i-1].l;j<=asks[i-1].r;j++)
                    Delete(root,source[j]);
            for(int j=asks[i].l;j<=asks[i].r;j++)
                Insert(root,source[j]);
        }
        ans[asks[i].from]=FindK(root,asks[i].k);
    }
    for(int i=1;i<=step;i++)
        printf("%d\n",ans[i]);
    return 0;
}

inline void Rotate(Complex*& a,int dir)
{
    Complex* k=a->son[dir^1];
    a->son[dir^1]=k->son[dir];
    k->son[dir]=a;
    a->Maintain(),k->Maintain();
    a=k;
}

void Insert(Complex*& a,int x)
{
    if(a==NULL){
        a=new Complex();
        a->val=x;
        return ;
    }
    int dir=a->Compare(x);
    if(dir==-1)
        a->cnt++;
    else{
        Insert(a->son[dir],x);
        if(a->son[dir]->random > a->random)
            Rotate(a,dir^1);
    }
    a->Maintain();
}

void Delete(Complex*& a,int x)
{
    int dir=a->Compare(x);
    if(dir!=-1)
        Delete(a->son[dir],x);
    else{
        if(a->cnt > 1)
            a->cnt--;
        else{
            if(a->son[0]==NULL)
                a=a->son[1];
            else if(a->son[1]==NULL)
                a=a->son[0];
            else{
                int _dir=(a->son[0]->random > a->son[1]->random);
                Rotate(a,_dir);
                Delete(a->son[_dir],x);
            }
        }
    }
    if(a!=NULL) a->Maintain();
}

int FindK(Complex*& a,int k)
{
    int t=0;
    if(a->son[0]!=NULL)
        t=a->son[0]->size;
    if(k<=t)
        return FindK(a->son[0],k);
    if(k>t+a->cnt)
        return FindK(a->son[1],k-t-a->cnt);
    return a->val;
}
