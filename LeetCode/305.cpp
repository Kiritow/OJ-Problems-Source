
class DisjointSet
{
public:
    int* parent;
    int countRoot;

    DisjointSet(int size) {
        parent = new int[size + 1];
        memset(parent, 0, sizeof(int) * (size + 1));
        countRoot = 0;
    }

    int find(int id) {
        if (parent[id] && parent[id] != id) {
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
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        int sz = m * n;
        DisjointSet dset(sz);
        vector<int> results;

        for (auto& pr : positions) {
            int line = pr[0];
            int col = pr[1];
            int id = line * n + col + 1;

            if (dset.parent[id]) {
                results.push_back(dset.countRoot);
                continue;
            }

            dset.setParent(id, id);

            if (line > 0) {
                int upid = (line - 1) * n + col + 1;
                if (dset.parent[upid]) dset.setParent(upid, id);
            }

            if (line < m - 1) {
                int downid = (line + 1) * n + col + 1;
                if(dset.parent[downid]) dset.setParent(downid, id);
            }

            if (col > 0) {
                int leftid = line * n + col;
                if (dset.parent[leftid]) dset.setParent(leftid, id);
            }

            if (col < n - 1) {
                int rightid = line * n + col + 2;
                if (dset.parent[rightid]) dset.setParent(rightid, id);
            }

            results.push_back(dset.countRoot);
        }

        return results;
    }
};
