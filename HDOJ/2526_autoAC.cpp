#include<iostream>
#include<string.h>
const int MAX=1000;
int s[MAX];
int x[MAX];
int y[MAX];
char z[MAX];
char v[MAX];
char k[MAX];
using namespace std;
int main()
{
    int t,n,m,i,j,q,p,sum;
    cin>>t;
    while(t--)
    {
        cin>>m;
        for(i=0;i<8;i++)
        {
            cin>>k>>n;
            sum=0;
            for(j=0;j<3;j++)
            {
                if(k[j]=='1'&&j==0)
                 sum+=4;
                if(k[j]=='1'&&j==1)
                sum+=2;
                if(k[j]=='1'&&j==2)
                sum+=1;
            }
            x[i]=sum;
            y[i]=n;
        }
        cin>>z;
        n=strlen(z);
        cout<<z<<endl;
        m-=1;
        while(m--)
        {
            strcpy(v,z);
            for(i=n;i>=1;i--)
            {
                v[i]=v[i-1];
            }
            v[0]='0';
            v[n+1]='0';
            for(i=1;i<n+1;i++)
            {
                if(v[i-1]=='0'&&v[i]=='0'&&v[i+1]=='0')
                sum=0;
                if(v[i-1]=='0'&&v[i]=='0'&&v[i+1]=='1')
                sum=1;
                if(v[i-1]=='0'&&v[i]=='1'&&v[i+1]=='0')
                sum=2;
                if(v[i-1]=='0'&&v[i]=='1'&&v[i+1]=='1')
                sum=3;
                if(v[i-1]=='1'&&v[i]=='0'&&v[i+1]=='0')
                sum=4;
                if(v[i-1]=='1'&&v[i]=='0'&&v[i+1]=='1')
                sum=5;
                if(v[i-1]=='1'&&v[i]=='1'&&v[i+1]=='0')
                sum=6;
                if(v[i-1]=='1'&&v[i]=='1'&&v[i+1]=='1')
                sum=7;
                for(j=0;j<8;j++)
                {
                    if(x[j]==sum)
                    {
                        z[i-1]=y[j]+'0';
                        break;
                    }
                }
            }
            cout<<z<<endl;
        }
    }
    return 0;
}
