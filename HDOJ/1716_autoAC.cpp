#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int a[5],tem;
    cin>>a[1]>>a[2]>>a[3]>>a[4];
    while(a[1]||a[2]||a[3]||a[4])
    {
        sort(a+1,a+5);
        tem=a[1];
        if(tem)
            cout<<a[1]<<a[2]<<a[3]<<a[4];
        while(next_permutation(a+1,a+5))
        {
            int i=1;
            if(a[1])
            {
                if(tem && a[i]==tem)
                    cout<<" ";
                for(i=1; i<=4; i++)
                {
                    if(a[i]!=tem && i==1 && tem)
                        cout<<endl;
                    cout<<a[i];
                }
            }
            tem=a[1];
        }
        cout<<endl;
        cin>>a[1]>>a[2]>>a[3]>>a[4];
        if(a[1]||a[2]||a[3]||a[4])
            cout<<endl;
    }
}
