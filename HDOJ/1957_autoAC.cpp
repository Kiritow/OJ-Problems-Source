#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <bitset>
#include <ctime>
#include <queue>
#include <complex>
using namespace std;
#define clr(a) memset(a,0,sizeof(a));
const int maxsize=1000007,inf=0x7fffffff;
template<class T>
void show(T a[],int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
template<class T>
void show(const vector<T>& t){
    for(int i=0;i<t.size();i++){
        cout<<t[i]<<" ";
    }
    cout<<endl;
}
inline int randin(const int& l,const int& r)
{   return rand()%(r-l+1)+l;    }
struct node{
    int a,b;
    node(){
        a=b=0;
    }
};
char isprime[maxsize];
char  tocombine[maxsize];
void init(){
int i;
for(i=0;i<maxsize;i++)
isprime[i]=1;
isprime[0]=0;
for(i=2;i<maxsize;i++){
tocombine[i]=0;
if(isprime[i]){
int k=i;
while(isprime[k]){tocombine[i]++; k--;}
for(int j=i*2;j<maxsize;j+=i){
isprime[j]=0;
}
}
}
}
struct state{
int s[11];
int cnt;
state(){cnt=0;}
void sortme(){sort(s,s+cnt);}
};
bool operator < (const state& a,const state& b){
if(a.cnt!=b.cnt) return a.cnt <b.cnt;
for(int i=0;i<a.cnt;i++){
if(a.s[i]!=b.s[i]){
return a.s[i]<b.s[i];
}
}
return false;
}
bool operator == (state a,state b){
if(a.cnt!=b.cnt) return false;
for(int i=0;i<a.cnt;i++){
if(a.s[i]!=b.s[i]){
return false;
}
}
return true;
}
const int hashsize =maxsize/3;
template<class Tk,class Tv>
class hashmap{
struct hashnode{
Tk key;
Tv value;
hashnode *next;
};
hashnode mem[hashsize];
int mem_end;
hashnode *entry[hashsize];
hashnode* getmem(){mem_end++; return mem+mem_end-1;}
int culhash(const state& a){
int h =0;
for(int i=0;i<a.cnt;i++){
h=h*1007+a.s[i];
}
return (h%hashsize+hashsize)%hashsize;
}
public:
hashmap(){
clr(entry);mem_end=0;
}
bool get(const Tk& k,Tv& v){
int h=culhash(k);
hashnode *p=entry[h];
for(;p;p=p->next){
if(p->key==k){
v=p->value;
return true;
}
}
return false;
}
bool insert(const Tk& key,const Tv& v){
if(mem_end>=hashsize)return false;
int h=culhash(key);
hashnode *p=getmem();
p->key=key;p->value=v;p->next=entry[h];
entry[h]=p;
return true;
}
};
hashmap<state,node> hhh;
int maxstate;
node get(state s){
sort(s.s,s.s+s.cnt);
state os =s;
node ret ;
if(!hhh.get(s,ret)){
if(s.cnt==1&&isprime[s.s[0]]){
s.s[0]--;
ret =get(s);
swap(ret.a,ret.b);
ret.a++;
}else{
int i,j,k=0,l;
for(i=0;i<s.cnt;i++){
if(isprime[s.s[i]]){
l=tocombine[s.s[i]];
k+=l;
s.s[i]-=l;
}
if(s.s[i]==0){
s.cnt--;
swap(s.s[i],s.s[s.cnt]);
i--;
}
}
if(s.cnt){
{
for(i=0;i<s.cnt;i++){
int t=s.s[i];
if(i&&t==s.s[i-1]) continue;
int st=sqrt(s.s[i])+2;
for(j=2;j<st;j++){
if(t%j==0){
state ns =s;
ns.cnt++;
ns.s[i]=j;
ns.s[s.cnt]=t/j;
node tmp =get(ns);
swap(tmp.a,tmp.b);
if(tmp.a>ret.a){
ret=tmp;
}
}
}
}
}
if(k%2) swap(ret.a,ret.b);
}
ret.a+=k/2+k%2;
ret.b+=k/2;
}
hhh.insert(os,ret);
}
return ret;
}
void test(int n){
clock_t t0=clock();
for(int i=2;i<n;i++){
state s;s.s[0]=i;s.cnt=1;
node ans=get(s);
}
cout<<clock()-t0<<endl;
} 
int main()
{
    init();
state s; s.s[0]=1;s.cnt=1; 
node ans; ans.a=1;
hhh.insert(s,ans);
int n;
for(cin>>n;n;--n){
scanf("%d",s.s);
s.cnt=1;
ans =get(s);
printf("%d %d\n",ans.a,ans.b);
}
    return 0;
}
