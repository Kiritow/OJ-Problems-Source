#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define mem(a,b) memset(a,0,sizeof(a))
#define L 1000005
#define up(i,x,y) for(i = x;i<=y;i++)
#define down(i,x,y) for(i = x;i>=y;i--)
#define bre(x,y) if(x){flag=y;break;}
#define con(x,y) if(x){ans(y);continue;}
char s[L];
int a[L][2],b[L][2],len,flag;
void ans(int i)
{
    if(i==1) printf("Unique\n");
    else if(i==2) printf("Many\n");
    else printf("None\n");
}
int main()
{
    int i,j;
    while(~scanf("%s",s+1))
    {
        len = strlen(s+1);
        con((len&1),0)
        mem(a,0);
        mem(b,0);
        flag = 1;
        up(i,1,len)
        {
            if(s[i]=='(')
                a[i][0]=a[i-1][0]+1,a[i][1]=a[i-1][1]+1;
            else if(s[i]==')')
            {
                if(!a[i-1][0])
                    a[i][0]=1;
                else
                    a[i][0]=a[i-1][0]-1;
                a[i][1]=a[i-1][1]-1;
            }
            else if(s[i]=='?')
            {
                if(!a[i-1][0]) a[i][0]=1;
                else
                    a[i][0]=a[i-1][0]-1;
                a[i][1]=a[i-1][1]+1;
            }
            bre((a[i][0]>a[i][1]),0)
        }
        con((!flag),0)
        down(i,len,1)
        {
            if(s[i]==')')
                b[i-1][0]=b[i][0]+1,b[i-1][1]=b[i][1]+1;
            else if(s[i]=='(')
            {
                if(!b[i][0])
                    b[i-1][0]=1;
                else
                    b[i-1][0]=b[i][0]-1;
                b[i-1][1]=b[i][1]-1;
            }
            else if(s[i]=='?')
            {
                if(!b[i][0]) b[i-1][0]=1;
                else
                    b[i-1][0]=b[i][0]-1;
                b[i-1][1]=b[i][1]+1;
            }
            bre((b[i][0]>b[i][1]),0)
        }
        con((!flag),0)
        int l,r;
        flag = 1;
        up(i,1,len)
        {
            l = max(a[i][0],b[i][0]);
            r = min(a[i][1],b[i][1]);
            bre((l>r),0)
            bre((l<r),2)
        }
        con((flag==0),0);
        con((flag==1),1);
        con((flag==2),2);
    }
    return 0;
}
