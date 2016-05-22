#include <stdio.h>
int main()
{
    int inc;
    scanf("%d",&inc);
    printf("%d %d %d %d \n",inc/1000,(inc%1000)/100,(inc%100)/10,inc%10);
    return 0;
}
