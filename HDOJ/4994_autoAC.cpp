#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <fstream>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <cmath>
#include <iomanip>
typedef long long LL;
typedef unsigned long long LLU;
const double PI=acos(-1.0);
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, a[1111], cnt=0;
        cin>>n;
        for(int i=0; i<n; i++)
            cin>>a[i];
        for(int i=0; i<n-1 && a[i]==1; i++)
            cnt++;
        if(cnt&1)
            cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
    return 0;
}
