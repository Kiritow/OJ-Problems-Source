#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int k , m , data , c, t;
    while(cin >> k && k && cin >> m)
    {
        vector<int> course;
        bool pass = true;
        while(k --)
        {
            cin >> data;
            course.push_back(data);
        }
        while(m --)
        {
            cin >> c >> t;
            if(pass)
            {
                int cnt = 0;
                while(c--)
                {
                    cin >> data;
                    if(find(course.begin() , course.end() , data) != course.end())
                    {++cnt;}
                }
                if(cnt < t)
                {pass = false;}
            }
            else
            {
                while(c --)
                {cin >> data;}
            }
        }
        cout << (pass ? "yes" : "no") << endl;
    }
    return 0;
}
