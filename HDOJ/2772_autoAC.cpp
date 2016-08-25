#include <iostream>
int main()
{
    int t,n,min,max_1,max_2,min_1,min_2;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        if(n<=1)
            return 0;
        else if(n==2)
            printf("1 1\n");
        else if(n==3)
            printf("7 7\n");
        else if(n==4)
            printf("4 11\n");
        else if(n==5)
            printf("2 71\n");
        else if(n==6)
            printf("6 111\n");
        else if(n==7)
            printf("8 711\n");
        else if(n==8)
            printf("10 1111\n");
        else if(n==9)
            printf("18 7111\n");
        else if(n==10)
            printf("22 11111\n");
        else if(n==11)
            printf("20 71111\n");
        else if(n==12)
            printf("28 111111\n");
        else if(n==13)
            printf("68 711111\n");
        else if(n==14)
            printf("88 1111111\n");
        else
        {
            max_1=(n-15)/7;
            max_2=(n-14)%7;
            if(max_2==1)
                printf("108");
            else if(max_2==2)
                printf("188");
            else if(max_2==3)
                printf("200");
            else if(max_2==4)
                printf("208");
            else if(max_2==5)
                printf("288");
            else if(max_2==6)
                printf("688");
            else if(max_2==0)
                printf("888");
            if(max_1)
    while(max_1--)
     printf("8");
    printf(" ");
    min_1=n/2-1;
    min_2=n%2;;
    if(min_2==0)
     printf("1");
    else if(min_2==1)
     printf("7");
    while(min_1--)
     printf("1");
    printf("\n");
        }
    }
    return 0;
}
