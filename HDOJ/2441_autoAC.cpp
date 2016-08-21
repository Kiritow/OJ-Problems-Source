#include<iostream>
#include <CMATH>
#include <cstring>
#include <cstdio>
using namespace std;
#define N 66000
bool is[N]; __int64 prm[66000];
int getprm(int n){
    int i, j, k = 0;
    int s, e = (int)(sqrt(0.0 + n) + 1);
    memset(is, 1, sizeof(is));
    prm[k++] = 2; is[0] = is[1] = 0;
    for (i = 4; i < n; i += 2) is[i] = 0;
    for (i = 3; i < e; i += 2) if (is[i]) {
        prm[k++] = i;
        for (s = i * 2, j = i * i; j < n; j += s)
            is[j] = 0;
    }
    for ( ; i < n; i += 2) if (is[i]) prm[k++] = i;
    return k; 
}
bool div(char *p,int n)
{
    char temp[1000];
    int i,sum=0,len=0;
    for(i=0;p[i]!=0;i++)
    {
        sum=sum*10+p[i]-'0';
        temp[len++]=sum/n+'0';
        sum%=n;
    } 
    temp[len]=0;
    if(sum==0)
    {
        for(i=0;temp[i]=='0';i++);
        strcpy(p,temp+i);
        return 1;
    }
    else return 0;     
}
int main()
{
    int cnt=getprm(66000);
    int i,n;
    char str[1010];
    while (scanf("%s",&str)&&str[0]!='0')    
    {
        bool judge=true;
        if(strcmp(str,"1")==0)
        {
            printf("no\n");
            continue;
        }
        for(i=0;i<cnt;i++)
        {
            int sum=0;
            while(div(str,prm[i]))
            {
                sum++;
                if(sum>1)
                {
                    judge=false;
                    break;
                }
            }
        }
        if(judge)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
