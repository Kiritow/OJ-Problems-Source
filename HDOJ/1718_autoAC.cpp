#include<iostream>
using namespace std;
void main()
{
    int a[101],i,num,num1,rank,mark1,mark;
    while(cin>>num)
    {
        memset(a,0,sizeof(a));
        while(cin>>num1>>mark1&&(num1!=0||mark1!=0))
        {
            if(num1==num)
                mark=mark1;
            a[mark1]++;
        }
        for(i=100,rank=0;i>mark;i--)
            rank+=a[i];
        cout<<rank+1<<endl;
    }
}
