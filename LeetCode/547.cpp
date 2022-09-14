
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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DisjointSet dset(n);
        for (int i = 0; i < n; i++)
        {
            dset.setParent(i, i);
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                if (isConnected[i][j]) {
                    dset.setParent(i, j);
                }
            }
        }

        return dset.countRoot;
    }
};
