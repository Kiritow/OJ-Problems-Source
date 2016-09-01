#include<cstdio>
#include<vector>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
const int mn=100100,M=379177,base=213;
int n,m;
#define hf(a) ((a)&0x7fffffff)%M
struct node {
     node *nxt;
    int k,len;
} *ha[M],pool[M];
int pp;
node* find(int k1,int len) {
     for(node *p=ha[hf(k1)];p;p=p->nxt)
        if(k1==p->k && len==p->len)return p;
    return 0;
}
void insert(int k,int len) {
    int h=hf(k);
    pool[pp].k=k;
    pool[pp].len=len;
    pool[pp].nxt = ha[h];
    ha[h]=&pool[pp++];
}
char ts[mn];
string a,b;
vector<int> a1,b1,a2,b2;
int pw[mn];
void getbit(string &str1,string &str2,vector<int> &bit)
{
    int len1,len2;
    len1=str1.size();
    len2=str2.size();
    bit.clear();
    int key=0;
    memset(ha,0,sizeof(ha));
    pp=0;
    for(int i=0;i<len1;i++)
    {
        key+=str1[len1-i-1]*pw[i];
        insert(key,i+1);
    }
    key=0;
    for(int i=0;i<len2 && i<len1;i++)
    {
        key*=base;
        key+=str2[i];
        node *p=find(key,i+1);
        if(p)bit.push_back(1);
        else bit.push_back(0);
    }
    reverse(bit.begin(),bit.end());
}
void mu(vector<int> &a,vector<int> &b)
{
    int i,j,c=0,tmp;
    i=a.size()-1; j=b.size()-1;
    while(1)
    {
        if(i<0 && j<0)break;
        if(i>=0)c+=a[i];
        if(j>=0)c-=b[j];
        if(c<0) { a[i]=2+c; c=-1; }
        else { a[i]=c; c=0; }
        i-=1;
        j-=1;
    }
}
int main()
{
    pw[0]=1;
    for(int i=1;i<mn;i++)pw[i]=pw[i-1]*base;
    while(1)
    {
        scanf("%d%d",&n,&m);
        if(n==0 && m==0)break;
        scanf("%s",ts);
        a=ts;
        scanf("%s",ts);
        b=ts;
        getbit(b,b,b1);
        getbit(b,a,b2);
        getbit(a,a,a1);
        getbit(a,b,a2);
        mu(b1,b2);
        mu(a1,a2);
        int al=0,bl=0;
        for(bl=0;bl<b1.size();bl++)if(b1[bl]!=0)break;
        for(al=0;al<a1.size();al++)if(a1[al]!=0)break;
        if(b1.size()-bl!=a1.size()-al)
        {
            if(b1.size()-bl>a1.size()-al)printf("Hamlet\n");
            else printf("Laertes\n");
        }
        else
        {
            bool f=1;
            while(1)
            {
                if(bl>=b1.size())break;
                if(b1[bl]!=a1[al])
                {
                    if(b1[bl]>a1[al])printf("Hamlet\n");
                    else printf("Laertes\n");
                    f=0;
                    break;
                }
                bl++;
                al++;
            }
            if(f)printf("Equal\n");
        }
    }
    return 0;
}
