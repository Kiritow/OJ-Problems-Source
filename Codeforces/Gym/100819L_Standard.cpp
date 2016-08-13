#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const int MAXN = 100000;
int N, W;
string safe;
long double p[MAXN], v[MAXN+1], s[MAXN+1];

int main()
{
    //ios::sync_with_stdio(0);
    while (cin >> N >> W && N)
    {
        v[0] = 0;
        for (int i = 0; i < N; ++i)
        {
            cin >> safe >> p[i] >> v[i+1];
            v[i+1] = log1p(v[i+1] / W);
            if (safe == "safe")
                s[i+1] = v[i+1];
            else
                s[i+1] = s[i];
        }
        for (int i = N-1; i >= 0; --i)
        {
            long double Ewin = p[i]*v[i+1] + (1-p[i])*s[i];
            v[i] = max(v[i], Ewin);
        }
        long double ans = expm1(v[0]) * W;
        cout << '$' << fixed << setprecision(2) << ans << endl;
        int residualDigit = int(1000*ans) % 10;
        if (residualDigit == 4 || residualDigit == 5)
            cerr << "WARNING: " << residualDigit << " in the first unseen place" << endl;
    }
}
