#include<stdio.h>
#include<string.h>
int main()
{
    char s[1000],a[100][100];
    int i,j,k,l,m,n,t,f,g,len;
    while(scanf("%d",&n)!=EOF&&n)
    {    t=-1;
        getchar();
        gets(s);len=strlen(s);
        for(i=0,j=-1;s[i]!='\0';i++)
        {
            if(i%n==0)
            {    t++;j++;k=0;}
            if(t%2==0)
            {
                a[j][k++]=s[i];
            }
            if(t%2==1)
            {
                f=i+n-1;
                for(g=f;g>=i;g--)
                    a[j][k++]=s[g];
                i=i+n-1;
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<=t;j++)
                printf("%c",a[j][i]);
        }
        printf("\n");
    }
    return 0;
}
