#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int len[2];
int next[2][1000111];
char str[2][1000111];
void getnext(int z)
{
    int j,k;
    j=1;k=0;
    next[z][1]=0;
    while(str[z][j])
    {
        if(k==0 || str[z][j]==str[z][k])    next[z][++j]=++k;
        else                                k=next[z][k];
    }
}
int KMP1(int a,int b)
{
    int i,j;
    j=1;
    for(i=1;str[a][i];)
    {
        if(str[a][i]==str[b][j])
        {
            i++;j++;
            if(j==len[b])    return 1;
        }
        else
        {
            j=next[b][j];
            if(j==0)    {i++;j=1;}
        }
    }
    return 0;
}
int KMP2(int a,int b)
{
    int i,j;
    int flag;
    j=1;
    for(i=1;str[a][i];)
    {
        flag=1;  
        if(str[a][i]==str[b][j])  
        {  
            if(i==len[a]-1) return j;  
            if(j==len[b]-1) flag=1;  
            else            {flag=0;i++;j++;}  
        }  
        if(flag)  
        {  
            j=next[b][j];  
            if(j==0)   {i++;j=1;}  
        }
    }
    return 0;
}
int main()
{
    int T;
    int ans1,ans2,ans;
    scanf("%d",&T);
    while(T--)
    {
        str[0][0]='#';
        str[1][0]='#';
        scanf("%s%s",str[0]+1,str[1]+1);
        len[0]=strlen(str[0]);
        len[1]=strlen(str[1]);
        getnext(0);
        getnext(1);
        if(len[0]>len[1])    ans=KMP1(0,1);
        else                ans=KMP1(1,0);
        if(ans)    {printf("%d\n",(len[0]>len[1]?len[0]:len[1])-1);continue;}
        ans1=KMP2(0,1);
        ans2=KMP2(1,0);
        ans=ans1>ans2?ans1:ans2;
        ans=len[0]+len[1]-2-ans;
        printf("%d\n",ans);
    }
    return 0;
}
