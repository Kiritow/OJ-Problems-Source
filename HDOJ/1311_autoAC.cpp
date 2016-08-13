#include <stdio.h>
#include <queue>
#include <string.h>
#include <algorithm>
#include <set>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
int father[110];
struct data
{
    string father, child;
    int dis;
    int age;
};
int n;
data family[200];
bool sign[200];
void dfs(string str, int year)
{
    for(int i=0; i<n; i++)
    {
        if(family[i].father == str && !sign[i])
        {
            family[i].age = year - family[i].dis;;
            sign[i] = 1;
            dfs(family[i].child, family[i].age);
        }
    }
}
bool cmp(data a, data b)
{
    if(a.age != b.age)
        return a.age > b.age ? 1:0;
    else
        return a.child < b.child ? 1:0;
}
int main()
{    
    int T;
    int co = 1;
    scanf("%d\n", &T);
    while(T--)
    {
        printf("DATASET %d\n", co++);
        scanf("%d", &n);
        int flag;
        memset(sign, 0, sizeof(sign) );
        for(int i=0; i<n; i++)
        {
            cin >> family[i].father >> family[i].child >> family[i].dis;
        }
        dfs("Ted", 100);
        sort(family, family+n, cmp);
        for(int i=0; i<n; i++)
            cout << family[i].child << ' ' << family[i].age << endl;
    }
    return 0;
}
