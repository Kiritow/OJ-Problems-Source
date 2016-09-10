#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char S[200];
char C[200];
int len;
long long a,b;
int getans(char *A)
{
    int i;
    int lena=strlen(A);
    if(lena==0) return 0;
    if(lena!=1&&A[0]=='0') return 0;
    for(i=0;i<lena;i++)
    if(!('0'<=A[i]&&A[i]<='9')) return 0;
    return 1; 
}
int main()
{
    int ans;
    long long k;
    while(gets(S)!=NULL)
    {
        scanf("%I64d%I64d",&a,&b);
        gets(C);
        len=strlen(S);
        if(S[0]=='-'&&S[1]=='0')  { printf("NO\n");continue;}    
        if(len>11||len==0) { printf("NO\n");continue;}    
        if(len==11&&S[0]!='-') { printf("NO\n");continue;}    
        if(S[0]=='-')
        ans=getans(S+1);
        else ans=getans(S);
        if(!ans) { printf("NO\n");continue;}
        else
          {
              k=strtoll(S,NULL,10);
            if(a<=k&&k<=b) printf("YES\n");    
            else printf("NO\n");
          }
                  memset(S,0,sizeof(S));
    }
    return 0;
}
