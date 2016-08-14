#include<stdio.h>
#include<string.h>
char Morse[26][5]={{".-"},{"-..."},{"-.-."},{"-.."},
{"."},{"..-."},{"--."},{"...."},{".."},{".---"},{"-.-"},{".-.."},
{"--"},{"-."},{"---"},{".--."},{"--.-"},{".-."},{"..."},{"-"},
{"..-"},{"...-"},{".--"},{"-..-"},{"-.--"},{"--.."}};
char Dict[10005][205];
int dp[40005];
int main()
{
    int T, i, n, len, j, a;
    char str[10270], str2[270];
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",str);
        len = strlen(str);
        scanf("%d",&n);
        memset(dp,0,sizeof(dp));
        for(i=0; i<n; i++)
        {
            Dict[i][0]=NULL;
            scanf("%s",str2);
            for(j=0; str2[j]; j++)
                strcat(Dict[i],Morse[str2[j]-'A']);
        }
        dp[0] = 1;
        for(i=0; i<len; i++)
        {
            if(dp[i])
            {
                for(j=0; j<n; j++)
                {
                    a = strlen(Dict[j]);
                    if(strncmp(str+i,Dict[j],a) == 0)
                        dp[i+a] += dp[i];
                }
            }
        }
        printf("%d\n",dp[len]);
    }
    return 0;
}
