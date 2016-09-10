#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
char str[5000000],s[5000000];
int main()
{
    int n,i,j;
    int cnt1,cnt2,flag1,flag2,len;
    __int64 sum;
    while(scanf("%d",&n)!=EOF)
    {
        gets(str);
        len = 0;
        for(i = 0; i<n; i++)
        {
            gets(str);
            int l = strlen(str);
            for(j = 0; j<l; j++)
            {
                s[len] = str[j];
                len++;
            }
        }
        flag1 = flag2  = cnt1 = cnt2 = 0;
        sum = 1;
        for(i = 0; i<len; i++)
        {
            if(s[i] == '{')
                flag1 = 1;
            else if(flag1 && s[i] == '|')
                cnt1++;
            else if(flag1 && s[i] == '}')
            {
                flag1 = 0;
                sum*=(cnt1+1);
                cnt1 = 0;
            }
            else if(s[i] == '$' && flag2 == 0)
                flag2 = 1;
            else if(s[i] == '$' && flag2 == 1)
            {
                sum = sum*(cnt2+1);
                cnt2 = 0;
                flag2 = 0;
            }
            else if(flag2 && s[i] == ' ')
                cnt2++;
            else if(flag2 && s[i] != ' ' && s[i]!='$')
            {
                sum = sum*(cnt2+1);
                cnt2 = 0;
            }
            if(sum>100000)
                break;
        }
        if(sum>100000)
            printf("doge\n");
        else
            printf("%I64d\n",sum);
    }
    return 0;
}
