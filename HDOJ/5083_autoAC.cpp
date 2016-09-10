#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <vector>
#include <set>
#include <queue>
#pragma comment (linker,"/STACK:102400000,102400000")
#define maxn 1005
#define MAXN 2005
#define mod 1000000009
#define INF 0x3f3f3f3f
#define pi acos(-1.0)
#define eps 1e-6
typedef long long ll;
using namespace std;
char ope[6][5]={{"ADD"},{"SUB"},{"DIV"},{"MUL"},{"MOVE"},{"SET"}};
char code[6][7]={{"000001"},{"000010"},{"000011"},{"000100"},{"000101"},{"000110"}};
char co[31][6]={ {"00001"} , {"00010"} , {"00011"} , {"00100"} , {"00101"} , {"00110"} , {"00111"} , {"01000"} , {"01001"} , {"01010"}
               , {"01011"} , {"01100"} , {"01101"} , {"01110"} , {"01111"} , {"10000"} , {"10001"} , {"10010"} , {"10011"} , {"10100"}
               , {"10101"} , {"10110"} , {"10111"} , {"11000"} , {"11001"} , {"11010"} , {"11011"} , {"11100"} , {"11101"} , {"11110"}
               , {"11111"}};
char s1[5],s2[10];
int OP(char str[])
{
    for (int i=0;i<6;i++)
    {
        if (strcmp(str,ope[i])==0)
            return i;
    }
}
int main()
{
    int n;
    while (~scanf("%d",&n))
    {
        if (n==1)
        {
            scanf("%s%s",s1,s2);
            int x=OP(s1);
            int dd=x;
            printf("%s",code[x]);
            x=s2[1]-'0';
            int ok=0;
            if (isdigit(s2[2]))
            {
                ok=1;
                x=x*10;
                x=x+s2[2]-'0';
            }
            x--;
            printf("%s",co[x]);
            if (dd==5)
            {
                printf("00000\n");
                continue;
            }
            if (ok)
            {
                x=s2[5]-'0';
                if (isdigit(s2[6]))
                {
                    x=x*10;
                    x=x+s2[6]-'0';
                }
            }
            else
            {
                x=s2[4]-'0';
                if (isdigit(s2[5]))
                {
                    x=x*10;
                    x=x+s2[5]-'0';
                }
            }
            x--;
            printf("%s\n",co[x]);
        }
        else if (n==0)
        {
            scanf("%s",s1);
            int len=strlen(s1);
            int t=1;
            int sum=0;
            for (int i=5;i>=0;i--)
            {
                int x=s1[i]-'0';
                sum+=t*x;
                t=t*2;
            }
            if (sum>6||sum==0)
            {
                printf("Error!\n");
                continue;
            }
            sum--;
            int o=sum;
            int flag=sum;
            t=1;
            sum=0;
            for (int i=10;i>=6;i--)
            {
                int x=s1[i]-'0';
                sum+=t*x;
                t=t*2;
            }
            if (sum>31||sum==0)
            {
                printf("Error!\n");
                continue;
            }
            int aa=sum;
            if (flag==5)
            {
                t=1;
                sum=0;
                for (int i=15;i>=11;i--)
                {
                    int x=s1[i]-'0';
                    sum+=t*x;
                    t=t*2;
                }
                if (sum==0)
                {
                    printf("%s",ope[o]);
                    printf(" R%d",aa);
                    printf("\n");
                    continue;
                }
                else
                {
                    printf("Error!\n");
                    continue;
                }
            }
            t=1;
            sum=0;
            for (int i=15;i>=11;i--)
            {
                int x=s1[i]-'0';
                sum+=t*x;
                t=t*2;
            }
            if (sum>31||sum==0)
            {
                printf("Error!\n");
                continue;
            }
            printf("%s",ope[o]);
            printf(" R%d",aa);
            printf(",R%d\n",sum);
        }
    }
    return 0;
}
