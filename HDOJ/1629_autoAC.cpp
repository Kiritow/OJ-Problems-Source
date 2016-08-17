#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
using namespace std;
struct Card
{
    char num;
    char flower;
    int num_flag;
};
Card p[5],q[5];
char  str[]= {'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
string s_name[9]= {"straight-flush","four-of-a-kind","full-house","flush",
        "straight","three-of-a-kind","two-pairs","one-pair","highest-card"
                  };
int flag[15],count,value[15], solve_flag[10];
void solve(Card *r,int x)
{
    if(solve_flag[0]) return;
    int flag_flush(0);
    memset(value,0,sizeof(value));
    memset(flag,0,sizeof(flag));
    for(int j=0; j<13; j++)
        if(r[0].num==str[j])
        {
            flag[j]=1;
            if(!j) flag[13]=1;
            value[j]++;
            break;
        }
    for(int i=1; i<5; i++)
    {
        if(r[i-1].flower!=r[i].flower) flag_flush=1;
        for(int j=0; j<13; j++)
            if(r[i].num==str[j])
            {
                flag[j]=1;
                if(!j) flag[13]=1;
                value[j]++;
                break;
            }
    }
    if(!flag_flush) solve_flag[3]=1;
    int y(0),v(0);
    if(flag[0])
    {
        for(int i=0; i<5; i++)
            if(flag[i]) y++;
        if(y==5&&!flag_flush)
        {
            solve_flag[0]=1;
            return;
        }
        if(y==5&&flag_flush) solve_flag[4]=1;
    }
    y=0;
    for(int i=1; i<14; i++)
    {
        if(flag[i]) y++;
        if(y==5&&!flag_flush)
        {
            solve_flag[0]=1;
            return;
        }
        if(y==5&&flag_flush)
        {
            solve_flag[4]=1;
            break;
        }
        if(y>=1&&!flag[i]) break;
    }
    y=v=0;
    for(int i=0; i<14; i++)
        if(value[i]>=4) solve_flag[1]=1;
        else if(value[i]==3) v++;
        else if(value[i]==2) y++;
    if(v&&y==1) solve_flag[2]=1;
    if(v&&!y) solve_flag[5]=1;
    if(!v&&y==2) solve_flag[6]=1;
    if(!v&&y==1) solve_flag[7]=1;
    if(x<count)
        for(int i=0; i<5; i++)
            if(!r[i].num_flag)
            {
                Card m[5];
                for(int j=0; j<5; j++) m[j]=r[j];
                m[i]=q[x];
                m[i].num_flag=1;
                solve(m,x+1);
            }
}
int main()
{
    char c,s[100];
    count=0;
    while(scanf("%c",&c)!=EOF)
    {
        if(c=='\n'||count>9)
        {
            if(c!='\n') gets(s);
            count=count-5;
            printf("Hand: ");
            for(int i=0; i<5; i++) printf("%c%c ",p[i].num,p[i].flower);
            printf("Deck: ");
            for(int i=0; i<count; i++) printf("%c%c ",q[i].num,q[i].flower);
            if(c!='\n') printf("%s ",s);
            printf("Best hand: ");
            memset(solve_flag,0,sizeof(solve_flag));
            solve_flag[8]=1;
            solve(p,0);
            for(int i=0; i<9; i++)
                if(solve_flag[i])
                {
                    cout<<s_name[i]<<endl;
                    break;
                }
            count=0;
        }
        else if(c!=' ')
        {
            Card k;
            k.num=c;
            scanf("%c",&c);
            k.flower=c;
            k.num_flag=0;
            if(count<=4) p[count]=k;
            else q[count-5]=k;
            count++;
        }
    }
    return 0;
}
