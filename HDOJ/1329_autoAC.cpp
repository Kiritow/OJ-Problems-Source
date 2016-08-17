#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define MAXN 50
int main(int ac, char *av[])
{
    vector < vector < int > > number;
    vector < int > result;
    int pegs = 1;
    number.resize(MAXN + 2);
    for (int i = 1; i <= MAXN; i++)
        number[i].push_back(0);
    for (int current = 1; pegs <= MAXN;)
    {
        bool successed = false;
        for (int c = 1; c <= pegs; c++)
        {
            int top = current + number[c][number[c].size() - 1];
            int value = sqrt(top);
            if (value * value == top)
            {
                number[c].push_back(current);
                successed = true;
                break;
            }
        }
        if (successed == false)
        {
            result.push_back(current - 1);
            pegs++;
            number[pegs].push_back(current);
            current++;
        }
        else
            current++;
    }
    int cases, n;
    cin >> cases;
    while (cases--)
    {
        cin >> n;
        cout << result[n - 1] << endl;
    }
    return 0;
}
