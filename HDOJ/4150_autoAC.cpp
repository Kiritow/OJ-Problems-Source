#include<stdio.h>
#include<string.h>
int main()
{
    char a[1000001],b[100001];
    int s,i,j,p,count,len1,len2;
    scanf("%d",&s);
    while(s--)
    {
        count=0;
        scanf("%s %s",a,b);
        len1=strlen(a);
        len2=strlen(b);
        for(i=0;i<=len1-1;i++)
        {
            p=i;
            for(j=0;j<=len2-1;j++)
            {
                if(a[p]==b[j]) {p++;}
                else
                    break;
            }
            if(j==len2)
            {
                count++;
                i=i+len2-1;
            }
        }
        printf("%d\n",count);
    }
    return 0;
}
