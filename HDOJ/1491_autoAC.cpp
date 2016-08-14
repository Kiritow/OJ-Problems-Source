#include <stdio.h>
int main ()
{
    int  n,month,day;
    scanf ("%d",&n);
    while (n--)
    {
        scanf ("%d%d",&month,&day);
        switch(month)
        {
        case 10 :
            if (day<21)
            {
                printf ("%d\n",21-day);
                break;
            }
            else if(day==21) 
            {
                printf ("It's today!!\n");
                break;
            }
            else  
            {
                printf("What a pity, it has passed!\n");
                break;
            }        
        case 9 :
            printf ("%d\n",30+21-day);
            break;
        case 8 :
            printf ("%d\n",31+30+21-day);
            break;
        case 7:
            printf ("%d\n",31+31+30+21-day);
            break;
        case 6 :
            printf ("%d\n",30+31+31+30+21-day);
            break;
        case 5:
            printf ("%d\n",31+30+31+31+30+21-day);
            break;
        case 4:
            printf ("%d\n",30+31+30+31+31+30+21-day);
            break;
        case 3:
            printf ("%d\n",31+30+31+30+31+31+30+21-day);
            break;
        case 2:
            printf ("%d\n",28+31+30+31+30+31+31+30+21-day);
            break;
        case 1:
            printf ("%d\n",31+28+31+30+31+30+31+31+30+21-day);
            break;
        default:
            printf ("What a pity, it has passed!\n");
            break;
        }
    }
    return 0;
}
