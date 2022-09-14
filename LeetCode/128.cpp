
class ArrayContainer {
public:
    unique_ptr<int[]> parent;
    ArrayContainer(int size, int nanVal) : parent(new int[size]) {
        if (nanVal == -1) memset(parent.get(), 0xFF, sizeof(int) * size);
        else fill(parent.get(), parent.get() + size, nanVal);
    }

    inline int get(int index) {
        return parent[index];
    }

    inline void set(int index, int val) {
        parent[index] = val;
    }
};

class UnorderedMapContainer {
public:
    unordered_map<int, int> parent;
    int nanVal;

    UnorderedMapContainer(int size, int nanVal) : nanVal(nanVal) {

    }

    inline int get(int index) {
        auto iter = parent.find(index);
        if (iter == parent.end()) return nanVal;
        return iter->second;
    }

    inline void set(int index, int val) {
        parent.insert_or_assign(index, val);
    }
};

template<typename ContainerType>
class DisjointSet
{
public:
    ContainerType parent;
    int countRoot;
    int nanVal;

    DisjointSet(int size, int nanVal) : parent(size, nanVal), countRoot(0), nanVal(nanVal) {
        
    }

    int find(int id) {
        if (parent.get(id) != nanVal && parent.get(id) != id) {
            parent.set(id, find(parent.get(id)));
        }

        //printf("parent of %d is %d\n", id, parent.get(id));
        return parent.get(id);
    }

    void setParent(int child, int upper) {
        if (upper == child) {
            parent.set(child, child);
            countRoot++;
        }
        else {
            if (parent.get(child) == nanVal) {
                parent.set(child, child);
                countRoot++;
            }
            if (parent.get(upper) == nanVal) {
                parent.set(upper, upper);
                countRoot++;
            }

            int childRoot = find(child);
            int upperRoot = find(upper);
            if (childRoot != upperRoot) countRoot--;

            //printf("set parent of %d to %d\n", childRoot, upperRoot);
            parent.set(childRoot, upperRoot);
        }
    }

    bool hasParent(int id) {
        return parent.get(id) != nanVal;
    }
};

// #define WRITE_LOG

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        DisjointSet<UnorderedMapContainer> dset(nums.size(), INT_MIN);

        for (auto& n : nums) {
            if (!dset.hasParent(n)) dset.setParent(n, n);

            if (dset.hasParent(n - 1)) {
                dset.setParent(n - 1, n);
            }
            if (dset.hasParent(n + 1)) {
                dset.setParent(n + 1, n);
            }
        }

        unordered_map<int, int> counter;
        unordered_set<int> inputset;
        int maxVal = 1;

#ifdef WRITE_LOG
        printf("output all parent\n");
        for (auto& n : nums) {
            printf("%d -> %d\n", n, dset.parent.get(n));
        }

        printf("find start...\n");
#endif

        for (auto& n : nums) {
            if (inputset.find(n) != inputset.end()) continue;
            inputset.insert(n);

            int p = dset.find(n);
            auto iter = counter.find(p);
            if (iter == counter.end()) {
                counter.insert({ p, 1 });
            }
            else {
                iter->second++;
                maxVal = max(maxVal, iter->second);
            }
        }

#ifdef WRITE_LOG
        printf("output all parent\n");
        for (auto& n : nums) {
            printf("%d -> %d\n", n, dset.parent.get(n));
        }
#endif

        return maxVal;
    }
};
