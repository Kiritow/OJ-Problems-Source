#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;
const int N=10010;
const int M=35;
char html[M][N],stored[M][N],sta1[N][M];
char mapping[M][M][2][M];
int mapNum[M],sta2[N];
void getHTML(int n)
{
    int j,i=0,flag=1;
    char beginTag[M],tag[M];
    getchar();
    while(1)
    {
        html[n][i]=getchar();
        if(html[n][i]=='<')
        {
            j=0;
            while(html[n][++i]=getchar())
            {
                if(html[n][i]=='/')continue;
                if(html[n][i]==' '||html[n][i]=='>')break;
                tag[j++]=html[n][i];
            }
            tag[j]='\0';
            if(flag==1)
            {
                strcpy(beginTag,tag);
                flag=0;
            }
            else if(!strcmp(tag,beginTag))
            {
                html[n][++i]='\0';
                return;
            }
        }
        i++;
    }
}
void getMapping(int n,int m)
{
    int i,j;
    char mp[100];
    cin>>mp;
    for(i=0; mp[i]!='-'; i++)
        mapping[n][m][0][i]=mp[i];
    mapping[n][m][0][i]='\0';
    for(j=0,i++; i<strlen(mp); i++,j++)
        mapping[n][m][1][j]=mp[i];
    mapping[n][m][1][j]='\0';
}
void getTag(int n,int i,char tag[])
{
    int j=0;
    while(1)
    {
        i++;
        if(html[n][i]=='/')continue;
        if(html[n][i]==' '||html[n][i]=='>')break;
        tag[j++]=html[n][i];
    }
    tag[j]='\0';
}
int getId(int n,int i,char id[])
{
    int j;
    id[0]='\0';
    char tmp[M];
    while(html[n][i]==' ')
    {
        j=0;
        while(html[n][++i]!='=')
            tmp[j++]=html[n][i];
        tmp[j]='\0';
        if(!strcmp(tmp,"id"))
        {
            i++;
            j=0;
            while(html[n][++i]!='"')
                id[j++]=html[n][i];
            id[j]='\0';
        }
        else
        {
            i++;
            while(html[n][++i]!='"');
        }
        i++;
    }
    return i;
}
void store(int n,int i,int j,char tag[])
{
    stored[j][0]='\0';
    int k,y=0,flag=0,len=strlen(tag);
    for(i++;; i++)
    {
        k=0;
        if(html[n][i]=='<')
            for(; k<len; k++)
                if(tag[k]!=html[n][i+1+k])break;
        if(k==len)flag++;
        k=0;
        if(html[n][i]=='<'&&html[n][i+1]=='/')
            for(; k<len; k++)
                if(tag[k]!=html[n][i+2+k])break;
        if(k==len)
        {
            if(!flag)
            {
                stored[j][y]='\0';
                return;
            }
            else flag--;
        }
        stored[j][y++]=html[n][i];
    }
}
bool isStructure(int n,int m)
{
    int i,j,k,ii,flag=0,top=-1;
    char tag[M],id[M],tag2[M],id2[M];
    int len1=strlen(html[n]);
    for(i=k=0; i<len1;)
    {
        ii=i;
        while(html[n][i]==' '||html[n][i]=='\n')i++;
        while(html[m][k]!='<')k++;
        getTag(n,i,tag);
        getTag(m,k,tag2);
        if(strcmp(tag,tag2)||html[n][i+1]!=html[m][k+1])
        {
            if(!strcmp(tag,tag2))sta2[top]++;
            if(!flag)
            {
                return false;
            }
            while(html[m][k]!='>')k++;
            i=ii;
            continue;
        }
        if(html[n][i+1]=='/') 
        {
            if(!sta2[top])
            {
                i+=strlen(tag)+3;
                flag--;
            }
            else sta2[top]--;
            k+=strlen(tag)+3;
        }
        else 
        {
            i+=strlen(tag)+1;
            k+=strlen(tag2)+1;
            if(html[n][i]==' ') 
            {
                if(html[m][k]!=' ')
                {
                    if(!flag)
                    {
                        return false;
                    }
                    while(html[m][k]!='>')k++;
                    i=ii;
                    continue;
                }
                i=getId(n,i,id);
                k=getId(m,k,id2);
                if(strcmp(id,id2))
                {
                    if(!flag)
                    {
                        return false;
                    }
                    while(html[m][k]!='>')k++;
                    i=ii;
                    continue;
                }
            }
            for(j=0; j<mapNum[n]; j++)
                if(!strcmp(id,mapping[n][j][0]))
                    break;
            if(html[n][i]=='/') 
            {
                i+=2;
                k+=2;
            }
            else  //<xx>
            {
                if(j!=mapNum[n]) 
                {
                    strcpy(sta1[++top],tag);
                    flag++;
                    sta2[top]=0;
                    for(j=0; j<mapNum[n]; j++)
                        if(!strcmp(id,mapping[n][j][0]))
                            store(m,k,j,tag);
                }
                i++;
                k++;
            }
        }
    }
    return true;
}
void output(int n)
{
    int i,j,k,ii;
    char tag[M];
    int len1=strlen(html[0]);
    for(i=0; i<len1;)
    {
        while(i<len1&&html[0][i]!='<')
            putchar(html[0][i++]);
        if(i==len1)break;
        getTag(0,i,tag);
        for(j=0; j<mapNum[n]; j++)
            if(!strcmp(tag,mapping[n][j][1]))
                break;
        if(j==mapNum[n])
        {
            putchar(html[0][i++]);
            continue;
        }
        else
        {
            int len=strlen(tag);
            ii=i;
            for(i+=len+1;; i++)
            {
                k=0;
                if(html[0][i]=='<'&&html[0][i+1]=='/')
                    for(; k<len; k++)
                        if(tag[k]!=html[0][i+2+k])break;
                if(k==len)break;
            }
            while(html[0][ii]!='>')
                putchar(html[0][ii++]);
            putchar(html[0][ii++]);
            cout<<stored[j];
            while(html[0][i]!='>')
                putchar(html[0][i++]);
            putchar(html[0][i++]);
        }
    }
}
int main()
{
    int t,ca=1;
    scanf("%d",&t);
    while(t--)
    {
        int i,j,n,m;
        getHTML(0);
        scanf("%d",&n);
        for(i=1; i<=n; i++)
        {
            getHTML(i);
            scanf("%d",&mapNum[i]);
            for(j=0; j<mapNum[i]; j++)
                getMapping(i,j);
        }
        getHTML(n+1);
        printf("Case #%d:\n",ca++);
        for(i=1; i<=n; i++)
            if(isStructure(i,n+1))
            {
                output(i);
                break;
            }
        if(i==n+1)printf("Can't Identify\n");
        else putchar('\n');
    }
    return 0;
}
