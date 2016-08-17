#include <iostream>
#include <vector>
using namespace std;
int main(void) {
    for (int n, k; cin >> n >> k && n * k != 0; ) {
        vector<int> Circle; 
        for (int i = 0; i < n; Circle.push_back(++i));
        for (int m = (k - 1) % Circle.size(), t; Circle.size() != 1; ) {
            t = (m - 1 + k) % (Circle.size() - 1);
            t = (t + (t >= m)) % Circle.size();
            Circle[m] = Circle[t];
            Circle.erase(Circle.begin() + t);
            m = (m - (t < m) + k) % Circle.size();
        } 
        cout << (n - Circle.front() + 1) % n + 1 << endl;
    }
    return 0;
}
