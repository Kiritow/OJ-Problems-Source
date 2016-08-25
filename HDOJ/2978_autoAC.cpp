#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <map>
#define OP(s) cout<<#s<<"="<<s<<" ";
#define PP(s) cout<<#s<<"="<<s<<endl;
#define SET(s,x) memset(s,x,sizeof(s));
using namespace std;
typedef long long LL;
struct Node
{
    int yes,count;
    string str;
}a[10010];
int tota = 0;
int main()
{
    int n,m,k;
    while (~scanf("%d",&n),n)
    {
        static int cas = 0;
        printf("Case %d: ",++cas);
        tota = 0;
        int m,k;
        cin>>m>>k;
        string s1,s2;
        map<string,int> mp;
        while (n--)
        {
            map<string,bool> vd;
            cin>>s1>>s2;
            int len = s1.length();
            for (int i = 0;i <= len-k;i++)
            {
                string tmp = "";
                for (int j =0;j < k;j++) tmp += s1[i+j];
                if (!vd[tmp])
                {
                    vd[tmp] = 1;
                    int id;
                    if (mp[tmp] == 0)
                    {
                        mp[tmp] = ++tota;
                        id = tota;
                        a[id].count = 0;
                        a[id].yes = 0;
                        a[id].str = tmp;
                    }
                    else id = mp[tmp];
                    a[id].count++;
                    if (s2 == "Yes") a[id].yes++;
                }
            }
        }
        int ans = -1,ansc = 1,ansy = 2;
        for (int i = 1;i <= tota;i++)
        {
            if (a[i].count < m) continue;
            int y1 = a[i].yes,c1 = a[i].count;
            if (y1 * ansc < ansy*c1
                || y1*ansc == ansy*c1 && c1 > ansc
                || y1*ansc == ansy*c1 && c1 == ansc && a[i].str < a[ans].str
            )
            {
                ans = i,ansy = y1,ansc = c1;
            }
        }
        if (ans == -1) cout<<"No solution\n";
        else cout<<a[ans].str<<endl;
    }
    return 0;
}
