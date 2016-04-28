#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
 
//Kiritow's BIGN (class BigNumber) Written on Nov. 12th, 2015
//Original Version: Build 1 ( Version 2 )
class bign
{
public:
    //WARNING: We use public here to reduce time consumed on Interface, although this is not a recommended way.
    int data[20480];
    void set_empty()
    {
        memset(data,0,sizeof(int)*20480);
    }
    int lenx()
    {
        for(int i=20480-1;i>=0;i--)
        {
            if(data[i]!=0) return i+1;
        }
        return 0;
    }
};
 
bign a,b,ans;
 
char buff[10240];
 
int ConvertSTRtoBIGN_A(const char* incstr,bign& incbign)
{
    int len=strlen(incstr);
    for(int i=0;i<len;i++)
    {
        incbign.data[len-i-1]=incstr[i]-'0';
    }
    return len;
}
 
int main()
{
    a.set_empty();
    b.set_empty();
    ans.set_empty();
    gets(buff);
    int lena=ConvertSTRtoBIGN_A(buff,a);
    gets(buff);
    int lenb=ConvertSTRtoBIGN_A(buff,b);
    for(int i=0;i<lena;i++)
    {
        for(int j=0;j<lenb;j++)
        {
            ans.data[j+i]+=a.data[i]*b.data[j];
        }
    }
    for(int i=0;i<20480;i++)
    {
        if(ans.data[i]>10)
        {
            ans.data[i+1]+=ans.data[i]/10;
            ans.data[i]=ans.data[i]%10;
        }
    }
    int slen=ans.lenx();
    for(int i=0;i<slen;i++)
    {
        printf("%d",ans.data[slen-i-1]);
    }
    printf("\n");
    return 0;
}
