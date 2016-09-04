#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
int tot, sct, lena, lenb, lenc;
char s1[10], s2[10], s3[10], save[10], save0[10], dig[10];
char ss1[10], ss2[10], ss3[10], soso[10];
void solve(int cct)
{
    if(cct >= sct)
    {
        int aa, bb, cc;
        for(int i = 0; i < sct; i++)
        {
            for(int j = 0; j < lena; j++)
                if(ss1[j] == save[i])
                    s1[j] = dig[i];
            for(int j = 0; j < lenb; j++)
                if(ss2[j] == save[i])
                    s2[j] = dig[i];
            for(int j = 0; j < lenc; j++)
                if(ss3[j] == save[i])
                    s3[j] = dig[i];
            sscanf(s1, "%d", &aa);
            sscanf(s2, "%d", &bb);
            sscanf(s3, "%d", &cc);
        }
        if(aa * bb == cc)
            ++tot;
        if(aa - bb == cc)
            ++tot;
        if(aa + bb == cc)
            ++tot;
        if(bb != 0 && aa / bb == cc && aa % bb == 0) 
            ++tot;
        return ;
    }
    int flag;
    if(strlen(save0) && strchr(save0, save[cct]) != NULL)
        flag = 1;
    else
        flag = 0;
    for(int j = flag; j < 10; j++)
        if(strchr(soso, ('0' + j)) == NULL)
        {
            soso[cct] = '0' + j;
            dig[cct] = '0' + j;
            solve(cct + 1);
            soso[cct] = '\0';
        }
    return ;
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int zct = 0;
        tot = sct = 0;
        memset(s1, 0, sizeof(s1));
        memset(s2, 0, sizeof(s2));
        memset(s3, 0, sizeof(s3));
        memset(save, 0, sizeof(save));
        memset(save0, 0, sizeof(save0));
        memset(soso, 0, sizeof(soso));
        scanf("%s%s%s", ss1, ss2, ss3);
        strcpy(s1, ss1);
        strcpy(s2, ss2);
        strcpy(s3, ss3);
        lena = strlen(s1), lenb = strlen(s2), lenc = strlen(s3);
        if(strchr(save0, s1[0]) == NULL && lena > 1)
            save0[zct++] = s1[0];
        if(strchr(save0, s2[0]) == NULL && lenb > 1)
            save0[zct++] = s2[0];
        if(strchr(save0, s3[0]) == NULL && lenc > 1)
            save0[zct++] = s3[0];
        for(int i = 0; i < lena; i++)
            if(strchr(save, s1[i]) == NULL)
                save[sct++] = s1[i];
        for(int i = 0; i < lenb; i++)
            if(strchr(save, s2[i]) == NULL)
                save[sct++] = s2[i];
        for(int i = 0; i < lenc; i++)
            if(strchr(save, s3[i]) == NULL)
                save[sct++] = s3[i];
        solve(0);
        printf("%d\n", tot);
    }
    return 0;
}
