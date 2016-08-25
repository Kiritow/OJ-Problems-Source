#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
#include<set>
#include<vector>
#include<stack>
#include<map>
#include<queue>
#include<deque>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<cctype>
#include<functional>
using namespace std;
#define me(s) memset(s,0,sizeof(s))
#define pb push_back
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair <int, int> P;
const int N=256;
int n,m,target;         
map<string,string>sol;  
queue<string>q;         
bool icy[N];
char link_l[N],link_r[N],clear_l[N],clear_r[N];
void init()
{
    memset(icy,0,sizeof(icy));
    icy['O']=icy['[']=icy[']']=icy['=']=true;
    memset(link_l,' ',sizeof(link_l));    
    link_l['O']=']';link_l['[']='=';
    memset(link_r,' ',sizeof(link_r));     
    link_r['O']='[';link_r[']']='=';
    memset(clear_l,' ',sizeof(clear_l));   
    clear_l[']']='O';clear_l['=']='[';clear_l['O']='O';clear_l['[']='[';
    memset(clear_r,' ',sizeof(clear_r));
    clear_r['[']='O';clear_r['=']=']';clear_r['O']='O';clear_r[']']=']';
}
string fall(string s)
{
    int k,r,p;
    for(int i=n-1;i>=0;i--) 
        for(int j=0;j<m;j++)
    {
        char ch=s[i*m+j];
        if(ch=='O'||ch=='@')
        {
            for(k=i+1;k<n;k++)if(s[k*m+j]!='.')break;
            s[i*m+j]='.';s[(k-1)*m+j]=ch;
        }
        else if(ch=='[')
        {
            for(r=j+1;r<m;r++)if(s[i*m+r]=='X'||s[i*m+r]==']')break;  
            if(s[i*m+r]==']')          
            {
                for(k=i+1;k<n;k++)     
                {
                    bool found=false;
                    for(p=j;p<=r;p++)if(s[k*m+p]!='.'){found=true;break;}
                    if(found)break;
                }
                for(p=j;p<=r;p++)s[i*m+p]='.';      
                for(p=j+1;p<r;p++)s[(k-1)*m+p]='='; 
                s[(k-1)*m+j]='[';s[(k-1)*m+r]=']';  
            }
            j=r;     
        }
    }
    return s;    
}
int h(string s)
{
    int a,b,x=s.find('@');
    a=x%m-target%m; if(a<0)a=-a;              
    if(x/m>target/m)b=x/m-target/m;         
    else b=(x/m<target/m?1:0);
    return a>b?a:b;                          
}
bool expand(string s,char cmd)
{
    string seq=sol[s]+cmd;
    int x=s.find('@');    
    s[x]='.';            
    if(cmd=='<'||cmd=='>')   
    {
        s[x]='@';
        int p=(cmd=='<'?x+m-1:x+m+1);
        if(s[p]=='X')return false;   
        else if(s[p]=='.')           
        {
            s[p]='O';
            if(icy[s[p-1]])s[p-1]=link_r[s[p-1]];
            if(s[p-1]!='.')s[p]=link_l[s[p]];   
            if(icy[s[p+1]])s[p+1]=link_l[s[p+1]];
            if(s[p+1]!='.')s[p]=link_r[s[p]];    
        }
        else  
        {
            s[p]='.';
            if(icy[s[p-1]])s[p-1]=clear_r[s[p-1]];  
            if(icy[s[p+1]])s[p+1]=clear_l[s[p+1]]; 
        }
    }
    else    
    {
        int p=(cmd=='L'?x-1:x+1); 
        if(s[p]=='.')s[p]='@';    
        else
        {
            if(s[p]=='O')   
            {
                int k;
                if(cmd=='L'&&s[p-1]=='.')
                {
                    for(k=p-1;k>0;k--)if(s[k-1]!='.'||s[k+m]=='.')break;
                    s[p]='.';s[k]='O';s[x]='@';
                }
                if(cmd=='R'&&s[p+1]=='.')
                {
                    for(k=p+1;k<n*m;k++)if(s[k+1]!='.'||s[k+m]=='.')break;
                    s[p]='.';s[k]='O';s[x]='@';
                }
            }
            if(s[p]!='.')  
            {
                if(s[p-m]=='.'&&s[x-m]=='.')s[p-m]='@';  
                else s[x]='@';
            }
        }
    }
    s=fall(s);  
    if(h(s)+seq.length()>15)return false;  
    if(s.find('@')==target)  
    {
        printf("%s\n",seq.c_str());
        return true;
    }
    if(!sol.count(s))  
    {
        sol[s]=seq;
        q.push(s);
    }
    return false;
}
int main()
{
    int rnd=0;
    init();    
    while(~scanf("%d%d",&n,&m))
    {
        if(!n)break;
        char mp[20][20];
        for(int i=0;i<n;i++)
            scanf("%s",mp[i]);
        string s="";
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
        {
            if(mp[i][j]=='#')
            {
                target=i*m+j;
                mp[i][j]='.';
            }
            s+=mp[i][j];
        }
        q.push(s);
        sol.clear();
        sol[s]="";
        printf("Case %d: ",++rnd);
        while(!q.empty())
        {
            string s=q.front();
            q.pop();
            if(expand(s,'<'))break;
            if(expand(s,'>'))break;
            if(expand(s,'L'))break;
            if(expand(s,'R'))break;
        }
        while(!q.empty())q.pop();
    }
}
