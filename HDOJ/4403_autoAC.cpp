#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>
using namespace std;
char seq[50];
char str[50];
int n,ans,eq;
bool ok(int len)
{
    long long a,sum=0;
    int i,flg=1;
    queue<char> q;
    q.push('+');
    seq[len]='\0';
    for(i=0; i<len; i++)
    {
        a=0;
        while(i<=len&&seq[i]>='0'&&seq[i]<='9') a=a*10+seq[i]-'0',i++;
        q.push(seq[i]);
        if(flg&&q.front()=='+')
            sum+=a;
        else
            flg=0,sum-=a;
        q.pop();
    }
    if(sum==0) return 1;
    else return 0;
}
void dfs(int cur,int q)
{
    if(eq>1) return;
    if(q>n)
    {
        if(ok(cur)) ans++;
        return;
    }
    seq[cur]=str[q];
    dfs(cur+1,q+1);
    seq[cur]='+';
    seq[cur+1]=str[q];
    dfs(cur+2,q+1);
    seq[cur]='=';
    seq[cur+1]=str[q];
    eq++;
    dfs(cur+2,q+1);
    eq--;
}
int main()
{
    while(cin>>str,str[0]!='E')
    {
        ans=0;eq=0;
        seq[0]=str[0];
        n=strlen(str)-1;
        dfs(1,1);
        cout<<ans<<endl;
    }
    return 0;
}
