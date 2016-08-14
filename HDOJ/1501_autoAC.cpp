#include<stdio.h>
#include<string.h>
int v[205][205];
char a[205],b[205],c[410];
int lena,lenb,lenc;
int dfs(int i,int j,int k)
{
    if(c[k]=='\0')
        return 1;
    if(v[i][j])return 0;
    v[i][j]=1;
    if(lena<lenc)
        if(a[i]==c[k] && dfs(i+1,j,k+1))return 1;
    if(lenb<lenc)
        if(b[j]==c[k] && dfs(i,j+1,k+1))return 1;
    return 0;
}
int main()
{
    int t,k;    
    while(scanf("%d",&t)!=EOF)
    {
        k=1;
        while(k<=t){
        scanf("%s%s%s",&a,&b,&c);
        lena=strlen(a);
        lenb=strlen(b);
        lenc=strlen(c);
        memset(v,0,sizeof(v));
        if(dfs(0,0,0)==1)
            printf("Data set %d: yes\n",k);
        else
            printf("Data set %d: no\n",k);
        k++;
        }
    }
        return 0;
}
