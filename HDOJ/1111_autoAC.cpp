#include <iostream>
using namespace std;
int xr,xi,br,bi,con;
int flag,t;
int a[105];  
void dfs(int n)
{
    int x,y,i;
    if(n>100) return;
    if(xr==0&&xi==0)
    {
        flag=1;
        t=n;
        return;
    }
    for(i=0;i*i<con;i++)
    {
        x=(xr-i)*br+xi*bi;
        y=xi*br-(xr-i)*bi;
        a[n]=i;
        if(x%con==0&&y%con==0) 
        {
            xr=x/con;
            xi=y/con;
            dfs(n+1);
        }
        if(flag) return;
    }
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        cin>>xr>>xi>>br>>bi;
        con=br*br+bi*bi;
        flag=0;
        dfs(0);
        if(!flag)
            cout<<"The code cannot be decrypted."<<endl;
        else
        {
            cout<<a[t-1];
            for(int i=t-2;i>=0;i--)
                cout<<','<<a[i];
            cout<<endl;
        }
    }
    return 0;
}
