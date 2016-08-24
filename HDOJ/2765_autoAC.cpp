#include<iostream>
using namespace std;
const int MAX = 2140000000;
int f[1000001];
void dfs(int p)
{
    int i,sum = 1,temp;
    if(p%2 == 1)
    {
        for(i=1;i<p;i+=2)
        {
            temp = (p-i)/2;
            if(f[temp]==MAX)
                dfs(temp);
            sum += f[temp];
        }
    }
    else //even
    {
        for(i=0;i<p;i+=2)
        {
            temp = (p-i)/2;
            if(f[temp]==MAX)
                dfs(temp);
            sum += f[temp];
        }            
    }
    f[p] = sum;
}
int main()
{
    int t,n,i,temp;
    for(i=0;i<=10000;i++)
        f[i] = MAX;
    f[0] = 0;
    f[1] = 1;
    f[2] = 2;
    f[3] = 2;
    int cas = 1;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(f[n] == MAX)
            dfs(n);
        cout<<cas++<<" "<<f[n]<<endl;
    }
    return 0;
}
