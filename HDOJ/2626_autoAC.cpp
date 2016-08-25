#include<stdio.h>
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("Samuel will ");
        switch(n)
        {
            case 13:printf("take test.\n");break;
            case 9:printf("buy food.\n");break;
            case 5:printf("meet friends.\n");break;
            case 1:printf("decorate.\n");break;
            case -3:printf("visit relative.\n");break;
            case 12:printf("go home.\n");break;
            case 8:printf("stay at home.\n");break;
            case 4:printf("go to movies.\n");break;
            case 0:printf("go out.\n");break;
            case -4:printf("visit relative.\n");break;
            case 11:printf("stay at home.\n");break;
            case 7:printf("visit teachers.\n");break;
            case 3:printf("stay at home.\n");break;
            case -1:printf("be in the park.\n");break;
            case -5:printf("stay at home.\n");break;
            case 10:printf("buy clothes.\n");break;
            case 6:printf("go to KTV.\n");break;
            case 2:printf("decorate.\n");break;
            case -2:printf("stay at home.\n");break;
            case -6:printf("prepare dinner.\n");break;
        }
    }
    return 0;
}
