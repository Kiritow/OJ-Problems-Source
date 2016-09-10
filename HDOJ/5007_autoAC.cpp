#include<cstdio>
#include<cstring>
char str[20000];
int main()
{
    int i;
    while(gets(str))
    {
        int len=strlen(str);
        for(i=0; i<len; i++)
        {
            if(str[i]=='A' && str[i+1]=='p' && str[i+2]=='p' && str[i+3]=='l' && str[i+4]=='e')
            {
                printf("MAI MAI MAI!\n");
            }
            if(str[i]=='i' && str[i+1]=='P' && str[i+2]=='h' && str[i+3]=='o' && str[i+4]=='n'&&str[i+5] == 'e')
            {
                printf("MAI MAI MAI!\n");
            }
            if(str[i]=='i' && str[i+1]=='P' && str[i+2]=='a' && str[i+3]=='d')
            {
                printf("MAI MAI MAI!\n");
            }
            if(str[i]=='i' && str[i+1]=='P' && str[i+2]=='o' && str[i+3]=='d')
            {
                printf("MAI MAI MAI!\n");
            }
            if(str[i]=='S' && str[i+1]=='o' && str[i+2]=='n' && str[i+3]=='y')
            {
                printf("SONY DAFA IS GOOD!\n");
            }
        }
    }
    return 0;
}
