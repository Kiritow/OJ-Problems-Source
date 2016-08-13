#include<iostream>
using namespace std;
string Da(string a,string b)
{
    string ans;
    int carry;
    int i,j,k;
    int add1,add2,sum;
    i=a.size()-1;
    j=b.size()-1;
    k=i>j?i:j;
    if(i>j) 
        ans=a; 
    else 
        ans=b;
    for(carry=0;k>=0;i--,j--,k--)
    {
        add1=i<0?0:a[i]-'0';
        add2=j<0?0:b[j]-'0';
        sum=add2+add1+carry>=10?add1+add2+carry-10:add1+add2+carry;
        carry=add1+add2+carry>=10?1:0;
        ans[k]=sum+'0';
    }
    k=ans.size();
    if(carry)
        ans.insert(0,"1");
    return ans;
}
int main()
{
    int n,i;
    string a[1005];
    a[0]="1";
    a[1]="3";
    for(i=2;i<=1000;i++)
    {
        a[i]=Da(Da(a[i-1],a[i-1]),a[i-2]);
    }
    while(cin>>n)
    {
        cout<<a[n]<<endl;
    }
    return 0;
}
