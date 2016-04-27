#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

//Kiritow's BIGN (class BigNumber) Written on Nov. 12th, 2015
//Original Version: Build 1
class bign
{
public:
    //WARNING: We use public here to reduce time consumed on Interface, although this is not a recommended way.
    int data[3000];
    bool more_than_zero;
    bign()
    {
        more_than_zero=true;
    }
    void set_empty()
    {
        memset(data,0,sizeof(int)*3000);
    }
    int lenx()
    {
        for(int i=3000-1;i>=0;i--)
        {
            if(data[i]!=0) return i+1;
        }
        return 0;
    }
};

char CompareBIGN(bign& a,bign& b)
{
    int lena=a.lenx();
    int lenb=b.lenx();
    if(lena<lenb)
    {
        return '<';
    }
    else if (lena>lenb)
    {
        return '>';
    }
    else
    {
        for(int i=lena-1;i>=0;i--)
        {
            if(a.data[i]>b.data[i])
            {
                return '>';
            }
            else if(a.data[i]<b.data[i])
            {
                return '<';
            }
        }
        return '=';
    }
}

void ConvertSTRtoBIGN(const char* incstr,bign& incbign)
{
    int len=strlen(incstr);
    for(int i=0;i<len;i++)
    {
        incbign.data[len-i-1]=incstr[i]-'0';
    }
}

bign a,b;
char buff[3000];
int main()
{
    a.set_empty();
    b.set_empty();
    gets(buff);
    ConvertSTRtoBIGN(buff,a);
    gets(buff);
    ConvertSTRtoBIGN(buff,b);
    printf("%c\n",CompareBIGN(a,b));
    return 0;
}
