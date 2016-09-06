#include <cstdio>
#include <cstring>
using namespace std;
int b[300100],len;
char c[300100];
inline int ca(int x)
{return x<len?x:x-len;}
int minp()
{
    int i=0,j=1,k=0;
    while(i<len && j<len && k<len)
    {
        int det=b[ca(i+k)]-b[ca(j+k)];
        if(det==0) k++;
        else 
        {
            if(det>0) i+=k+1; else j+=k+1;
            if(i==j) j++;
            k=0;
        }
    }
    return i>j?j:i;
}
int main()
{
    while(scanf("%s",c)==1)
    {
        len=strlen(c);c[len]=c[0];c[len+1]='\0';
        for(int i=0;i<len;i++)
        {
            b[i]=c[i+1]-c[i];
            if(c[i]>c[i+1]) b[i]+=8;
        }
        int k=minp();
        for(int l=0;l<len;l++) printf("%d",b[ca(k+l)]); puts("");
    }
}
