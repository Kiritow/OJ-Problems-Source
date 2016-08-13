#include<stdio.h>
#include<string.h>
char str[28][11111][11];
int main()
{
    char s[11],tem[11];
    int i=0,j,num[28];
    int count;
    int len;
    memset(num,0,sizeof(num));
    while(gets(tem)&&strcmp(tem,"")!=0)
    {
     int r=tem[0]-96;   strcpy(str[r][num[r]++] , tem);
    }
   while(scanf("%s",s)!=EOF)
    {
        count=0;int r=s[0]-96;
        len=strlen(s);
        for(j=0;j<num[r];j++)
        {
            if(memcmp(str[r][j],s,len)==0)
                count++;
        }
        printf("%d\n",count);
    }
    return 0;
}
