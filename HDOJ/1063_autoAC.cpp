#include <iostream>
using namespace std;
const int MAX_LEN=1000;
int temp[1000];
void mul(char* z,char* x,char* y)
{
    int lenx=strlen(x);
    int leny=strlen(y);
    int i,j;
    memset(temp,0,1000*4);
    for(i=0;i<lenx;i++)
        for(j=0;j<leny;j++)
            temp[i+j]+=(x[lenx-1-i]-'0')*(y[leny-1-j]-'0');
    memset(z,0,1000);
    for(i=0;(i<lenx+leny-1) || temp[i]>9;i++)
    {
        if(temp[i]>9)
            temp[i+1]+=temp[i]/10;
        z[i]=temp[i]%10+'0';
    }
    z[i]=temp[i]+'0';
    z[i+1]=0;
    while(z[i]=='0' && i)
        z[i--]=0;
    _strrev(z);
}
int main()
{
    char t[1000];
    char s[7];
    int i,n,dot,len,integer;
    while(cin>>s>>n)
    {
        dot=-1;
        integer=0;
        for(i=0;i<6;i++)
            if(s[i]=='.')
            {
                dot=i;
                for(;i<6;i++)
                {
                    s[i]=s[i+1];
                    if(s[i]==0)
                        break;
                }
                while(s[--i]=='0' && i>=dot)
                    s[i]=0;
                dot=strlen(s)-dot;
                if(dot==0)
                    integer=1;
                break;
            }
        if(dot==-1)
            integer=1;
        memset(t,0,1000);
        t[0]='1';
        for(i=0;i<n;i++)
            mul(t,t,s);
        len=int(strlen(t))-dot*n;
        if(integer)
            cout<<t<<endl;
        else if(len>0)
        {
            for(i=0;i<len;i++)
                cout<<t[i];
            cout<<'.'<<t+len<<endl;
        }
        else
        {
            cout<<'.';
            for(i=0;i<-len;i++)
                cout<<'0';
            cout<<t<<endl;
        }
    }
}
