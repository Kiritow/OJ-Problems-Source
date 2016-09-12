#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<queue>
#include<math.h>
#include<vector>
#include<map>
#include<set>
#include<stdlib.h>
#include<cmath>
#include<string>
#include<algorithm>
#include<iostream>
#define exp 1e-10
using namespace std;
const int N = 3145750;
const int inf = 1000000000;
char s[N];
int main()
{
    int t,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s);
        for(i=0;s[i+1]!='\0';i++)
            if(s[i]=='w'||s[i]=='v'&&s[i+1]=='v')
                break;
        if(s[i+1]=='\0')
        {
            puts("No");
            continue;
        }
        for(;s[i]!='\0';i++)
            if(s[i]=='y')
                break;
        if(s[i]=='\0')
        {
            puts("No");
            continue;
        }
        for(;s[i]!='\0';i++)
            if(s[i]=='h')
                break;
        if(s[i]=='\0')
            puts("No");
        else
            puts("Yes");
    }
    return 0;
}
