#include<iostream>
#include<cstring>
using namespace std;
const int N=5011;
int flag[N];
void init()
{
    int i,l,j;
    int a,b;
    memset(flag,0,sizeof(flag));
    for(i=1;i<=5000;i++)
    {
        for(l=1;l<=1000;l++)
        {
            for(j=1;j<=1000;j++)
            {
                a=l*l*j+1;
                b=l*l+j;
                if(a%i==0 && b%i)    flag[i]=1;
                if(flag[i])    break;
            }
            if(flag[i])    break;
        }
    }
}
int main()
{
    init();
    int T;
    int n;
    cin>>T;
    while(T--)
    {
        cin>>n;
        if(flag[n])    cout<<"NO"<<endl;
        else        cout<<"YES"<<endl;
    }
    return 0;
}
