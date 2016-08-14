#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;
const int maxa=21000;
const int maxn=1002;
int a[maxn];
int b[maxn];
int c[maxn];
int p[maxa];
int N,l,r;
void dp()
{
    for(int i=0;i<maxa;++i)
        p[i]=INT_MIN;
    l=r=10000;
    p[l]=0;
    for(int i=0;i<N;++i)
    {
        if(a[i]>0)
        {
            for(int j=b[i];j>=l;--j)
                if(p[j]!=INT_MIN)
                    p[j+a[i]]=max(p[j+a[i]],p[j]+c[i]);
            r+=a[i];
        }
        else if(a[i]<0)
        {
            for(int j=b[i];j<=r;++j)
                if(p[j]!=INT_MIN)
                    p[j+a[i]]=max(p[j+a[i]],p[j]+c[i]);
            l+=a[i];
        }
    }
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        cin>>N;
        for(int i=0;i<N;++i)
        {
            cin>>a[i]>>b[i]>>c[i];
            b[i]+=10000;
        }
        dp();
        cout<<*max_element(p,p+maxa)<<endl;
    }
    return 0;
}
