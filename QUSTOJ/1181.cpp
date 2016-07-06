#include<iostream>
using namespace std;
int main()
{
    int a,b,mx=0;
    int i;
    int m,n,v[61]= {0},p[61]= {0},q;
    int v1[61]= {0},v2[61]= {0},p1[61]= {0},p2[61]= {0};
    int f[50001]= {0};
    cin>>m>>n;
    m/=10;
    for(i=1; i<=n; i++)
    {
        cin>>a>>b>>q;
        a/=10;
        if(q!=0)
        {
            if(v1[q]==0)
            {
                v1[q]=a;
                p1[q]=b;
            }
            else
            {
                v2[q]=a;
                p2[q]=b;
            }
        }
        else
        {
            v[i]=a;
            p[i]=b;
        }
    }
    for(int i=1; i<=n; i++)
        for(int j=m; j>=v[i]; j--)
        {
            f[j]=max(f[j],f[j-v[i]]+v[i]*p[i]);
            if(j-v1[i]-v[i]>=0)f[j]=max(f[j],f[j-v1[i]-v[i]]+v1[i]*p1[i]+v[i]*p[i]);
            if(j-v2[i]-v[i]>=0)f[j]=max(f[j],f[j-v2[i]-v[i]]+v2[i]*p2[i]+v[i]*p[i]);
            if(j-v1[i]-v2[i]-v[i]>=0)f[j]=max(f[j],f[j-v1[i]-v2[i]-v[i]]+v1[i]*p1[i]+v2[i]*p2[i]+v[i]*p[i]);
            mx=max(f[j],mx);
        }
    cout<<mx*10<<endl;
    return 0;
}
