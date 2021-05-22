#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Leetcode 1293

struct Plan
{
    int x, y, k, s;

    Plan(int X, int Y, int K, int S) : x(X), y(Y), k(K), s(S) {  }
};

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        queue<Plan> todo;

        todo.emplace(Plan(0, 0, k, 0));
        vector<vector<int>> visited;
        int ymax = -1;
        for (int i = 0; i < grid.size(); i++)
        {
            vector<int> vec(grid[i].size(), -1);
            ymax = grid[i].size();
            visited.push_back(vec);
        }
        int xmax = grid.size();

        int minSteps = INT_MAX;

        while (!todo.empty())
        {
            Plan c = todo.front();
            todo.pop();
            visited[c.x][c.y] = c.k;

            if (c.x == xmax - 1 && c.y == ymax - 1)
            {
                minSteps = min(c.s, minSteps);
                continue;
            }

            if (c.y + 1 < ymax && c.k > visited[c.x][c.y + 1] && grid[c.x][c.y + 1] == 0)
            {
                todo.emplace(Plan(c.x, c.y + 1, c.k, c.s + 1));
                visited[c.x][c.y + 1] = c.k;
            }
            if (c.y + 1 < ymax && c.k > visited[c.x][c.y + 1] && grid[c.x][c.y + 1] == 1 && c.k > 0)
            {
                todo.emplace(Plan(c.x, c.y + 1, c.k - 1, c.s + 1));
                visited[c.x][c.y + 1] = c.k;
            }

            if (c.y > 0 && c.k > visited[c.x][c.y - 1] && grid[c.x][c.y - 1] == 0)
            {
                todo.emplace(Plan(c.x, c.y - 1, c.k, c.s + 1));
                visited[c.x][c.y - 1] = c.k;
            }
            if (c.y > 0 && c.k > visited[c.x][c.y - 1] && grid[c.x][c.y - 1] == 1 && c.k > 0)
            {
                todo.emplace(Plan(c.x, c.y - 1, c.k - 1, c.s + 1));
                visited[c.x][c.y - 1] = c.k;
            }

            if (c.x + 1 < xmax && c.k > visited[c.x + 1][c.y] && grid[c.x + 1][c.y] == 0)
            {
                todo.emplace(Plan(c.x + 1, c.y, c.k, c.s + 1));
                visited[c.x + 1][c.y] = c.k;
            }
            if (c.x + 1 < xmax && c.k > visited[c.x + 1][c.y] && grid[c.x + 1][c.y] == 1 && c.k > 0)
            {
                todo.emplace(Plan(c.x + 1, c.y, c.k - 1, c.s + 1));
                visited[c.x + 1][c.y] = c.k;
            }

            if (c.x > 0 && c.k > visited[c.x - 1][c.y] && grid[c.x - 1][c.y] == 0)
            {
                todo.emplace(Plan(c.x - 1, c.y, c.k, c.s + 1));
                visited[c.x - 1][c.y] = c.k;
            }
            if (c.x > 0 && c.k > visited[c.x - 1][c.y] && grid[c.x - 1][c.y] == 1 && c.k > 0)
            {
                todo.emplace(Plan(c.x - 1, c.y, c.k - 1, c.s + 1));
                visited[c.x - 1][c.y] = c.k;
            }
        }

        if (minSteps == INT_MAX)
        {
            return -1;
        }
        return minSteps;
    }
};