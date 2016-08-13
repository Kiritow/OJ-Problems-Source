#include<iostream>
#include<cstring>
using namespace std;
int a[500];
void change(int n,int m)
{
    int c;
        c=0;
        for(int j=0;j<500;j++)
        {
            c=a[j]*n+c;
            a[j]=c%10;
            c=c/10;
        }
        c=0;
        for(int j=499;j>=0;j--)
        {
            c=a[j]+c*10;
            a[j]=c/m;
            c=c%m;
        }
    return;
}
int main()
{
    int n,s,k;
    int b[26];
    while(cin>>n&&n)
    {
        s=0;
        memset(a,0,sizeof(a));
        a[0]=1;
        for(int i=0;i<n;i++){
            cin>>b[i];
            for(int j=1;j<=b[i];j++)
                change(s+j,j);
            s+=b[i];
        }
        for(k=499;k>=0;k--)if(a[k]!=0)
            break;
        for(int i=k;i>=0;i--)
            cout<<a[i];
        cout<<endl;
    }
    return 0;
}
