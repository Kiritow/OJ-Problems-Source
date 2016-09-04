#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;
#define LL(x) (x<<1)
#define RR(x) (x<<1|1)
#define MID(a,b) (a+((b-a)>>1))
#define INF (1<<30)
const int N=50005;
int n,q,ed[N];
int st_len,ed_len;
struct Segtree
{
    set<int> T[N];
    int st[N*4],len[N*4];
    void PushUp(int ind)
    {
        if(st[LL(ind)]<st[RR(ind)])
        {
            st[ind]=st[LL(ind)];
            len[ind]=len[LL(ind)];
        }
        else
        {
            st[ind]=st[RR(ind)];
            len[ind]=len[RR(ind)];
        }
    }
    void build(int lft,int rht,int ind)
    {
        st[ind]=INF;
        if(lft==rht) T[lft].clear();
        else
        {
            int mid=MID(lft,rht);
            build(lft,mid,LL(ind));
            build(mid+1,rht,RR(ind));
        }
    }
    void updata(int pos,int ist,bool add,int ind,int lft,int rht)
    {
        if(lft==rht)
        {
            if(add) T[lft].insert(ist);
            else T[lft].erase(ist);
            if(T[lft].size()==0) st[ind]=INF;
            else
            {
                len[ind]=lft;    st[ind]=*(T[lft].begin());
            }
        }
        else
        {
            int mid=MID(lft,rht);
            if(pos<=mid) updata(pos,ist,add,LL(ind),lft,mid);
            else updata(pos,ist,add,RR(ind),mid+1,rht);
            PushUp(ind);
        }
    }
    pair<int,int> query(int ist,int ied,int ind,int lft,int rht)
    {
        if(ist<=lft&&rht<=ied) return make_pair(st[ind],len[ind]);
        else
        {
            int mid=MID(lft,rht);
            pair<int,int> tmp1,tmp2; tmp1.first=INF,tmp2.first=INF;
            if(ist<=mid) tmp1=query(ist,ied,LL(ind),lft,mid);
            if(ied> mid) tmp2=query(ist,ied,RR(ind),mid+1,rht);
            if(tmp1.first<tmp2.first) return tmp1;
            else return tmp2;
        }
    }
}seg;
struct BIT
{
    int T[N],sum;
    void init(){memset(T,0,sizeof(T));sum=0;}
    int lowbit(int x){return x&-x;}
    void insert(int x,int add)
    {
        sum+=add;
        while(x<N)
        {
            T[x]+=add; x+=lowbit(x);
        }
    }
    int query(int k)
    {
        int ind=0;
        for(int i=20;i>=0;i--)
        {
            ind^=(1<<i);
            if(ind<N&&k>T[ind]) k-=T[ind];
            else ind^=(1<<i);
        }
        return ind+1;
    }
    int getsum()
    {
        return sum;
    }
}bit;
int calu(int st,int len,int m,int a,int b)    
{
    int ed=st+len-1;
    return max(ed-m-b+1,st);
}
bool judge(int st1,int st2,int &ilen,int &ist) 
{
    ist=st1;
    if(st1>st2) return false;
    ilen=st2-st1+1;
    return true;
}
int main()
{
    int t,t_cnt=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&q);
        seg.build(1,n,1);   bit.init();
        st_len=n,ed_len=n;
        printf("Case #%d:\n",++t_cnt);
        while(q--)
        {
            char cmd[5];     scanf("%s",cmd);
            if(cmd[0]=='A')
            {
                int m,a,b;     scanf("%d%d%d",&m,&a,&b);
                if(st_len>=m)     
                {
                    if(st_len==n)  
                    {
                        ed[1]=m; bit.insert(1,1); st_len=0; ed_len-=m;
                        printf("%d\n",1);
                    }
                    else            
                    {
                        int tmp=calu(1,st_len,m,a,b);     
                        ed[tmp]=tmp+m-1; bit.insert(tmp,1); 
                        printf("%d\n",tmp);
                        int len,st;
                        if(judge(ed[tmp]+1,st_len,len,st)) seg.updata(len,st,1,1,1,n);    
                        st_len=tmp-1;                     
                    }
                }
                else
                {
                    pair<int,int> res=seg.query(m,m+a+b,1,1,n);
                    if(res.first!=INF)
                    {
                        seg.updata(res.second,res.first,0,1,1,n); 
                        int tmp=calu(res.first,res.second,m,a,b);  
                        ed[tmp]=tmp+m-1;  bit.insert(tmp,1);        
                        printf("%d\n",tmp);
                        int len,st;
                        if(judge(res.first,tmp-1,len,st))     seg.updata(len,st,1,1,1,n);        
                        if(judge(ed[tmp]+1,res.first+res.second-1,len,st))     seg.updata(len,st,1,1,1,n);
                    }
                    else
                    {
                        if(ed_len<m) puts("-1");
                        else
                        {
                            int tmp=n-ed_len+1;
                            ed[tmp]=tmp+m-1; ed_len=n-ed[tmp];    bit.insert(tmp,1);
                            printf("%d\n",tmp);
                        }
                    }
                }
            }
            else
            {
                int k; scanf("%d",&k);
                if(k>bit.getsum()||k<=0) continue;  
                int st=bit.query(k);                 
                int st1=1;
                if(k>1) st1=ed[bit.query(k-1)]+1;    
                int len1=st-st1;                    
                if(len1>0&&st1!=1) seg.updata(len1,st1,0,1,1,n);    
                int st2=bit.query(k+1)-1,len2;        
                if(st2>n) len2=0,st2=n;
                else len2=st2-ed[st];
                if(len2>0&&!(st2==n)) seg.updata(len2,ed[st]+1,0,1,1,n);
                if(st1!=1&&st2!=n) seg.updata(st2-st1+1,st1,1,1,1,n);
                if(st1==1) st_len=st2-st1+1;
                if(st2==n) ed_len=st2-st1+1;            
                bit.insert(st,-1);
            }
        }
    }
    return 0;
}
