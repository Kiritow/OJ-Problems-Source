#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#define LL long long
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
map<string,int>m;
void Init()
{
    m["1m"]=1;m["2m"]=2;m["3m"]=3;
    m["4m"]=4;m["5m"]=5;m["6m"]=6;
    m["7m"]=7;m["8m"]=8;m["9m"]=9;
    m["1s"]=10;m["2s"]=11;m["3s"]=12;
    m["4s"]=13;m["5s"]=14;m["6s"]=15;
    m["7s"]=16;m["8s"]=17;m["9s"]=18;
    m["1p"]=19;m["2p"]=20;m["3p"]=21;
    m["4p"]=22;m["5p"]=23;m["6p"]=24;
    m["7p"]=25;m["8p"]=26;m["9p"]=27;
    m["1c"]=28;m["2c"]=29;m["3c"]=30;
    m["4c"]=31;m["5c"]=32;m["6c"]=33;
    m["7c"]=34;
}
int c[35];int b[14];
int c13[13]={1,9,10,18,19,27,28,29,30,31,32,33,34};
bool judge1()
{
    int c1=0,c2=0;
    for(int i=0;i<13;i++)
    {
        if(c[c13[i]]) c1++;
        if(c[c13[i]]>1) c2++;
    }
    if(c1==13&&c2==1) return true;
    return false;
}
bool judge2()
{
    for(int i=0;i<14;i+=2)
    {
        if((i&&b[i]==b[i-1])||b[i]!=b[i+1]) return false;
    }
    return true;
}
bool flag;
bool check(int idx)
{
    if(idx>=1&&idx<=7) return true;
    if(idx>=10&&idx<=16) return true;
    if(idx>=19&&idx<=25) return true;
    return false;
}
void dfs(int idx,int k1,int k2)
{
    if(flag) return;
    if(k1>4||k2>1) return ;
    if(idx==14)
    {
        if(k1==4&&k2==1){flag=true;}
        return ;
    }
    for(int i=1;i<=34;i++)
    {
        int mark=0;
        if(c[i]>=3) {c[i]-=3;mark++;dfs(idx+3,k1+1,k2);c[i]+=3;}
        if(c[i]>=2) {c[i]-=2;mark++;dfs(idx+2,k1,k2+1);c[i]+=2;}
        if(check(i)&&c[i]&&c[i+1]&&c[i+2]) {c[i]--;c[i+1]--;c[i+2]--;mark++;dfs(idx+3,k1+1,k2);c[i]++;c[i+1]++;c[i+2]++;}
        if(c[i]&&mark==0) return ;
        if(c[i]) break;
    }
}
int a[14];
int slove()
{
    memcpy(b,a,sizeof(a));
    sort(b,b+14);
    mem(c,0);
    for(int i=0;i<14;i++)
    {
        c[b[i]]++;
        if(c[b[i]]>4)return false;
    }
    if(judge1()) return true;
    if(judge2()) return true;
    flag=false;
    dfs(0,0,0);
    return flag;
}
int main()
{
    m.clear();
    Init();
    int t;
    cin>>t;
    while(t--)
    {
        for(int i=0;i<13;i++)
        {
            string s;
            cin>>s;
            a[i]=m[s];
        }
        int ans[50],cnt=0;
        for(int i=1;i<=34;i++)
        {
            a[13]=i;
            if(slove()) ans[cnt++]=i;
        }
        if(cnt==0) cout<<"Nooten"<<endl;
        else
        {
            cout<<cnt;
            for(int i=0;i<cnt;i++)
            {
                for(map<string,int>::iterator it=m.begin();it!=m.end();it++)
                {
                    if(it->second==ans[i])
                    {
                        cout<<" "<<(it->first);
                        break;
                    }
                }
            }
            cout<<endl;
        }
    }
    return 0;
}
