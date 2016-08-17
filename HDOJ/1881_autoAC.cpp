#include <iostream>
#include <algorithm>
using namespace std;
int m[31][1000];
struct bg_typ
{
    int h,l,t;
};
bg_typ bg[31];
bool cmp(const bg_ a,const bg_ b)
{
    return a.t<b.t;
}
int main()
{
    int n;
    while(cin>>n&&n>=0)
    {
        int mmax=0;
        for(int t=1;t<=n;++t)
        {    
            cin>>bg[t].h>>bg[t].l>>bg[t].t;
            if(bg[t].t>mmax)
                mmax=bg[t].t;
        }
        sort(bg+1,bg+n+1,cmp);
        for(int i=0;i<=n;++i)m[i][0]=m[0][i]=0;
        for(int i=1;i<=n;++i)
        {
            for(int j=0;j<=mmax;++j)
            {     
                if(j<=bg[i].t&&j-bg[i].l>=0)
                    m[i][j]=max(m[i-1][j],m[i-1][j-bg[i].l]+bg[i].h);
                else if(j<bg[i].l)
                    m[i][j]=m[i-1][j];
                else
                    m[i][j]=m[i][bg[i].t];
            }
        }
        int result=m[n][mmax];
        cout<<result<<endl;
    }
    return 0;
}
