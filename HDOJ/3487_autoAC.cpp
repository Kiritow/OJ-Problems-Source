#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
#include<algorithm>
#define N 300015
#define inf 1<<29
#define MOD 100000007
#define LL long long
#define Key_value ch[ch[root][1]][0]
#define _match(a,b) ((a)==(b))
using namespace std;
int n,q;
int size[N],pre[N],key[N],num[N],rev[N];
int ch[N][2],tot,root,node[N];
void NewNode(int &r,int k,int father){
    r=++tot;
    ch[r][0]=ch[r][1]=0;
    pre[r]=father;
    rev[r]=0;
    key[r]=k;
}
void Push_Up(int r){
    size[r]=size[ch[r][0]]+size[ch[r][1]]+1;
}
void Push_Down(int r){
    if(rev[r]){
        swap(ch[r][0],ch[r][1]);
        rev[ch[r][0]]^=1;
        rev[ch[r][1]]^=1;
        rev[r]=0;        
    }
}
void Bulid(int &r,int L,int R,int father){
    if(L>R)
        return ;
    int mid=(L+R)/2;
    NewNode(r,mid,father);
    Bulid(ch[r][0],L,mid-1,r);
    Bulid(ch[r][1],mid+1,R,r);
    Push_Up(r);
}
void Init(){
    tot=root=0;
    ch[root][0]=ch[root][1]=pre[root]=rev[root]=size[root]=0;
    NewNode(root,-1,0);
    NewNode(ch[root][1],-1,root);
    size[root]=2;
    Bulid(Key_value,1,n,ch[root][1]);
    Push_Up(ch[root][1]);
    Push_Up(root);
}
void Rotate(int x,int kind){  
    int y=pre[x];    
    Push_Down(y);
    Push_Down(x);
    ch[y][!kind]=ch[x][kind];   
    pre[ch[x][kind]]=y;  
    if(pre[y])  
        ch[pre[y]][ch[pre[y]][1]==y]=x;  
    pre[x]=pre[y];  
    ch[x][kind]=y;  
    pre[y]=x;  
    Push_Up(y);  
}   
void Splay(int r,int goal){  
    Push_Down(r);
    while(pre[r]!=goal){  
        if(pre[pre[r]]==goal)  
            Rotate(r,ch[pre[r]][0]==r);  
        else{  
            int y=pre[r];  
            int kind=(ch[pre[y]][0]==y);  
            if(ch[y][kind]==r){  
                Rotate(r,!kind);  
                Rotate(r,kind);  
            }  
            else{  
                Rotate(y,kind);  
                Rotate(r,kind);  
            }  
        }  
    }  
    Push_Up(r);  
    if(goal==0) root=r;  
} 
int Get_Kth(int r,int k){
    Push_Down(r);
    int t=size[ch[r][0]];
    if(t==k-1)
        return r;
    if(t>=k)
        return Get_Kth(ch[r][0],k);
    else
        return Get_Kth(ch[r][1],k-t-1);
}
int Get_Min(int r){
    Push_Down(r);
    while(ch[r][0]){
        r=ch[r][0];
        Push_Down(r);
    }
    return r;
}
int Get_Max(int r){
    Push_Down(r);
    while(ch[r][1]){
        r=ch[r][1];
        Push_Down(r);
    }
    return r;
}
void Reversal(int a,int b){
    int x=Get_Kth(root,a);
    int y=Get_Kth(root,b+2);
    Splay(x,0);
    Splay(y,root);        
    rev[Key_value]^=1;
}
void Cut(int a,int b,int c){
    int x=Get_Kth(root,a);
    int y=Get_Kth(root,b+2);    
    Splay(x,0);
    Splay(y,root);
    int tmp=Key_value;
    Key_value=0;
    Push_Up(ch[root][1]);
    Push_Up(root);
    int z=Get_Kth(root,c+1);
    Splay(z,0);
    int m=Get_Min(ch[root][1]);
    Splay(m,root);
    Key_value=tmp;
    pre[Key_value]=ch[root][1];
    Push_Up(ch[root][1]);
    Push_Up(root);
}
int cnt;
void InOrder(int r){
    if(r==0)
        return;
    Push_Down(r);
    InOrder(ch[r][0]);
    if(cnt>=1&&cnt<=n){
        if(cnt>1) printf(" ");
        printf("%d",key[r]);
    }
    cnt++;
    InOrder(ch[r][1]);
}    
int main(){
    while(scanf("%d%d",&n,&q)!=EOF){
        if(n==-1&&q==-1)
            break;
        Init();
        while(q--){
            char str[10];
            int a,b,c;
            scanf("%s",str);        
            if(str[0]=='C'){
                scanf("%d%d%d",&a,&b,&c);
                Cut(a,b,c);
            }
            else{
                scanf("%d%d",&a,&b);
                Reversal(a,b);
            }
        }    
        cnt=0;
        InOrder(root);
        printf("\n");
    }
    return 0;
}
