#include <cstring>
#include <cstdio>
#include <cstdlib>
int c[26];
char buff[1024];
int main()
{
    int n;
    while(scanf("%d%*c",&n)==1)
    {
        gets(buff);
        memset(c,0,sizeof(int)*26);
        for(int i=0;i<n;i++)
        {
            if(buff[i]>='A'&&buff[i]<='Z')
            {
                ++c[buff[i]-'A'];
            }
            else
            {
                ++c[buff[i]-'a'];
            }
        }
        bool flag=true;
        for(int i=0;i<26;i++)
        {
            if(c[i]<1) flag=false;
        }
        if(!flag)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
        }
    }
    return 0;
}
