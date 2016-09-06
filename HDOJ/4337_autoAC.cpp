#include <string.h>
#include <iostream>
#include <stdio.h>
using namespace std;
#define V 200
int n,m;
bool c[V][V];
int x[V];
bool flag[V];
void hamilton()
{
    int i, k;
    bool s[V];
    for(i = 0; i < n; i++)
    {
        x[i] = -1;
        s[i] = false;
    }
    k = 1;
    s[0] = true;
    x[0] = 0;
    while(k >= 0)
    {
        x[k]++;
        while(x[k] < n)
            if(!s[x[k]] && c[x[k - 1]][x[k]])
                break;
            else
                x[k]++;
        if((x[k] < n) && (k != n - 1))
        {
            s[x[k]] = true;
            k++;
        }
        else if((x[k] < n) && k == n - 1 && c[x[k]][x[0]])
        {
            break;
        }
        else
        {
            x[k] = -1;
            k--;
            s[x[k]] = false;
        }
    }
}
int main()
{
    int a,b;
    while(cin >> n >> m){
        memset(c,0,sizeof(c));
        memset(flag,0,sizeof(flag));
        memset(x,0,sizeof(x));
        for(int i=0;i<m;i++){
            cin >> a >> b;
            c[a-1][b-1]=c[b-1][a-1]=true;
        }
        hamilton();
        bool f=0;
        for(int i=0;i<n;i++){
            flag[x[i]]=1;
        }
        for(int i=0;i<n;i++){
            if(!flag[i]) f=1;
        }
        if(f) cout <<"no solution" <<endl;
        else{
            for(int i=0;i<n;i++){
                if(i==n-1) cout << x[i]+1 <<endl;
                else cout << x[i]+1 <<" ";
            }
        }
    }
    return 0;
}
