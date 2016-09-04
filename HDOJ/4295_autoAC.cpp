#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=4100;
char s[N],ss[70];
short l,sl[4],maxl;
short flag[N],d1[N][16][65],d2[N][16][65];
int main()
{
    int i,j,k,x;
    while(~scanf("%s",s))
    {
        l=strlen(s);
        memset(flag,0,sizeof(flag[0])*l);
        for(i=0;i<4;i++)
        {
            scanf("%s",ss);
            sl[i]=strlen(ss);
            for(j=0;j+sl[i]<=l;j++)
            {
                for(k=0;ss[k];k++)if(s[j+k]!=ss[k])break;
                if(ss[k]=='\0') flag[j]|=1<<i;
            }
            if(sl[i]>maxl) maxl=sl[i];
        }
        memset(d1,0x3f,sizeof(d1[0])*(l+1));
        memset(d2,0xc3,sizeof(d1[0])*(l+1));
        d1[0][0][0]=d2[0][0][0]=0;
        for(i=0;i<l;i++)for(j=0;j<16;j++)for(k=0;k<=maxl;k++)
        {
            d1[i+1][j][k?k-1:0]=min(d1[i][j][k],d1[i+1][j][k?k-1:0]);
            d2[i+1][j][k?k-1:0]=max(d2[i][j][k],d2[i+1][j][k?k-1:0]);
            for(x=0;x<4;x++)
            {
                if((1<<x&~j)&&(1<<x&flag[i]))
                {
                    short t=max((short)k,sl[x]);
                    d1[i][1<<x|j][t]=min((short)(d1[i][j][k]+t-k),d1[i][1<<x|j][t]);
                    d2[i][1<<x|j][t]=max((short)(d2[i][j][k]+t-k),d2[i][1<<x|j][t]);
                }
            }
        }
        printf("%hd %hd\n",d1[l][15][0],d2[l][15][0]);
    }
    return 0;
}
