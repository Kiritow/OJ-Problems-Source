#include<stdio.h>
long long save[30]={1};
void work()
{
    for(int i=1;i<30;i++)
       save[i]=save[i-1]*3;
}
int main()
{
    int test,n;
    work();
    scanf("%d",&test);
    while(test--)
    {
     scanf("%d",&n);
     printf("%I64d\n",save[n]);
    }
    return 0;
}
