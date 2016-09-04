#include "iostream"
#include "stdio.h"
#include "math.h"
#include "vector"
#include "queue"
#include "memory.h"
#include "algorithm"
#include "string.h"
using namespace std;
#define N 105
char str[N];
int Div(int s,int t)
{
    int center=-2;
    if(s==t)
       center=-1;
    bool flag=(t-s+1)%2;
    while(t>s&&str[s]==str[t])
        s++,t--;
    if(s>t&&!flag)//even
        center=-1;
    else if(s==t&&flag)//odd
        center=s;
    return center;
}
int main()
{
    int center1,center2,center;
    while(cin>>str&&strcmp(str,"#")!=0)
    {
        int len=strlen(str);
        bool flag=false;
        for(int i=0;i<len;i++)
        {
            center1=Div(0,i);
            center2=Div(i+1,len-1);
            if(center1!=-2&&center2!=-2)
            {
                center=center1==-1?center2:center1;
                cout<<"YES "<<center<<endl;
                flag=true;
                break;
            }
        }
        if(!flag)
            printf("NO\n");
    }
}
