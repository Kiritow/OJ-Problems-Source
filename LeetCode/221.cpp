#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Leetcode 221

class Solution
{
public:
    int maximalSquare(vector<vector<char>>& matrix)
    {
        vector<vector<int>> vec;
        for (int i = 0; i < matrix.size(); i++)
        {
            vector<int> tvec(matrix[i].size(), 0);
            vec.push_back(tvec);
        }

        for (int i = 0; i < matrix.size(); i++)
        {
            if (matrix[i][0] == '1')
            {
                vec[i][0] = 1;
            }
            else
            {
                vec[i][0] = 0;
            }
        }

        for (int j = 0; j < matrix[0].size(); j++)
        {
            if (matrix[0][j] == '1')
            {
                vec[0][j] = 1;
            }
            else
            {
                vec[0][j] = 0;
            }
        }

        for (int i = 1; i < matrix.size(); i++)
        {
            for (int j = 1; j < matrix[i].size(); j++)
            {
                if (matrix[i][j] == '0')
                {
                    vec[i][j] = 0;
                    continue;
                }

                if (matrix[i][j] == '1')
                {
                    if (vec[i - 1][j] && vec[i][j - 1] && vec[i-1][j-1])
                    {
                        vec[i][j] = min(min(vec[i - 1][j], vec[i][j - 1]), vec[i - 1][j - 1]) + 1;
                    }
                    else
                    {
                        vec[i][j] = 1;
                    }
                }
            }
        }

        int nMax = 0;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                cout << vec[i][j] << " ";
                nMax = max(nMax, vec[i][j]);
            }
            cout << endl;
        }

        return nMax * nMax;
    }
};