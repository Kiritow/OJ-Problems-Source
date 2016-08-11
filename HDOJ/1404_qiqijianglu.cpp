/*
HDU 1404
*/
#include<stdio.h>
#include<math.h>
#include<iostream>
#include<string.h>
using namespace std;

const int MAXN=1000000;
int sg[MAXN];
int get_length(int n)//得到整数n的位数
{
    if(n/100000) return 6;
    if(n/10000) return 5;
    if(n/1000)  return 4;
    if(n/100)   return 3;
    if(n/10)  return 2;
    return 1;
}

void _extend(int n)//sg[n]=0;表示n为后者必胜
                   //那么所以可以一步变成n的都是前者必胜
{
    int len=get_length(n);
    int i;
    for(i=len;i>=1;i--)//每一个位上加上一个数
    {
        int m=n;
        int base=1;
        for(int j=1;j<i;j++)  base*=10;
        int tmp=(m%(base*10))/base;
        for(int j=tmp;j<9;j++)
        {
            m+=base;
            sg[m]=1;//m为前者必胜点
        }
    }
    if(len!=6)//长度小于6，则可以在后面加0开头的
    {
        int m=n;
        int base=1;
        for(int i=len;i<6;i++)
        {
            m*=10;
            for(int b=0;b<base;b++)
                sg[m+b]=1;
            base*=10;
        }
    }
}
void fun()
{
    memset(sg,0,sizeof(sg));
    sg[0]=1;
    for(int i=1;i<MAXN;i++)
    {
        if(!sg[i])  _extend(i);
    }
}
int main()
{
    char str[8];
    int n;
    fun();
    while(scanf("%s",&str)!=EOF)
    {
        if(str[0]=='0')  //第一个数字是0，则前者必胜
        {
            printf("Yes\n");
            continue;
        }
        int len=strlen(str);//第一个数字非0，再转化成整型数
        n=0;
        for(int i=0;i<len;i++)
        {
            n*=10;
            n+=str[i]-'0';
        }
        if(sg[n]) printf("Yes\n");
        else  printf("No\n");
    }
    return 0;
}
