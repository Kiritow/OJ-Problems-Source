#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
typedef char big[105];
big now,now2,now3,time,ans,ans2,now4;/*now2:now3*now,
                now3:time^now4*/
int l;
void smlt1(char *a,char *b,char *c)
{
    int static i;
    void smlt2(char *a,int b,char *c,int num);
    memset(c,'0',sizeof(char)*104); *(c+104) = 0;
    for (i = 0;*(b+i) && i < 105;i++)
        smlt2(a,(*(b+i))-'0',c+i,i);
    *(c+104) = 0;
}
void smlt2(char *a,int b,char *c,int num)
{
    int static tmp1,tmp2;
    tmp1 = tmp2 = 0;
    while ((*a) && (num < l)) {
        tmp1 = (*a)-'0';
        tmp2 += tmp1*b;
        if (*c) {
            tmp2 = tmp2-'0'+*c;
            *c = '0'+tmp2%10;
        } else {
            *c = '0'+tmp2%10;
        }
        tmp2 /= 10;
        a++,c++;
        num++;
    }
    while ((tmp2) && (num < l)) {
        if (*c) {
            tmp2 = tmp2-'0'+*c;
            *c = '0'+tmp2%10;
        } else {
            *c = '0'+tmp2%10;
        }
        tmp2 /= 10;
        c++;
        num++;
    }
}
int check(int k)
{
    smlt1(now4,time,now3);
    strcpy(now4,now3);
    smlt1(now3,now,now2);
    if (now[k] == now2[k])
        return 1;
    else
        return 0;
}

void print_big(char *s)
{
    char *p;
    p = strlen(s)+s-1;
    while (p > s) {
        if ((*p) != '0')
            break;
        p--;
    }
    while (p >= s) {
        printf("%c",*p);
        p--;
    }
    printf("\n");
}

void clear1(char *s)
{
    memset(s,0,sizeof(char)*105);
    *s = '1';
}

int main()
{
    int i,j;

    void init();

    init();
    for (i = 0;i < l;i++) {
        strcpy(time,now3);
        clear1(now4);
        for (j = 1;j <= 10;j++)
            if (check(i) == 1)
                break;
        if (j != 11) {
            memset(ans2,0,sizeof(char)*105);
            smlt2(ans,j,ans2,0);
            strcpy(ans,ans2);
            if (i == l-1)
                break;
        } else {
            printf("-1\n");
            return 0;
        }
    }
    print_big(ans);
    return 0;
}

void reverse(char *s)
{
    char *p,ch;
    p = strlen(s)+s-1;
    while (p > s) {
        ch = *p; *p = *s; *s = ch;
        p--; s++;
    }
}

void init()
{
    memset(now2,0,sizeof(char)*105);
    memset(now3,0,sizeof(char)*105);
    memset(time,0,sizeof(char)*105);
    memset(ans,0,sizeof(char)*105);
    memset(ans2,0,sizeof(char)*105);
    memset(now4,0,sizeof(char)*105);
    scanf("%s",now);
    reverse(now);
    strcpy(now3,now); strcpy(now2,now);
    scanf("%d",&l);
    memset(ans,'0',sizeof(ans));
    ans[0] = '1'; ans[104] = 0;
    ans2[0] = '1'; ans2[104] = 0;
}
