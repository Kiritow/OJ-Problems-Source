#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#define Max  2000
int num[Max], pre[Max];
void init()
{
    memset(num, 0, sizeof(num));
    memset(pre, 0, sizeof(pre));
    pre[0] = 1;
    for(int i = 2; i <= 110; i++)
    {
        int c = 0;
        for(int j = 0; j < Max; j++)
        {
            int sum = pre[j]*i + c;
            pre[j] = sum%16;
            c = sum/16;
        }
        int k;
        for(k = Max-1; k >= 0; k--) if(pre[k])
            break;
        for(int j = 0; j <= k; j++) if(!pre[j])
            num[i]++;
    }
}
int main(void)
{
    int n;
    init();
    while(cin>>n && n >= 0)
    {
        cout<<num[n]<<endl;
    }
    return 0;
}
