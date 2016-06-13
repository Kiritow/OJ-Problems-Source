#include <stdio.h>
long list[4];
void swap(long* a,long* b)
{
    long tmp=*a;
    *a=*b;
    *b=tmp;
}
 
int main()
{
    scanf("%ld %ld %ld %ld",&list[0],&list[1],&list[2],&list[3]);
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<3;j++)
        {
            if(list[j]>list[j+1])
            {
                swap(&list[j],&list[j+1]);
            }
        }
    }
    printf("%ld %ld %ld %ld\n",list[0],list[1],list[2],list[3]);
    return 0;
}
