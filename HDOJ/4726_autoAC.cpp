#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
int a[20];
int b[20];
char A[2000020],B[2000020];
int num1[2000020],num2[2000020];
int ans[2000020];
int main()
{
    int T;
    int iCase = 0;
    scanf("%d",&T);
    while(T--)
    {
        iCase++;
        scanf("%s%s",A,B);
        int n = strlen(A);
        for(int i = 0;i < n;i++)
        {
            num1[i] = A[i] - '0';
            num2[i] = B[i] - '0';
        }
        if(n == 1)
        {
            printf("Case #%d: %d\n",iCase,(num1[0]+num2[0])%10);
            continue;
        }
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for(int i = 0;i < n;i++)
        {
            a[num1[i]] ++;
            b[num2[i]] ++;
        }
        int x = 0, y = 0;
        int ttt = -1;
        for(int i = 1;i <= 9;i++)
            for(int j = 1;j <= 9;j++)
                if(a[i] && b[j] && ((i+j)%10) > ttt )
                {
                    x = i;
                    y = j;
                    ttt = (x+y)%10;
                }
        a[x]--;
        b[y]--;
        int cnt = 0;
        ans[cnt++] = (x+y)%10;
        for(int p = 9;p >= 0;p--)
        {
            for(int i = 0;i <= 9;i++)
                if(a[i])
                {
                    if(i <= p)
                    {
                        int j = p-i;
                        int k = min(a[i],b[j]);
                        a[i] -= k;
                        b[j] -= k;
                        while(k--)
                            ans[cnt++] = p;
                    }
                    int j = 10 + p - i;
                    if(j > 9)continue;
                    int k = min(a[i],b[j]);
                    a[i] -= k;
                    b[j] -= k;
                    while(k--)
                        ans[cnt++] = p;
                }
        }
        printf("Case #%d: ",iCase);
        int s = 0;
        while(s < cnt-1 && ans[s] == 0)s++;
        for(int i = s;i < cnt;i++)
            printf("%d",ans[i]);
        printf("\n");
    }
    return 0;
}
