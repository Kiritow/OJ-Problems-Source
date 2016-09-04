#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
#include<algorithm>
#define N 1000005
#define inf 1<<29
#define MOD 100000007
#define LL long long
#define Key_value ch[ch[root][1]][0]
#define _match(a,b) ((a)==(b))
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
int n,q,a[N],pl,pr;
int size[N],pre[N],rev[N],sum[5],val[N];
int ch[N][2],tot1,root,s[N],tot2;
inline void NewNode(int &r,int k,int father){
    if(tot2)
        r=s[tot2--];
    else
        r=++tot1;
    ch[r][0]=ch[r][1]=0;
    pre[r]=father;
    size[r]=1;
    rev[r]=0;
    val[r]=k;
}
inline void Push_Up(int x){
    int l=ch[x][0],r=ch[x][1];
    size[x]=size[l]+size[r]+1;
}
inline void Push_Down(int r){
    if(rev[r]){
        rev[ch[r][0]]^= 1;  
        rev[ch[r][1]]^= 1;  
        swap(ch[r][0],ch[r][1]);  
        rev[r]=0;  
    }
}
inline void Bulid(int &r,int L,int R,int father){
    if(L>R)
        return ;
    int mid=(L+R)/2;
    NewNode(r,a[mid],father);
    Bulid(ch[r][0],L,mid-1,r);
    Bulid(ch[r][1],mid+1,R,r);
    Push_Up(r);
}
void Init(){
    tot1=tot2=root=0;
    ch[root][0]=ch[root][1]=pre[root]=rev[root]=size[root]=0;
    NewNode(root,-100,0);
    NewNode(ch[root][1],-1,root);
    Push_Up(root);
    Bulid(Key_value,1,n,ch[root][1]);
    Push_Up(ch[root][1]);
    Push_Up(root);
}
inline void Rotate(int x,int kind){
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
inline void Splay(int r,int goal){
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
inline void RotateTo(int k, int goal) {  
    int x=root;  
    Push_Down(x);  
    while(k!=size[ch[x][0]]+1){  
        if (k<=size[ch[x][0]]){  
            x=ch[x][0];  
        }else{  
            k-=(size[ch[x][0]]+1);  
            x=ch[x][1];  
        }  
        Push_Down(x);  
    }  
    Splay(x,goal);  
}  
void Print();
inline void Reversal(int pos,int k){
    RotateTo(pos,0);
    RotateTo(pos+k+1,root);
    rev[Key_value]^=1;
}
inline void Insert(int pos,int k,int num){
    RotateTo(pos,0);
    RotateTo(pos+1,root);
    NewNode(Key_value,num,ch[root][1]);
    Push_Up(ch[root][1]);
    Push_Up(root);
}
inline void Delete(int pos,int k){
    RotateTo(pos,0);
    RotateTo(pos+k+1,root);
    Key_value=0;
    Push_Up(ch[root][1]);
}
int cnt,ans[N];
inline void scanf_(int &num){
    char in;
    bool neg=false;
    while(((in=getchar()) > '9' || in<'0') && in!='-') ;
    if(in=='-'){
        neg=true;
        while((in=getchar()) >'9' || in<'0');
    }
    num=in-'0';
    while(in=getchar(),in>='0'&&in<='9')
        num*=10,num+=in-'0';
    if(neg)
        num=0-num;
}
inline void printf_(int num){
    bool flag=false;
    if(num<0){
        putchar('-');
        num=-num;
    }
    int ans[10],top=0;
    while(num!=0){
        ans[top++]=num%10;
        num/=10;
    }
    if(top==0)
        putchar('0');
    for(int i=top-1;i>=0;i--){
        char ch=ans[i]+'0';
        putchar(ch);
    }
}
void InOrder(int r){
    if(r==0)
        return;
    Push_Down(r);
    InOrder(ch[r][0]);
    if(cnt) putchar(' ');
    printf_(val[r]);
    cnt++;
    InOrder(ch[r][1]);
}
void Print(){
    RotateTo(1,0);
    RotateTo(n+2,root);
    cnt=0;
    InOrder(Key_value);
    putchar('\n');
}
int main(){
    int t;
    scanf_(t);
    while(t--){
        scanf_(n);
        for(int i=1;i<=n;i++)
            scanf_(a[i]);
        Init();
        char str[20];
        int k=1,pl,r1;
        scanf_(pl);scanf_(pr);scanf_(q);
        while(q--){
            scanf("%s",str);
            if(str[0]=='M'&&str[4]=='R'){
                scanf("%s",str);
                if(str[0]=='L') pl++;
                else pr++;
            }
            else if(str[0]=='M'&&str[4]=='L'){
                scanf("%s",str);
                if(str[0]=='L') pl--;
                else pr--;
            }
            else if(str[0]=='I'){
                scanf("%s",str);
                scanf_(a[1]);
                if(str[0]=='L') {Insert(pl,k,a[1]);}
                else {Insert(pr+1,k,a[1]);}
                n++;pr++;
            }
            else if(str[0]=='D'){
                scanf("%s",&str);
                if(str[0]=='L') {Delete(pl,k);}
                else {Delete(pr,k);}
                n--;pr--;
            }
            else if(str[0]=='R')
                Reversal(pl,pr-pl+1);
        }
        Print();
    }
    return 0;
}
