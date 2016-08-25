#include <stdio.h>
#include <string.h>
int main()
{
    char key[28],str[84];
    while(scanf("%s",key)!=EOF)
    {
        getchar();
        gets(str);
        int i,len;
        len=strlen(str);
        for(i=0;i<len;i++)
        {
            if(str[i]>='A'&&str[i]<='Z')
            {
                str[i]=key[str[i]-'A']-'a'+'A';
            }
            else if(str[i]>='a'&&str[i]<='z')
            {
                str[i]=key[str[i]-'a'];
            }
        }
        printf("%s\n",str);
    }
    return 0;
}
