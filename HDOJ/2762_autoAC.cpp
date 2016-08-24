#include <iostream>
using namespace std;
const int MAXP = 100;
int dis(int *p1, int *p2)
{
    int d = 0;
    for(int i = 0; i < 3; ++i)
    {
        d += abs(p1[i] - p2[i]);
    }
    return d;
}
int main()
{
    int N;
    cin>>N;
    int points[MAXP][3];
    for(int no = 0; no < N; ++no)
    {
        int P;
        cin>>P;
        fscanf(stdin, "%d,%d,%d", &points[0][0], &points[0][1], &points[0][2]);
        int area = 6;
        bool iscorrect = true;
        cout<<no + 1<<" ";
        for(int i = 1; i < P; ++i)
        {
            fscanf(stdin, "%d,%d,%d", &points[i][0], &points[i][1], &points[i][2]);
            if(!iscorrect)
            {
                continue;
            }
            area += 6;
            int j = 0;
            bool isconnected = false;
            while(j < i)
            {
                int d = dis(points[i], points[j]);
                if(d == 0)
                {
                    break;
                }
                if(d == 1)
                {
                    isconnected = true;
                    area -= 2;
                }
                j++;
            }
            if(j != i || !isconnected)
            {
                iscorrect = false;
                cout<<"NO "<<i + 1<<endl;
            }
        }
        if(iscorrect)
        {
            cout<<area<<endl;
        }
    }
    return 0;
}
