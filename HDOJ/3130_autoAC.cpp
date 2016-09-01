#include <cstdio>
#include <cstring>
int main()
{
    for(int i = 100; i <= 999; i++)
    {
        for(int j = 100; j <= 999; j++)
        {
            int t1 = (i-i%10)/10;
            int t2 = j-j/100*100;
            int x1 = i%10;
            int x2 = j/100;
            if(x1==x2 && i/(j*1.0)==t1/(t2*1.0) && i != j)
            {
                printf("%d / %d = %d / %d\n",i,j,t1,t2);
            }
        }
    }
    return 0;
}
