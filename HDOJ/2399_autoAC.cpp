#include<stdio.h>
#include<string.h>
int main()
{
    char s[1000];
    int i,num,flag;
    double t;
    while(gets(s))
    {
        t=0;
        num=0;
        i=0;
        flag=0;
        while(s[i])
        {
            switch(s[i++])
            {
            case 'A':
                t+=4.0;
                num++;
                continue;
            case 'B':
                t+=3.0;
                num++;
                continue;
            case 'C':
                t+=2.0;
                num++;
                continue;
            case 'D':
                t+=1.0;
                num++;
                continue;
            case 'F':
                num++;
                continue;
            case ' ':
                continue;
            default:
                flag=1;
                break;
            }
        }
        if(flag==1)
            printf("Unknown letter grade in input\n");
        else
            printf("%.2lf\n",t/num);
    }
    return 0;
}
