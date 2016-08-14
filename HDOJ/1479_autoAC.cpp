#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
void R(char* n,char* t)
{
    int i,j;
    int time[10]={0};  
    for(i=0;n[i];i++)
        time[ n[i]-'0' ]++;
    for(i=0,j=0;i<10;i++)
    {
        if(time[i])
        {
            if(time[i]<10)  
            {
                t[j++]=time[i]+'0';
                t[j++]=i+'0';
            }
            else    
            {
                t[j++]=time[i]/10+'0';
                t[j++]=time[i]%10+'0';
                t[j++]=i+'0';
            }
        }
    }
    t[j]='\0';
    return;
}
int main(int i,int j)
{
    char n[16][85];    
    while(cin>>n[0] && n[0][0]!='-')
    {
        bool flag1=false;    
        int flag2=0;        
        int flag3=0;       
        for(i=1;i<=15;i++)
            R(n[i-1],n[i]);
        if(!strcmp(n[0],n[1])) 
            flag1=true;
        if(!flag1)
        {
            for(j=1;j<15;j++)
                if(!strcmp(n[j],n[j+1])) 
                {
                    flag2=j;
                    break;
                }
            if(!flag2)
            {
                for(j=1;j<=15;j++)  
                {
                    for(i=0;i<=j-2;i++)
                    {
                        if(!strcmp(n[j],n[i]))
                        {
                            flag3=j-i;
                            break;
                        }
                    }
                    if(flag3)
                        break;
                }
            }
        }
        if(flag1)
            cout<<n[0]<<" is self-inventorying"<<endl;
        else if(flag2)
            cout<<n[0]<<" is self-inventorying after "<<flag2<<" steps"<<endl;
        else if(flag3)
            cout<<n[0]<<" enters an inventory loop of length "<<flag3<<endl;
        else
            cout<<n[0]<<" can not be classified after 15 iterations"<<endl;
    }
    return 0;
}
