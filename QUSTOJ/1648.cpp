#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

class bign
{
public:
    //WARNING: We use public here to reduce time consumed on Interface, although this is not a recommended way.
    int data[3000];
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

bign sum,tmp,a;

char buff[1024];

void ConvertSTRtoBIGN(const char* incstr,bign& incbign)
{
    int len=strlen(incstr);
    for(int i=0;i<len;i++)
    {
        incbign.data[len-i-1]=incstr[i]-'0';
    }
}
int main()
{
    int times,n;
    scanf("%d%*c",&times);
    for(;times>0;times--)
    {
        scanf("%d%*c",&n);
        sum.set_empty();
        for(;n>0;n--)
        {
            gets(buff);
            tmp.set_empty();
            ConvertSTRtoBIGN(buff,tmp);
            int lena=tmp.lenx();
            int lenb=sum.lenx();
            int maxlen=(lena>lenb)?(lena):(lenb);
            for(int i=0;i<maxlen;i++)
            {
                sum.data[i]+=tmp.data[i];
                if(sum.data[i]>9)
                {
                    sum.data[i]-=10;
                    sum.data[i+1]++;
                }
            }
        }
        int slen=sum.lenx();
        for(int i=slen-1;i>=0;i--)
        {
            printf("%d",sum.data[i]);
        }
        printf("\n");
    }
    return 0;
}
