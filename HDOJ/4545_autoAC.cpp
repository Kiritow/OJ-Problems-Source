#include<stdio.h>
#include<string.h>
#define N 1005
int main()
{
    char s1[N],s2[N];
    int mark[27][27];
    int i,j;
    int flag;
    int T;
    char x,y;
    scanf("%d",&T);
    int count=1;
    while(T--)
    {
        getchar();
        gets(s1);
        gets(s2);
        int n;
        scanf("%d",&n);
        memset(mark,0,sizeof(mark));
        while(n--)
        {
            getchar();
            scanf("%c %c",&x,&y);
            mark[x-'a'+1][y-'a'+1]=1;
        }
        int ln1,ln2;
        ln1=strlen(s1);
        ln2=strlen(s2);
        i=0;
        j=0;
        flag=0;
        for(i=0;i<ln1;i++)
        {
            if(j==ln2)
                break;
            if(s1[i]==s2[j])
            {
                j++;
                continue;
            }
            while(s2[j]!=s1[i])
            {
                if(j==ln2)
                {
                    flag=1;
                    break;
                }
                if(mark[s2[j]-'a'+1][s1[i]-'a'+1]==1)
                {
                    j++;
                    break;
                }
                else 
                    j++;
            }
        }
        if(!flag)
            printf("Case #%d: happy\n",count++);
        else
            printf("Case #%d: unhappy\n",count++);
    }
    return 0;
}
