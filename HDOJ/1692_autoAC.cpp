#include<iostream>
using namespace std;
int w[100005],L[100005],p[100005];
int main()
{
    int T,i,N,j,max,k,sum,carry;
    cin>>T;
    for(i=1;i<=T;i++)
    {
        cin>>N;
        for(j=1;j<=N;j++)
            cin>>w[j]>>L[j]>>p[j];
        max=p[N];
        for(j=1;j<N;j++)
        {
            sum=0;
            carry=0;
            for(k=j;k<=N;k++)
            {
                carry=carry+w[k];
                if(carry<=L[k])
                    sum=sum+p[k];
                if(sum>max)
                    break;
            }
            if(sum<max)
            {
                max=sum;
            }
        }
        cout<<"Case "<<i<<": Need to use "<<max<<" mana points."<<endl;
    }
    return 0;
}
