#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
/*
bool check(int inc)
{
    if(inc%36!=0) return false;
    char buff[32];
    memset(buff,0,32);
    sprintf(buff,"%d",inc);
    if(strstr(buff,"36")==NULL) return false;
    int len=strlen(buff);
    for(int i=0;i<len;i++)
    {
        if(buff[i]=='3')
        {
            if(buff[i+1]!='6') return false;
        }
        if(buff[i]=='6')
        {
            if(i==0) return false;
            else if(buff[i-1]!='3') return false;
        }
    }
    return true;
}

int cnt=0;
int main()
{
freopen("aaa.txt","w",stdout);
for(int i=1;i<=100000;i++)
{
    if(check(i)) {
            cnt++;printf("%d,",i);
    }
}
printf("#%d",cnt);
return 0;
}
*/
int num[119]={36,360,936,1368,1836,2736,3600,3636,3672,4536,5364,5436,7236,8136,9036,9360,9936,10368,10836,11736,13608,13644,13680,14364,14436,17136,18036,18360,18936,19368,19836,20736,22536,23652,23688,25236,27036,27360,27936,28368,28836,29736,36000,36036,36072,36108,36144,36180,36252,36288,36360,36504,36540,36720,36792,36828,36900,36936,36972,40536,41364,41436,44136,45036,45360,45936,47736,49536,50364,50436,52236,53604,53640,54036,54360,54936,55368,55836,58536,59364,59436,70236,71136,72036,72360,72936,73620,73692,74736,77364,77436,79236,80136,81036,81360,81936,82368,82836,83628,85536,88236,89136,90036,90360,90936,91368,91836,92736,93600,93636,93672,94536,95364,95436,97236,98136,99036,99360,99936};
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int L;
        scanf("%d",&L);
        bool found=false;
        for(int k=0;k<119;k++)
        {
            if(num[k]<L) continue;
            else
            {
                printf("%d\n",num[k]);
                found=true;
                break;
            }
        }
        if(!found)
        {
            printf("-1\n");
        }
    }
    return 0;
}
