#include<iostream>
#include<cctype>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
    char s[4100];
    while(gets(s))
    {
        int len=strlen(s);
        int line;
        if(len%16==0)line=len/16;
        else line=len/16+1;
        for(int i=0;i<line;i++)
        {
            int count=0;
            printf("%.4x: ",i<<4);
            for(int j=i*16;s[j]&&j<i*16+16;j++)
            {
                printf("%.2x",s[j]);
                count+=2;
                if(j&1){putchar(' ');count++;}
            }
            while(count++<40)putchar(' ');
            for(int j=i*16;s[j]&&j<i*16+16;j++)
            {
                if(islower(s[j]))
                putchar(toupper(s[j]));
                else
                putchar(tolower(s[j]));
            }
            printf("\n");
        }
    }
    return 0;
}
