#include <iostream>
using namespace std;
char a[100002];
int main()
{
    int n,x,y;
    char ch;
    while(cin>>n)
    {
        memset(a,'b',sizeof(a));
        int maxnum=0,minnum=2e31-1;
        for(int i=0;i<n;i++)
        {
            cin>>x>>y>>ch;
            if(y>maxnum)
                maxnum=y;
            if(x<minnum)
                minnum=x;
            for(int j=x;j<=y;j++)
                a[j]=ch;
        }
        int sum=0,max1=0,beg=minnum,end=minnum,minpos=-1,maxpos=-1;
        for(int i=minnum;i<=maxnum+1;i++)
        {
            if(a[i]=='b')
            {
                if(sum>max1)
                {
                    max1=sum;
                    minpos=beg;
                    maxpos=end;
                }
                sum=0;
                continue;
            }
            if(sum==0)
                beg=i;
            sum++;
            end=i;
        }
        if(max1==0)
            cout<<"Oh, my god"<<endl;
        else
            cout<<minpos<<" "<<maxpos<<endl;
    }
    return 0;
}
