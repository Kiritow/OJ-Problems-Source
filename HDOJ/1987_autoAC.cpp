#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;
typedef pair<int , int> P;
const int dx[] = {0 , 1 , 0 , -1} , dy[] = {1 , 0 , -1 , 0};
const int MAX = 30;
int array[MAX][MAX];
int main()
{
    int t;
    cin >> t;
    for(int s = 1; s <= t; ++s)
    {
        int r , c;
        string cipher;
        cin >> r >> c >> cipher;
        fill(*array , *array + MAX * MAX , -1);
        size_t cnt = 0;
        for(int i = 0; cnt < cipher.size() && i < r; ++i)
            for(int j = 0; cnt < cipher.size() && j < c; ++j)
            {array[i][j] = cipher[cnt ++] - '0';}
        //decode
        cout << s << ' ';
        P pos(0 , 0);
        int direc = 0;
        string decode;
        for(int i = 1; i <= (r * c / 5); ++i)
        {
            int val = 0;
            for(int k = 1; k <= 5; ++k)
            {
                int x = pos.first , y = pos.second;
                if(array[x][y] == -1 || x < 0 || x >= r || y < 0 || y >= c)
                {
                    int px = x + dx[direc] , py = y + dy[direc];
                    while(array[px][py] == -1 || px < 0 || px >= r || py < 0 || py >= c)
                    {
                        ++direc;
                        direc %= 4;
                        px = x + dx[direc] , py = y + dy[direc];
                    }
                    x = px;y = py;
                }
                    val = 2 * val + array[x][y];
                array[x][y] = -1;
                pos.first = x;pos.second = y;
            }
            if(val == 0)
            {decode += ' ';}
            else{decode += static_cast<char>(val - 1 + 'A');}
        }
        int end = decode.size() - 1;
        while(decode[end] == ' '){--end;}
        for(int i = 0; i <= end; ++i){cout << decode[i];}
        cout << endl;
    }
    return 0;
}
