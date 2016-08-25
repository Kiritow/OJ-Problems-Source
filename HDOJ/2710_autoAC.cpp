#include<iostream>
#include<cmath>
using namespace std;
#define MAX 2270
int data[MAX]; 
int j;
void Judge(int a)
{
    int i;
    int tmp=sqrt(double(a))+1;
    for(i=2;i<=tmp;i++)
    {
        if(a%i==0)
            return;
    }
    data[j]=a;
    j++;
    return;
}
void Set()
{
    int i;
    j=1;
    data[0]=1;
    data[1]=2;
    j++;
    for(i=3;i<=20010;i++)
        Judge(i);
}
int main()
{
    Set();
    int n,tmp,Max,result,num,i;
    while(cin>>n)
    {
        result=0;
        while(n--)
        {
            cin>>tmp;
            for(i=0;i<2263;i++)
            {
                if(data[i]==tmp||(data[i]<tmp&&tmp%data[i]==0))
                    Max=data[i];
                if(data[i]>tmp)
                    break;
            }
            if(result<Max)
            {
                result=Max;
                num=tmp;
            }
        }
        cout<<num<<endl;
    }
    return 0;
}
