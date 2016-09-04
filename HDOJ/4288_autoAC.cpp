#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int n;
int a[100005],len;
char str[10];
__int64 sum;
int main()
{
    int i,j,k;
    while(~scanf("%d",&n))
    {
        len = 0;
        while(n--)
        {
            scanf("%s",str);
            if(!strcmp(str,"add"))
            {
                scanf("%d",&k);
                for(i = len++; i>0; i--)
                {
                    if(a[i-1]>k)
                        a[i] = a[i-1];
                    else
                        break;
                }
                a[i] = k;
            }
            else if(!strcmp(str,"del"))
            {
                scanf("%d",&k);
                for(i = 0; i<len; i++)
                    if(a[i] == k)
                        break;
                for(; i<len; i++)
                    a[i] = a[i+1];
                len--;
            }
            else if(!strcmp(str,"sum"))
            {
                sum = 0;
                for(i = 2; i<len; i+=5)
                    sum+=a[i];
                printf("%I64d\n",sum);
            }
        }
    }
    return 0;
}
