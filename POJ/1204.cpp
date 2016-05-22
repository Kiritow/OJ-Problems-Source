#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXC=1005;
const int MAXL=1005;
const int MAXW=1005;
#define nullptr NULL
//#define ISDEBUG

#ifdef ISDEBUG
#define dprintf(format,args...) printf(format,##args)
#define dsystem(cmd) system(cmd)
#else
#define dprintf(format,args...)
#define dsystem(cmd)
#endif // ISDEBUG
char map[MAXL][MAXC];
char word[MAXW];
int ans[MAXW][3];
int L,C,W;

int direction[8][2];

inline void initdirection()
{
    /// ..[..][0] +-Y   ..[..][1] +-X
    direction[0][0]=-1;
    direction[0][1]=0;

    direction[1][0]=-1;
    direction[1][1]=+1;

    direction[2][0]=0;
    direction[2][1]=+1;

    direction[3][0]=+1;
    direction[3][1]=+1;

    direction[4][0]=+1;
    direction[4][1]=0;

    direction[5][0]=+1;
    direction[5][1]=-1;

    direction[6][0]=0;
    direction[6][1]=-1;

    direction[7][0]=-1;
    direction[7][1]=-1;
}

struct node
{
    node* next[26];
    int wid;
};

node _root;
node* root=&_root;

void display_tree(int step,node* ptr)
{
    for(int i=0;i<26;i++)
    {
        if(ptr->next[i]!=nullptr)
        {
            for(int i=0;i<step;i++)
            {
                printf("\t");
            }
            printf("%c\n",i+'A');
            display_tree(step+1,ptr->next[i]);
        }
    }
}

void printtree()
{
    for(int i=0;i<26;i++)
    {
        if(root->next[i]!=nullptr)
        {
            printf("%c\n",i+'A');
            display_tree(1,root->next[i]);
        }
    }
}

void dfs(node* ptr,int starty,int startx,int y,int x,int dir)
{
    dprintf("In DFS: %d %d Dir=%d\n",y,x,dir);
    if(ptr==nullptr)
    {
        dprintf("Null Pointer.\n");
        return;
    }

    if(ptr->wid!=0)
    {
        dprintf("Set ID ptr->wid=%d Set to %d,%d,%d(dir)\n",ptr->wid,startx,starty,dir);
        dsystem("PAUSE");
        ans[ptr->wid][0]=starty;
        ans[ptr->wid][1]=startx;
        ans[ptr->wid][2]=dir+'A';
        /// Reset word ID to 0.
        ptr->wid=0;
    }
    if(y<0||y>=L||x<0||x>=C) return;
    /// Same Direction (dir)
    dfs(ptr->next[map[y][x]-'A'],starty,startx,y+direction[dir][0],x+direction[dir][1],dir);
}

void buildtree(char* str,node* curnode,int id)
{
    int len=strlen(str);
    node* nptr=curnode;
    for(int i=0;i<len;i++)
    {
        int index=str[i]-'A';
        if(nptr->next[index]==nullptr)
        {
            node* newnode=(node*)malloc(sizeof(node));
            for(int s=0;s<26;s++) newnode->next[s]=nullptr;
            newnode->wid=0;
            nptr->next[index]=newnode;
            nptr=newnode;
        }
        else
        {
            nptr=nptr->next[index];
        }
    }
    nptr->wid=id;
}

int main()
{
    initdirection();
    scanf("%d %d %d",&L,&C,&W);
    for(int i=0;i<L;i++)
    {
        scanf("%s",&map[i][0]);
    }
    for(int i=0;i<W;i++)
    {
        scanf("%s",word);
        buildtree(word,root,i+1);
    }
    /// Main LOOP
    for(int i=0;i<L;i++)
    {
        for(int j=0;j<C;j++)
        {
            for(int k=0;k<8;k++)
            {
                node* ptrStart=root;
                dfs(ptrStart,i,j,i,j,k);
            }
        }
    }
    for(int i=1;i<=W;i++)
    {
        printf("%d %d %c\n",ans[i][0],ans[i][1],(char)ans[i][2]);
    }
    return 0;
}
