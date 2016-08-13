#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

#include <algorithm>
using namespace std;
#define MAXROUND 100005
double safemoney[MAXROUND];
double roundmoney[MAXROUND];
double p[MAXROUND];
char str[256];
inline double ln(double inc)
{
    return log(inc);
}
int main()
{
    int n,W;
    scanf("%d %d",&n,&W);
    for(int i=0;i<n;i++)
    {
        scanf("%s %lf %lf",str,&p[i],&roundmoney[i+1]);
        roundmoney[i+1]=ln(1+roundmoney[i+1]/W);
        if(strcmp(str,"safe")==0)
        {
            safemoney[i+1]=roundmoney[i+1];
        }
        else
        {
            safemoney[i+1]=safemoney[i];
        }
    }
    for(int i=n-1;i>=0;i--)
    {
        double tmp=p[i]*roundmoney[i+1]+(1-p[i])*safemoney[i];
        roundmoney[i]=max(tmp,roundmoney[i]);
    }
    double ans=(exp(roundmoney[0])-1)*W;
    printf("$%.2f\n",ans);
}
