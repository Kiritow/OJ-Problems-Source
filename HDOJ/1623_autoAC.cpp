#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAXN 400
char title[204][MAXN];
char keyword[52][14]; 
typedef struct charter{
    char character[MAXN]; 
    int rank; 
    int start, end; 
}charter;
charter mes[3004];
int dealenter(char *temp)
{
    int len = strlen(temp);
    if(temp[len-1] == '\n') temp[len-1] = ' ';
    else temp[len++] = ' ', temp[len] = '\0';
    return 0;
}
int calculate(int n1, int n2, int n3)
{
    int i, j, k, flag;
    charter temp;
    for(i=0; i<n3-1; ++i)
    {
        flag = 1;
        for(j=0; j<n3-1-i; ++j)
        {
            if(strcmp(mes[j].character, mes[j+1].character) > 0)
            {
                flag = 0;
                temp = mes[j], mes[j] = mes[j+1], mes[j+1] = temp;
            }
        }
        if(flag) break;
    }
    return 0;
}
int shuai(int n1, char *from)
{
    int i, j, flag = 0;
    for(i=0; i<n1; ++i)
    {
        if(strcmp(keyword[i], from) == 0) {flag = 1; break;}
    }
    return flag;
}
int lastline(int n1, int n2, int n3)
{
    int i, j, k, t, flag, len, start, end;
    for(i=0; i<n3; ++i)
    {
        if(!shuai(n1, mes[i].character))
        {
            j = mes[i].rank;
            start = mes[i].start, end = mes[i].end;
            for(t=0; t<start; ++t)
            printf("%c", title[j][t]);
            len = strlen(mes[i].character);
            for(k=0; k<len; ++k)
                printf("%c", mes[i].character[k] - ('a' - 'A'));
            len = strlen(title[j]);
            for(k=end+1; k<len; ++k)
               printf("%c", title[j][k]);
               printf("\n");
        }
    }
}
int main()
{
    int  i, j, t, k, n, m, count, cnt3, cnt1, cnt2, cnt4, flag, flag2, len, doc;
    char temp[MAXN];
    flag = cnt1 = cnt2 = cnt3 = 0;
    while(fgets(temp, MAXN, stdin) != NULL)
    {
        dealenter(temp);
        len = strlen(temp);
        if(strcmp(temp, ":: ") == 0) flag = 1;
        else if(!flag)
            {
                strcpy(keyword[cnt1], temp);
                keyword[cnt1++][len-1] = '\0';
            }
        else
        {
            for(i=0,flag2=cnt4=0,doc=-1; i<len; ++i)
            {
                if(temp[i] != ' ')
                {
                    if(doc == -1) doc = i;
                    if(isupper(temp[i])) mes[cnt3].character[cnt4++] = temp[i] = towlower(temp[i]);
                    else mes[cnt3].character[cnt4++] = temp[i];
                    flag2 = 1;
                }
                else if(flag2)
                {
                    mes[cnt3].rank = cnt2, mes[cnt3].start = doc, mes[cnt3].end = i-1;
                    mes[cnt3].character[cnt4] = '\0';
                    cnt3++, cnt4 = 0;
                    flag2 = 0, doc = -1;
                }
            }
                strcpy(title[cnt2], temp);
                title[cnt2++][len-1] = '\0';
        }
    }
    calculate(cnt1, cnt2, cnt3);
    lastline(cnt1, cnt2, cnt3);
    return 0;
}
