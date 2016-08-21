#include<stdio.h>
#include<string.h>
int map[111][111];
int main()
{
    int n,i,j,m;
    char s[100];
    while(scanf("%s",s)!=EOF)
    {
        if(strcmp(s,"SHOW")==0)
        {
            for(i=1;i<=n;i++)
            {
                for(j=1;j<n;j++)
                    printf("%d ",map[i][j]);
                printf("%d\n",map[i][j]);
            }
            printf("\n");
        }
        else  if(strcmp(s,"NEIGHBORS")==0)
        {
            scanf("%d",&m);
            int flag=1;
            for(i=1;i<=n;i++)
            {
                for(j=1;j<=n;j++)
                    if(map[i][j]==m) 
                    {flag=0;break;}
                if(flag==0) break;
            }
                    int out[5],k,cnt=0;
                    if(map[i-1][j]!=-1) out[cnt++]=map[i-1][j];
                    if(map[i][j-1]!=-1) out[cnt++]=map[i][j-1];
                    if(map[i][j+1]!=-1) out[cnt++]=map[i][j+1];
                    if(map[i+1][j]!=-1) out[cnt++]=map[i+1][j];
                    for(k=0;k<cnt-1;k++)  printf("%d ",out[k]);
                    printf("%d\n",out[cnt-1]);
        }
        else
        {
            int k=0;
            n=0;
            while(s[k]!='\0')
            {
                n=n*10+(s[k]-'0');
                k++;
            }
            memset(map,-1,sizeof(map));
            for(i=1;i<=n;i++)
                for(j=1;j<=n;j++)
                    scanf("%d",&map[i][j]);      
        }
    }
    return 0;
}
