#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

//Kiritow's BIGN (class BigNumber) Written on Nov. 12th, 2015
//Original Version: Build 1 (Version 2)
//CCBIGN : from BIGN (Build 1 -version 2)
class ccbign
{
public:
    //WARNING: We use public here to reduce time consumed on Interface, although this is not a recommended way
    int data[3000];
    int length;
    ccbign()
    {
        length=0;
    }
    void set_empty()
    {
        memset(data,0,sizeof(int)*3000);
    }
};

int ConvertSTRtoCCBIGN(const char* incstr,ccbign& incbign)
{
    int len=strlen(incstr);
    for(int i=0;i<len;i++)
    {
        incbign.data[i]=incstr[i]-'0';
    }
    incbign.length=len;
    return len;
}

ccbign a;

char buff[3000];

int main()
{
    int times;
    scanf("%d%*c",&times);
    for(;times>0;times--)
    {
        a.set_empty();
        gets(buff);
        int len=ConvertSTRtoCCBIGN(buff,a);
        for(int i=0;i<len-1;i++)
        {
            int tmp=a.data[i]*10+a.data[i+1];
            if(tmp<17)
            {
                a.data[i+1]+=a.data[i]*10;
                continue;
            }
            else
            {
                a.data[i+1]=tmp%17;
            }
        }
        int answer=a.data[a.length-1];
        printf("%d\n",answer);
    }
    return 0;
}
