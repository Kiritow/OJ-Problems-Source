#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define sss1 {ans(1);continue;}
#define sss0 {ans(0);continue;}
char s1[20],s2[20];
int p1[16],p2[16],len1,len2;
int a[8],b[8],kk[10] = {0,0,0,14,13,12,11,10,9,8};
int check(char c)
{
    if(c == 'Y')
        return 0;
    if(c == 'X')
        return 1;
    if(c == '2')
        return 2;
    if(c == 'A')
        return 3;
    if(c == 'K')
        return 4;
    if(c == 'Q')
        return 5;
    if(c == 'J')
        return 6;
    if(c == 'T')
        return 7;
    for(int i = '9';i>='3';i--)
    {
        if(c == i)
        return kk[i-'0'];
    }
}
void ans(int i)
{
    if(i==1)
        printf("Yes\n");
    else
        printf("No\n");
}
int Solo()
{
    int i;
    for(i = 0; i<15; i++)
    {
        if(p1[i])
            return 1;
        if(p2[i])
            return 0;
    }
}
int Pair()
{
    int i;
    for(i = 2; i<15; i++)
    {
        if(p1[i]>=2)
            return 1;
        if(p2[i]>=2)
            return 0;
    }
}
int Trio()
{
    int i;
    for(i = 2; i<15; i++)
    {
        if(p1[i]>=3)
            return 1;
        if(p2[i]>=3)
            return 0;
    }
}
int Bomb()
{
    int i;
    for(i = 2; i<15; i++)
    {
        if(p1[i]>=4)
            return 1;
        if(p2[i]>=4)
            return 0;
    }
}
int main()
{
    int t,i,j;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s%s",s1,s2);
        len1 = strlen(s1);
        len2 = strlen(s2);
        memset(p1,0,sizeof(p1));
        memset(p2,0,sizeof(p2));
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for(i = 0; i<len1; i++)
            p1[check(s1[i])]++;
        for(i = 0; i<len2; i++)
            p2[check(s2[i])]++;
        for(i = 0; i<15; i++)
        {
            a[p1[i]] = 1;
            b[p2[i]] = 1;
        }
        int flag = 0;
        if(p1[0]&&p1[1] || len1 == 1 || (a[2]&&len1==2) || (a[3]&&len1==3) || (a[4]&&len1==4) || (a[3]&&len1==4) || (a[3]&&a[2]&&len1==5) || (a[4]&&len1==6))
        sss1;
        if(p2[0] && p2[1])
        sss0;
        if(a[4] && !b[4])
        sss1;
        if(b[4] && !a[4])
        sss0;
        if(a[4] && b[4])
        {
            if(Bomb())
            sss1
            else
            sss0
        }
        if(a[3] && !b[3])
        sss1;
        if(a[3] && b[3])
        {
            if(Trio())
            sss1
            else
            {
                if(len1 >= 4 && len2<4)
                sss1
                else if(a[2] && (!b[2]||len2<5))
                sss1
            }
        }
        if(a[2] && !b[2] && !b[3])
        sss1
        if(a[2] && (b[2]||b[3]))
        {
            if(Pair())
            sss1
        }
        if(Solo())
        sss1
        sss0
    }
    return 0;
}
