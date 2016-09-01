#include <cstdio>
#include <map>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
map<string,int>mm;
int main()
{
    string name[117];
    int t;
    int n;
    int cas = 0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        mm.clear();
        for(int i = 0; i < n; i++)
        {
            cin>>name[i];
        }
        int m;
        scanf("%d",&m);
        char s[1000];
        string ss="";
        for(int i = 0; i < m; i++)
        {
            getchar();
            gets(s);
            for(int j = 0; j < strlen(s); j++)
            {
                if(s[j]==' ')
                {
                    mm[ss]++;
                    ss="";
                    continue;
                }
                ss+=s[j];
            }
            mm[ss]++;
            ss="";
        }
        printf("Test set %d:\n",++cas);
        for(int i = 0 ; i < n; i++)
        {
            if(mm[name[i]])
            {
                cout<<name[i]<<" is present"<<endl;
            }
            else
            {
                cout<<name[i]<<" is absent"<<endl;
            }
        }
        printf("\n");
    }
    return 0;
}
