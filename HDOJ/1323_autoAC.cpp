#include<iostream>
#include<cstdio>
using namespace std; 
int t[103];
int judge(int n)
{
    int sum=0;
    for(int i=1;i<n;++i)
        if(n%i==0)
            sum+=i;
    if(sum==n)
        return 0;
    if(sum<n)
        return -1;
    if(sum>n)
        return 1; 
}
int main()
{
    int i,num=0;
    while(cin>>t[++num]&&t[num]);
    --num;
    cout<<"PERFECTION OUTPUT"<<endl;
    for(i=1;i<=num;++i)
    {
        printf("%5d  ",t[i]);
        switch(judge(t[i]))
        {
            case 0:cout<<"PERFECT"<<endl;break;
            case -1:cout<<"DEFICIENT"<<endl;break;
            case 1:cout<<"ABUNDANT"<<endl;break;
        }
    }
    cout<<"END OF OUTPUT"<<endl;
    return 0;
}
