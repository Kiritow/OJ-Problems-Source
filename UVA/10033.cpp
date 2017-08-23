#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int reg[10];

int mem[1000];

int main()
{
    int t;
    scanf("%d%*c%*c",&t);

    while(t--)
    {
        memset(reg,0,sizeof(reg));
        memset(mem,0,sizeof(mem));

        /// Read code
        int cc=0;
        while(1)
        {
            string buff;
            if(!getline(cin,buff)) break;

            if(buff.size()>1)
            {
                sscanf(buff.c_str(),"%d",&mem[cc]);
                ++cc;
            }
            else break;
        }

        /// Execute Code
        int cnt=0;
        int pc=0;
        while(1)
        {
            int opt=mem[pc];
            ++cnt;
            ++pc;
            if(opt==100)
            {
                break;
            }

            int d=(opt%100)/10;
            int n=opt%10;

            switch(opt/100)
            {
            case 0:
                if(reg[n]) pc=reg[d];
                break;
            case 2:
                reg[d]=n;
                break;
            case 3:
                reg[d]=(reg[d]+n)%1000;
                break;
            case 4:
                reg[d]=(reg[d]*n)%1000;
                break;
            case 5:
                reg[d]=reg[n];
                break;
            case 6:
                reg[d]=(reg[d]+reg[n])%1000;
                break;
            case 7:
                reg[d]=(reg[d]*reg[n])%1000;
                break;
            case 8:
                reg[d]=mem[reg[n]];
                break;
            case 9:
                mem[reg[n]]=reg[d];
                break;
            }
        }

        printf("%d\n",cnt);
        if(t) printf("\n");
    }

    return 0;
}
