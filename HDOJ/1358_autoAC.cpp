#include<stdio.h>
#include<string.h>
int next[1000005],n;
char s[1000005];
void getnext(char *s)
{
    int i,j;
    memset(next,0,sizeof(next));
    next[0]=-1;
    i=0;
    j=-1;
    while(i<n)
    {
        if(j==-1||s[i]==s[j])
        {
            i++;
            j++;
            next[i]=j;
        }
        else
            j=next[j];
    }
}
int main()
{
    int c=0;
    while(scanf("%d",&n)!=EOF,n)
    {
        int i;
        scanf("%s",s);
        getnext(s);
        printf("Test case #%d\n",++c);
        for(i=2;i<=n;i++)
        {
            int len=i-next[i];
            if(i%len==0&&i/len>1)
            {
                printf("%d %d\n",i,i/len);
            }
        }
        printf("\n");
    }
}
