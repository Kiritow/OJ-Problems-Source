# include <stdio.h>
# include <string.h>
int ACL[30], out[30][2] ;
char str[100] ;
char entity[100], right[100] ;
void gao(char s[])
{
    char *p = s, op ;
    int ent, rit, i, j ;
    memset (ACL, 0, sizeof(ACL)) ;
    while (*p)
    {
        sscanf (p, "%[A-Z]%c%[a-z]%*c", entity, &op, right) ;
        p += strlen(entity) + strlen(right) + 2 ;
        for (i = 0 ; entity[i] ; i++)
        {
            ent = entity[i]-'A' ;
            for (rit = 0, j = 0 ; right[j] ; j++) rit |= (1<<(right[j]-'a')) ;
            if (op == '+') ACL[ent] |= rit ;
            else if (op == '-') ACL[ent] &= ~rit ;
            else //op == '='
                ACL[ent] = rit ;
        }
    }
}
int main ()
{
    int nCase = 1 ;
    int i, j, cnt ;
    while (~scanf ("%s", str) && strcmp(str, "#"))
    {
        gao(str) ;
        memset (str, 0, sizeof(str)) ;
        printf ("%d:", nCase++) ;
        for (i = 0, cnt = 0 ; i < 26 ; i++) if (ACL[i])
            out[cnt][0] = i, out[cnt++][1] = ACL[i] ;
        for (i = 0 ; i < cnt ; i++)
        {
            printf ("%c", out[i][0]+'A') ;
            if (i==cnt-1 || (i<cnt-1 && out[i][1] != out[i+1][1]))
                for (j = 0 ; j < 26 ; j++) if (out[i][1] & (1<<j))
                    printf ("%c", j+'a') ;
        }
        printf ("\n") ;
    }
    return 0 ;
}
