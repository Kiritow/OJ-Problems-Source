#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
int t, p;
int tp[200], fa[200], ac[200];
int min(int a, int b){
    if(a<b) return a;return b;
} 
int max(int a, int b){
    if(a>b) return a;return b;
}
void solve()
{
    for(int i = 1; i <= t; i++)
    {
        tp[i] = 0; fa[i] = 0; ac[i] = 0;
    }
    for(int i = 1; i <= t; i++)
        for(int j = 1; j <= p; j++)
        {
            int x;
            int y;
            char s[5];
            cin >> x >> s;
            if(s[1] != '-'){
                ac[i]++;
                fa[i]+=x;
                y = 0;
                for(int k = 1; k <strlen(s); k++)
                    y = y * 10 + s[k] - 48;
                tp[i] += y;
            }
        }
        int least = 1;
        int biggest = 2000000000;
        for(int i = 1; i <= t; i++)
            for(int j = 1; j <= t; j++)
                if(i != j && ac[i] == ac[j] && fa[i] != fa[j])
                {
                    double x = (tp[i] - tp[j] +0.0) / (fa[j]-fa[i] +0.0);
                    if(x-20 < 1e-6 && 20-x < 1e-6)
                    {
                        biggest = 20;least = 20;
                    }
                    else if(x > 20)
                        biggest = min(biggest, int(floor(x-1e-2)));
                    else
                        least = max(least, int(ceil(x + 1e-2)));
                }
        cout << least <<' ';
        if(biggest == 2000000000)
            cout << '*';
        else
            cout << biggest;
        cout << endl; 
}
int main()
{
    cin >> t >> p;
    while(t!=0 || p != 0)
    {
        solve();
        cin >> t >> p;
    }
}
