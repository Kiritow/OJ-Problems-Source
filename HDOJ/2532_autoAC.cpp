#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
struct node
{
    char name[300];
    int cnt;
    int id;
    int len;
} s[1005];
char ss[300];
struct kode
{
    char name[30];
    int len;
} word[15];
struct qode
{
    char name[30];
    int len;
} word2[15];
int cmp(node x,node y)
{
    if(x.cnt==y.cnt)
        return x.id<y.id;
    return x.cnt>y.cnt;
}
int main()
{
    int n,i,j,k,x,y,z,m,len;
    int ll,l_word,flag;
    int ll2,l_word2;
    while(~scanf("%d",&n),n)
    {
        for(i = 0; i<n; i++)
        {
            getchar();
            gets(s[i].name);
            scanf("%d",&s[i].cnt);
            s[i].id = i;
            s[i].len = strlen(s[i].name);
            s[i].name[s[i].len++] = ' ';
            s[i].name[s[i].len] = '\0';
        }
        sort(s,s+n,cmp);
        scanf("%d",&m);
        getchar();
        for(i = 0; i<m; i++)
        {
            gets(ss);
            ll = 0;
            l_word = 0;
            len = strlen(ss);
            ss[len++] = ' ';
            ss[len] = '\0';
            for(j = 0; j<len; j++)
            {
                if(ss[j]>='A' && ss[j]<='Z')
                    ss[j]+=32;
            }
            memset(word,'\0',sizeof(word));
            for(j = 0; j<len; j++)
            {
                if(ss[j]>='a' && ss[j]<='z')
                {
                    word[l_word].name[ll++] = ss[j];
                }
                else if(j>0 && ss[j] == ' ' && ss[j-1]>='a' && ss[j-1]<='z')
                {
                    word[l_word].name[ll] = '\0';
                    word[l_word].len = ll;
                    l_word++;
                    ll = 0;
                }
            }
            for(j = 0; j<n; j++)
            {
                l_word2 = ll2 = 0;
                memset(word2,'\0',sizeof(word2));
                for(k = 0; k<s[j].len; k++)
                {
                    if(s[j].name[k]>='a' && s[j].name[k]<='z')
                    {
                        word2[l_word2].name[ll2++] = s[j].name[k];
                    }
                    else if(s[j].name[k]>='A' && s[j].name[k]<='Z')
                    {
                        word2[l_word2].name[ll2++] = s[j].name[k]+32;
                    }
                    else if(s[j].name[k] == ' ' && s[j].name[k-1]>='a' && s[j].name[k-1]<='z')
                    {
                        word2[l_word2].name[ll2] = '\0';
                        word2[l_word2].len = ll2;
                        l_word2++;
                        ll2 = 0;
                    }
                    else if(s[j].name[k] == ' ' && s[j].name[k-1]>='A' && s[j].name[k-1]<='Z')
                    {
                        word2[l_word2].name[ll2] = '\0';
                        word2[l_word2].len = ll2;
                        l_word2++;
                        ll2 = 0;
                    }
                }
                y = 0;
                x = 0;
                flag = 0;
                while(x<l_word && y<l_word2)
                {
                    if(!strcmp(word[x].name,word2[y].name))
                    {
                        x++;
                        y++;
                        flag++;
                    }
                    else
                    {
                        x = 0;
                        y++;
                        flag = 0;
                    }
                }
                if(flag == l_word)
                {
                    for(z = 0;z<s[j].len-1;z++)
                    printf("%c",s[j].name[z]);
                    printf("\n");
                }
            }
            printf("***\n");
        }
        printf("---\n");
    }
    return 0;
}
