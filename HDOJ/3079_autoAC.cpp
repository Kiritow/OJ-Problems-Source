#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,t;
    char str[55];
    while(scanf("%d",&t)!=EOF)
    {
        for(i=0;i<t;i++)
        {
            scanf("%s",str);
            for(j=0;str[j]!='\0';j++)
            {
                if(str[j]=='a' || str[j]=='e' || str[j]=='i' || str[j]=='o' || str[j]=='u')
                    str[j]-=32;
                else
                    if(str[j]!='A' && str[j]!='E' && str[j]!='I' && str[j]!='O' && str[j]!='U' && str[j]>='A' && str[j]<='Z')
                        str[j]+=32;
            }
            printf("%s\n",str);
        }
    }
    return 0;
}
