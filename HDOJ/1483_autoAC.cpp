#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 10010;
struct node
{
    char word[110];
    int lenword;
}dic[MAX];
char qu[1010];
int Judge(char *a, char *b, int len)
{
    int i= 0, count = 0, j = 0;
    while (i < len && j < len - 1)
    {
        if (a[i] == b[j])
        {
            i ++;
            j ++;
        }
        else
        {
            count ++;
            i ++;
        }
    }
    if (j == len - 1 && count == 0)
    {
        return 1;
    }
    if (count == 1)
    {
        return 1;
    }
    return 0;
}
int main()
{
    int n, i, m, j, lenqu, flag, k, count;
    scanf("%d", &n);
    for (i = 0; i < n; ++i)
    {
        scanf("%s", dic[i].word);
        dic[i].lenword = strlen(dic[i].word);
    }
    scanf("%d", &m);
    for (i = 0; i < m; ++i)
    {
        flag = 0;
        scanf("%s", qu);
        lenqu = strlen(qu);
        for (j = 0; j < n; ++j)
        {
            if (strcmp (dic[j].word, qu) == 0)
            {
                flag = 1;
                printf("%s is correct\n", qu);
                break;
            }
        }
        if (!flag)
        {
            for (j = 0; j < n; ++j)
            {
                if (dic[j].lenword == lenqu)
                {
                    int com[110] = {0};
                    count = 0;
                    for (k = 0; k < lenqu; ++k)
                    {
                        if (dic[j].word[k] != qu[k])
                        {
                            count ++;
                            com[count] = k;
                        }
                    }
                    if (count == 1)
                    {
                        flag = 1;
                    }
                    if (count == 2)
                    {
                        if (dic[j].word[com[1]] == qu[com[2]] && dic[j].word[com[2]] == qu[com[1]] && com[2] - com[1] == 1)
                        {
                            flag = 1;
                        }
                    }
                }
                else if (dic[j].lenword - 1 == lenqu)
                {
                    flag = Judge(dic[j].word, qu, dic[j].lenword);
                }
                else if (dic[j].lenword + 1 == lenqu)
                {
                    flag = Judge(qu, dic[j].word, lenqu);
                }
                if (flag)
                {
                    printf("%s is a misspelling of %s\n", qu, dic[j].word);
                    break;
                }
            }
        }
        if (!flag)
        {
            printf("%s is unknown\n", qu);
        }
    }
    return 0;
}
