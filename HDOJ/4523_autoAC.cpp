#include<stdio.h>
#include<string.h>
char n[111],m[111],p[111],mid[111];
int compare(char *s1,char *s2)
{
      int len1=strlen(s1);
      int len2=strlen(s2);
      if(len1>len2) return 1;
      else if(len1<len2) return 0;
      for(int i=0;i<len1;i++)
      {
          if(s1[i]>s2[i]) return 1;
          else if(s2[i]>s1[i]) return 0;
      }
      return 1;
}
void solve(char *s1,char *s2)
{
    int len=strlen(s2);
    int len1=strlen(s1);
    strrev(s1);
    strrev(s2);
    for(int i=0;i<len;i++)
    {
        s1[i]=s1[i]-'0'+s2[i]-'0'+'0';
    }
    for(int i=0;i<len1;i++)
    {
        if(s1[i]>'9')
        {
            s1[i]=s1[i]-10;
            if(i+1==len1) {s1[len1]='1';s1[len1+1]='\0';}
            else
            s1[i+1]++;
        }
    }
    strrev(s1);
    if(compare(s1,m)) printf("YES\n");
    else printf("NO\n");
}
int main()
{
    while(scanf("%s %s %s",n,m,p)!=EOF)
    {
        if(strlen(m)==1&&m[0]-'0'<3) {printf("NO\n");continue;}
        if(strcmp(p,"0")==0)
        {
            if(strcmp(n,m)==0) printf("YES\n");
            else printf("NO\n");
            continue;
        }
        if(compare(n,m)) {printf("YES\n"); continue;}
        if(strlen(p)>strlen(n))
          solve(p,n);
        else solve(n,p);
    }
     return 0;
}
