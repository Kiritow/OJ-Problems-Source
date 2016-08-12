#include<stdio.h>
 int main()
{
    long n,num,cnt,res;
    while(EOF != scanf("%d",&n))
    {
        cnt = 0;
        while(n--)
        {
            scanf("%d",&num);
            if(0 == cnt)
            {
                res = num;
                cnt++;
            }
            else
            {
                if(res == num)
                    cnt++;
                else
                    cnt--;
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
