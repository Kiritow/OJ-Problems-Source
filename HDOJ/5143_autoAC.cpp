#include<iostream>
using namespace std;
int a1,a2,a3,a4;
bool good(int i,int j,int k)
{
    if(((a1-i-k==0)||(a1-i-k>=3))&&((a2-i-j-k==0)||(a2-i-j-k>=3))&&((a3-i-j-k==0)||(a3-i-j-k>=3))&&((a4-j-k==0)||(a4-j-k>=3)))return 1;
    else return 0;
}
int main()
{
    int n;
    int i,j,k;
    int flag;
    cin>>n;
    while(n--)
    {
        cin>>a1>>a2>>a3>>a4;
        flag=0;
        for(i=0;i<=2;i++)
          for(j=0;j<=2;j++)
           for(k=0;k<=2;k++)
            if(good(i,j,k)){flag=1;break;}
        if(flag)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
 return 0;
}
