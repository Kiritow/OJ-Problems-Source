
class DisjointSet
{
public:
    int* parent;
    int countRoot;

    DisjointSet(int size) {
        parent = new int[size];
        memset(parent, 0xFF, sizeof(int) * size);
        countRoot = 0;
    }

    ~DisjointSet() {
        delete[] parent;
    }

    int find(int id) {
        if (parent[id] != -1 && parent[id] != id) {
            parent[id] = find(parent[id]);
        }

        // printf("parent of %d is %d\n", id, parent[id]);
        return parent[id];
    }

    void setParent(int child, int upper) {
        if (upper == child) {
            parent[child] = child;
            countRoot++;
        }
        else {
            if (parent[child] == -1) {
                parent[child] = child;
                countRoot++;
            }
            if (parent[upper] == -1) {
                parent[upper] = upper;
                countRoot++;
            }

            int childRoot = find(child);
            int upperRoot = find(upper);
            if (childRoot != upperRoot) countRoot--;

            // printf("set parent of %d to %d\n", childRoot, upperRoot);
            parent[childRoot] = upperRoot;
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet dset = DisjointSet(n * n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!grid[i][j]) continue;

                if (dset.find(i * n + j) == -1) {
                    dset.setParent(i * n + j, i * n + j);
                }

                if (i > 0 && grid[i - 1][j]) {
                    dset.setParent((i - 1) * n + j, i * n + j);
                }

                if (i < n - 1 && grid[i + 1][j]) {
                    dset.setParent((i + 1) * n + j, i * n + j);
                }

                if (j > 0 && grid[i][j - 1]) {
                    dset.setParent(i * n + j - 1, i * n + j);
                }

                if (j < n - 1 && grid[i][j + 1]) {
                    dset.setParent(i * n + j + 1, i * n + j);
                }
            }
        }

        unordered_map<int, int> areaMap;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!grid[i][j]) continue;

                int root = dset.find(i * n + j);
                auto iter = areaMap.find(root);
                if (iter != areaMap.end()) {
                    iter->second++;
                }
                else {
                    areaMap.insert_or_assign(root, 1);
                }
            }
        }

        int maxArea = 0;
        for (auto iter = areaMap.begin(); iter != areaMap.end(); iter++) {
            maxArea = max(maxArea, iter->second);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) continue;
                unordered_set<int> usedRoot;

                int totalArea = 1;
                if (i > 0 && grid[i-1][j]) {
                    int root = dset.find((i - 1) * n + j);
                    if (usedRoot.find(root) == usedRoot.end()) {
                        usedRoot.insert(root);
                        int area = areaMap.find(root)->second;
                        totalArea += area;
                    }
                }

                if (i < n - 1 && grid[i + 1][j]) {
                    int root = dset.find((i + 1) * n + j);
                    if (usedRoot.find(root) == usedRoot.end()) {
                        usedRoot.insert(root);
                        int area = areaMap.find(root)->second;
                        totalArea += area;
                    }
                }

                if (j > 0 && grid[i][j - 1]) {
                    int root = dset.find(i * n + j - 1);
                    if (usedRoot.find(root) == usedRoot.end()) {
                        usedRoot.insert(root);
                        int area = areaMap.find(root)->second;
                        totalArea += area;
                    }
                }

                if (j < n - 1 && grid[i][j + 1]) {
                    int root = dset.find(i * n + j + 1);
                    if (usedRoot.find(root) == usedRoot.end()) {
                        usedRoot.insert(root);
                        int area = areaMap.find(root)->second;
                        totalArea += area;
                    }
                }

                maxArea = max(maxArea, totalArea);
            }
        }

        return maxArea;
    }
};
