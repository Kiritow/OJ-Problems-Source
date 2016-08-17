#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;
struct cd
{
    string a;
    string b;
}dic[100100];
int main(void)
{
    string js,tem,cx;
    char ct[30];
    int tms=0;
    while(getline(cin,tem),tem!="@END@")
    {
        dic[tms].a=tem.substr(0,tem.find(']',0)+1);
        dic[tms].b=tem.substr(tem.find(']',0)+2);
        ++tms;
    }
    int cs;int i;
    cin>>cs;
    int a; while((a=getchar())!='\n');
    while(cs--&&getline(cin,cx))
    {
        if(cx[0]=='[')
        {
            for(i=0;i<tms;i++)
            {
                if(dic[i].a==cx)
                    {cout<<dic[i].b<<endl;break;}
            }
            if(i==tms)
                cout<<"what?"<<endl;
        }
        else
        {
            for(i=0;i<tms;i++)
            {
                if(dic[i].b==cx)
                {
                    tem=dic[i].a;
                    tem=tem.substr(1,tem.size()-2);
                    cout<<tem<<endl;
                    break;
                }
            }
            if(i==tms)
                cout<<"what?"<<endl;
        }
    }
    return 0;
}
