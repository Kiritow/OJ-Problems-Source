#include <cstdio>
int cnt[26];

int main()
{
    char c;
    while((c=fgetc(stdin))!='#')
    {
        if(c>='a'&&c<='z')
        {
            ++cnt[c-'a'];
        }
    }
    for(int i=0;i<26;i++)
    {
        printf("%c %d\n",i+'a',cnt[i]);
    }
    return 0;
}
