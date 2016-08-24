#include<cstdio>
#include<cstring>
int num[3],tot,n,f;
char s[3][100],ans[3][100];
int check()
{
    char str[100];
    int a=0,b=0,c;
    for(int i=0;i<num[0];i++)
        a=a*10+s[0][i]-'0';
    for(int i=0;i<num[1];i++)
        b=b*10+s[1][i]-'0';
    c=a*b;
    for(int i=num[2]-1;i>=0;i--)
    {
        str[i]='0'+c%10;
        c/=10;
    }
    if(c>0||str[0]=='0')
        return 0;
    for(int i=0;i<num[2];i++)
        if(s[2][i]!=str[i]&&s[2][i]!='*')
            return 0;
    return 1;
}
void dfs(int a,int b)
{
    if(b>=num[a])
    {
        b=0;
        a++;
    }
    if(a==2)
    {
        if(check())
            tot++;
        return;
    }
    if(s[a][b]!='*')
        dfs(a,b+1);
    else
    {
        for(int i=0;i<10;i++)
        {
            if(b==0&&i==0)
                continue;
            s[a][b]='0'+i;
            dfs(a,b+1);
            if(tot>1)
            {
                s[a][b]='*';
                return;
            }
        }
        s[a][b]='*';
    }
}
void search(int a,int b,int c)
{
    if(b>=num[a])
    {
        b=0;
        a++;
    }
    if(c==n)
    {
        tot=0;
        dfs(0,0);
        if(tot==1)
        {
            f=1;
            for(int i=0;i<3;i++)
                strcpy(ans[i],s[i]);
        }
        return;
    }
    if(a>=3)
        return;
    char ch=s[a][b],tc;
    for(int i=0;i<=10;i++)
    {
        if(i==1&&b==0)
            continue;
        if(!i)
            tc='*';
        else
            tc='0'+i-1;
        if(tc==s[a][b])
            search(a,b+1,c);
        else
        {
            s[a][b]=tc;
            search(a,b+1,c+1);
        }
        if(f)
        {
            s[a][b]=ch;
            return;
        }
        s[a][b]=ch;
    }
}
void work()
{
    int m=0;
    for(int i=0;i<3;i++)
        m+=num[i];
    for(n=1;n<=m;n++)
    {
        f=0;;
        search(0,0,0);
        if(f)
            return;
    }
}
int main()
{
    int cas=1;
    memset(s,0,sizeof(s));
    while(scanf("%s",s[0])&&s[0][0]!='0')
    {
        scanf("%s%s",s[1],s[2]);
        for(int i=0;i<3;i++)
            num[i]=strlen(s[i]);
        tot=0;
        dfs(0,0);
        printf("Case %d: ",cas++);
        if(tot==1)
            printf("%s %s %s\n",s[0],s[1],s[2]);
        else
        {
            work();
            printf("%s %s %s\n",ans[0],ans[1],ans[2]);
        }
        memset(s,0,sizeof(s));
    }
    return 0;
}
