#include <iostream>
#include <cstring>
using namespace std;
int father[100010];
int findfather(int x)
{
    while (father[x]!=x)
        x=father[x];
    return x;
}
bool is_father(int m,int n)
{
    while (father[m]!=n)
    {
        if (father[m]==m) return true;
        m=father[m];
    }
    return false;
}
int main()
{
    bool e,flag;
    int times=0;
    int maxx,root,m,n,t;
    while (cin >> m >> n && (m>=0 && n>=0))
    {
        memset(father,0,sizeof(father));
        e=false;flag=true;
        root=-1;
        maxx=0;
        while ((m+n)!=0)
        {
            if (e) cin >> m >> n;
            if (m+n==0) break;
            if (maxx<m) maxx=m;
            if (maxx<n) maxx=n;
            e=true;
            if (father[m]==0) father[m]=m;
            if (father[n]==0) father[n]=n;
            if (father[n]!=n) flag=false;
            if (is_father(m,n)) father[n]=m;
            else flag=false;
        }
        times++;
        cout << "Case " << times << " is ";
        if (flag==false) {cout << "not a tree." << endl;continue;}
        for (int i=1;i<=maxx;i++)
        {
            if (father[i]==0) continue;
            t=findfather(i);
            if (t!=root)
            {
                if (root==-1) root=t;
                else {flag=false;break;}
            }
        }
        if (flag==false) {cout << "not a tree." << endl;continue;}
        cout << "a tree." <<endl;
    }
    return 0;
}
