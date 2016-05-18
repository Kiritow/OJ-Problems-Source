#include<iostream>
#include<queue>
#define judge (y<ny && y>=0 && x<nx && x>=0)
using namespace std;
struct node
{
    node *s[26],*fail;
    char c;
    int w;      
}*head,*p;
struct pp
{
    int y,x,len;
    char c;      
}outdata[1001];
int ny,nx,n,i,face,len,t[8][2]={{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1}};
char s[1001][1001],str[2001];
node *UpdateFail(node *p,int k)
{
    if (p->s[k]!=NULL) return p->s[k];
    else
    if (p==head) return p;
    else 
    return UpdateFail(p->fail,k);   
}
void built_trie(node *h,int k)
{  
    if (k==len)
    {
         h->w=i;
         return;
    }
    if (h->s[str[k]-'A']==NULL)   
    {
         p=new node; 
         p->w=0;
         p->c=str[k];
         for (int j=0;j<26;j++) p->s[j]=NULL; 
         p->fail=head;      
         h->s[str[k]-'A']=p;
    }     
    built_trie(h->s[str[k]-'A'],k+1);
    return;
}
queue< node* > myqueue;
void built_AC_automation()
{
    int i;
    node *h;
    while (!myqueue.empty()) myqueue.pop();
    myqueue.push(head);
    while (!myqueue.empty())
    {
         h=myqueue.front();
         myqueue.pop();  
         for (i=0;i<26;i++)
         if (h->s[i]!=NULL)  
         {
              myqueue.push(h->s[i]);               
              if (h==head) h->s[i]->fail=head;
              else                
              h->s[i]->fail=UpdateFail(h->fail,i);             
         }
    }
    return; 
}
void find(int y,int x,node *h)
{
    if (h==NULL) h=head;  
    if (h->w && outdata[h->w].x<0) 
    {
         outdata[h->w].x=x-t[face][0]*(outdata[h->w].len);
         outdata[h->w].y=y-t[face][1]*(outdata[h->w].len);
         outdata[h->w].c=face+'A';   
    }     
    if (!judge) return;
    while (h->s[s[y][x]-'A']==NULL && h!=head) h=h->fail; 
    find(y+t[face][1],x+t[face][0],h->s[s[y][x]-'A']);
    return;
}
int main()
{   
    memset(outdata,-1,sizeof(outdata)); 
    scanf("%d%d%d",&ny,&nx,&n);    
    getchar(); 
    for (i=0;i<ny;i++) scanf("%s",s[i]);
    head=new node;  
    head->w=0; 
    head->fail=head;
    for (i=0;i<26;i++) head->s[i]=NULL;
    for (i=1;i<=n;i++)
    {
         scanf("%s",str);
         len=strlen(str);
         outdata[i].len=len;
         built_trie(head,0);
    }
    built_AC_automation();
    for (face=0;face<8;face++)
    {
         for (i=0;i<nx;i++) {  find(0,i,head); find(ny-1,i,head); }
         for (i=0;i<ny;i++) {  find(i,0,head); find(i,nx-1,head); }
    }    
    for (i=1;i<=n;i++) printf("%d %d %c\n",outdata[i].y,outdata[i].x,outdata[i].c);
    return 0;   
}
