#include <cstdio>
#include <cstring>
int main()
{
    int t;
    int cas = 0;
    char s[1117];
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        //scanf("%s",s);
        gets(s);
        int len = strlen(s);
        int k = 0;
        int maxx = 0;
        for(int i = 0; i < len; i++)
        {
            if(s[i] == '[')
                k++;
            else
                k--;
            if(k > maxx)
                maxx = k;
        }
        printf("%d %d\n",++cas,1<<maxx);
    }
    return 0;
}
