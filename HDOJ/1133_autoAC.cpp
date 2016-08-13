#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
const int MAX=501;
int s[MAX];
using namespace std;
int main()
{
    int n,m,q,p=1,c,sum,k,temp,t,i,j;
    while(cin>>m>>n&&(m||n))
    {
        cout<<"Test #"<<p++<<':'<<endl;
        if(m<n)
        {
            cout<<0<<endl;
            continue;
        }
        memset(s,0,sizeof(s));
        s[1]=1;
        sum=0;
        for(i=2;i<=(m+n);i++)
        {
            for(j=1;j<MAX;j++)
            {
                c=s[j]*i+sum;
                s[j]=c%10;
                sum=c/10;
            }
        }
        q=m+1-n;
        sum=0;
        for(j=1;j<MAX;j++)
        {
            c=s[j]*q+sum;
            s[j]=c%10;
            sum=c/10;
        }
        for(j=MAX-1;j>=1;j--)
        {
            if(s[j]!=0)
            break;
        }
        for(i=j,sum=0,t=0;j>=1;j--)
        {
            temp=sum*10+s[j];
            if(t==0)
            {
                if(temp/(m+1)>0)
                {
                    t=1;
                    cout<<temp/(m+1);
                }
            }
            else
            cout<<temp/(m+1);
            sum=temp%(m+1);
        }
        cout<<endl;
    }
    return 0;
}
