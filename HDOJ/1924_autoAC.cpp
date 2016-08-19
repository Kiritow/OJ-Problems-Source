#include<stdio.h>
#include<string.h>
#include<queue>
#include<map>
#include<string>
#include<iostream>
using namespace std;
map<string,int>my;
map<int,string>my2;
int turn1(string ss1)
{        
    int num1=0;
    int car=0;
    int last=1000000;
    for(int i=0;i<ss1.size();i++)
    {
        string ch="";
        ch+=ss1[i];
        if(my[ch]!=last)
        {
            if(my[ch]<last)
                num1+=car;
            else
                num1-=car;
            car=0;
            car+=my[ch];
        }
        else
            car+=my[ch]; 
        last=my[ch];
    }
    num1+=car;
    return num1;
}
string turn2(int n)
{
        string ans="";
        for(int i=1;n;i*=10)
        {
            int nw=n%10;
            n/=10;
            if(nw<=3||i==1000)
            {
                while(nw--)
                {
                    ans=my2[i]+ans;
                }
            }
            else if(nw>=3&&nw<=5)
            {
                int tem=5-nw;
                ans=my2[i*5]+ans;//hou
                while(tem--)
                    ans=my2[i]+ans;
            }
            else if(nw<=8)
            {
                int tem=nw-5;
                while(tem--)
                    ans=my2[i]+ans;
                ans=my2[i*5]+ans;
            }
            else
            {
                int tem=10-nw;
                ans=my2[i*10]+ans;
                while(tem--)
                    ans=my2[i]+ans;
            } 
        }
        return ans;
}
int main()
{ 
    my["I"]=1;
    my["V"]=5;
    my["X"]=10;
    my["L"]=50;
    my["C"]=100;
    my["D"]=500;
    my["M"]=1000;
    my2[1]="I";
    my2[5]="V";
    my2[10]="X";
    my2[50]="L";
    my2[100]="C";
    my2[500]="D";
    my2[1000]="M";
    string ss1,ss2;
    int n;
    int cas=1;
    while(cin>>n,n)
    {
        int ans=0;
        for(int i=0;i<n;i++)
        {
            cin>>ss1;
            ans+=turn1(ss1);
        }
        cout<<"Case "<<turn2(cas++)<<": "<<turn2(ans)<<endl;
    }
    return 0;
}
