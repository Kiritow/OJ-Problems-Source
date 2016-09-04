#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;
int a[16];
int main()
{
    int T;
    int iCase=0;
    int now;
    int Alice,Bob;
    scanf("%d",&T);
    while(T--)
    {
        iCase++;
        printf("Case #%d: ",iCase);
        for(int i=1;i<=15;i++)
          scanf("%d",&a[i]);
        Alice=Bob=0;
        now=1;
        if(a[15]%2==0)
        {
            Alice+=a[15]/2;
            Bob+=a[15]/2;
        }
        else
        {
            Alice+=a[15]/2+1;
            Bob+=a[15]/2;
            now=2;
        }
        int tempa=a[5]+a[6];
        int tempb=a[3]+a[4];
        if(tempa==tempb)
        {
            Alice+=tempa;
            Bob+=tempb;
        }
        else if(tempa<tempb)
        {
            Alice+=tempa;
            Bob+=tempa;
            tempb-=tempa;
            if(tempb%2==0)
            {
                Bob+=tempb/2;
            }
            else
            {
                if(now==1)
                {
                    now=2;
                    Bob+=tempb/2;
                }
                else
                {
                    now=1;
                    Bob+=tempb/2+1;
                }
            }
        }
        else
        {
            Alice+=tempb;
            Bob+=tempb;
            tempa-=tempb;
            if(tempa%2==0)
            {
                Alice+=tempa/2;
            }
            else
            {
                if(now==1)
                {
                    now=2;
                    Alice+=tempa/2+1;
                }
                else
                {
                    now=1;
                    Alice+=tempa/2;
                }
            }
        }
        int temp=a[11]+a[12]+a[13]+a[14];
        if(temp%2==0)
        {
            Alice+=0;
            Bob+=0;
        }
        else
        {
            if(now==1)
            {
                now=2;
            }
            else
            {
                now=1;
            }
        }
        tempa=a[7]+a[8];
        tempb=a[9]+a[10];
        if(tempa==tempb)
        {
            Alice+=0;
            Bob+=0;
        }
        else if(tempa<tempb)
        {
            Alice+=0;
            Bob+=0;
            tempb-=tempa;
            if(tempb%2==0)
            {
                Bob+=tempb/2;
            }
            else
            {
                if(now==1)
                {
                    now=2;
                    Bob+=tempb/2+1;
                }
                else
                {
                    now=1;
                    Bob+=tempb/2;
                }
            }
        }
        else
        {
            tempa-=tempb;
            if(tempa%2==0)
            {
                Alice+=tempa/2;
            }
            else
            {
                if(now==1)
                {
                    now=2;
                    Alice+=tempa/2;
                }
                else
                {
                    now=1;
                    Alice+=tempa/2+1;
                }
            }
        }
        Alice+=2*a[1];
        Bob+=2*a[2];
        if(now==1)
        {
            if(Bob>=Alice)printf("Bob\n");
            else printf("Alice\n");
        }
        else
        {
            if(Alice>=Bob)printf("Alice\n");
            else printf("Bob\n");
        }
    }
    return 0;
}
