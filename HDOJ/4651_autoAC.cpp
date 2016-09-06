#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
long long tar[100002];
const int MOD=1000000007;
void init()
{
    memset(tar,0,sizeof(tar));
    tar[0]=1;
    for(int i=1;i<=100000;i++)
    {
        int nbit;
        for(int j=1;;j++)
        {
            int element1,element2;
            element1=i-j*(3*j-1)/2;
            element2=i-j*(3*j+1)/2;
            if(j&1)
                nbit=1;
            else if(j%2==0)
                nbit=-1;
            if(element2<0 && element1<0)
                break;
            if(element1>=0)
            {
                tar[i]=(tar[i]+nbit*tar[element1])%MOD;
            }
            if(element2>=0)
            {
                tar[i]=(tar[i]+nbit*tar[element2])%MOD;
            }
        }
        tar[i]=(tar[i]+MOD)%MOD;
    }
}
int main()
{
    int testcase;
    init();
    cin>>testcase;
    while(testcase--)
    {
        int rat;
        cin>>rat;
        cout<<tar[rat]<<endl;
    }
    return 0;
}
