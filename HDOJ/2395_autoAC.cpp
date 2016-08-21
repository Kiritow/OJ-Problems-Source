#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    int i,t;
    char t1[10],t2[10];
    int a1,b1,c1,a2,b2,c2;
    char s1[3],s2[3];
    int p;
    while(scanf("%d",&t)!=EOF)
    {
        for(i=0;i<t;i++)
        {
            scanf("%s %s",&t1,&t2);
            p=0;
            if(strlen(t1)==6)
            {
                a1=t1[0]-'0';
                b1=(t1[2]-'0');
                c1=(t1[3]-'0');
                strcpy(s1,t1+4);
            }
            else
            {
                a1=10*(t1[0]-'0')+(t1[1]-'0');
                b1=(t1[3]-'0');
                c1=(t1[4]-'0');
                strcpy(s1,t1+5);
            }
            if(strlen(t2)==6)
            {
                a2=t2[0]-'0';
                b2=(t2[2]-'0');
                c2=(t2[3]-'0');
                strcpy(s2,t2+4);
            }
            else
            {
                a2=10*(t2[0]-'0')+(t2[1]-'0');
                b2=(t2[3]-'0');
                c2=(t2[4]-'0');
                strcpy(s2,t2+5);
            }
            if(strcmp(s1,s2))
                p++;
            if(abs(a1-a2)<=6)
                p+=abs(a1-a2);
            else
                p+=12-abs(a1-a2);
            if(abs(b1-b2)<=3)
                p+=abs(b1-b2);
            else
                p+=6-abs(b1-b2);
            if(abs(c1-c2)<=5)
                p+=abs(c1-c2);
            else
                p+=10-abs(c1-c2);
            if(p==1)
                printf("Going from %s to %s requires 1 push.\n",t1,t2);
            else
                printf("Going from %s to %s requires %d pushes.\n",t1,t2,p);
        }
    }
    return 0;
}
