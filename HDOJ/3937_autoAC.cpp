#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<cmath>
#define N 64
struct trie{
 int next[N];
 int tag;
}data[3000000];
int inp;
int init(int a){
 memset(data[a].next,0,sizeof(data[a].next));
 data[a].tag=0;
 return a;
}
int tran(char a){
 if(a>='A'&&a<='Z') return a-'A';
 if(a>='a'&&a<='z') return a-'a'+26;
 return a-'0'+52;
}
void insert(char *a){
 int p=0;
 for(;*a;a++){
 int d=tran(*a);
 if(data[p].next[d]==0)data[p].next[d]=init(++inp);
 p=data[p].next[d];
 data[p].tag++;
 }
}
int query(char *a){
 int p=data[0].next[tran(*a)];
 for(a++;*a&&p;a++){
 int d=tran(*a);
 p=data[p].next[d];
 }
 return data[p].tag;
}
bool isok(double x,double y){
 return (fabs(x-y)/x)<0.11;
}
int getint(char *a){
 int ret=0;
 for(int i=0;i<8;i++)
 ret=ret*2+a[i];
 return ret;
}
char be[]="begin";
char en[]="end";
bool cmp(char *a,char *b,int len){
 for(int i=0;i<len;i++)
 if(a[i]!=b[i])
 return false;
 return true;
}
int T,n,m,tf;
double a,b;
char str[100],ss[10];
int main(void){
 while(scanf("%d%d",&T,&m)+1){
 inp=0;init(0);
 tf=0;
 for(int i=0;i<T;i++){
 scanf("%s",str);
 insert(str);
 }
 for(;m;m--){
 tf=0;
 double temp;
 scanf("%d",&n);
 scanf("%lf%lf",&a,&b);
 if(!(a<b&&isok(2*a,b))){
 tf=1;
 }
 ss[0]=0,ss[1]=1;
 for(int i=2;i<8;i++){
 scanf("%lf",&temp);
 if(isok(temp,a))
 ss[i]=0;
 else
 ss[i]=1;
 }
 str[0]=getint(ss);
 for(int i=1;i<n;i++){
 for(int j=0;j<8;j++){
 scanf("%lf",&temp);
 if(isok(temp,a)){
 ss[j]=0;
 }
 else{
 ss[j]=1;
 }
 }
 str[i]=getint(ss);
 }
 str[n]='\0';
 if(!cmp(be,str,5)||!cmp(en,str+n-3,3))
 tf=1;
 if(tf){
 printf("wrong barcode!\n");
 }
 else{
 str[n-3]='\0';
 printf("%d\n",query(str+5));
 }
 }
 }
}
