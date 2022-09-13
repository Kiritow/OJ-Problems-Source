class Trie {
public:
    struct Node
    {
        bool ends;
        int number;
        Node* next[2];

        Node()
        {
            ends = false;
            memset(next, 0, sizeof(next));
        }
    };
    Node* root;

    Trie() {
        root = new Node;
    }

    inline void stepDownInsert(int* bits, int leftBits, int number, Node* current) {
        if (!leftBits) {
            current->ends = true;
            current->number = number;
            return;
        }

        if (!current->next[bits[leftBits - 1]]) {
            auto n = new Node;
            current->next[bits[leftBits - 1]] = n;
        }
        stepDownInsert(bits, leftBits - 1, number, current->next[bits[leftBits - 1]]);
    }

    void insert(int number) {
        int bits[32] = { 0 };
        int input = number;
        int index = 0;
        while (input) {
            bits[index++] = input & 0x1;
            input >>= 1;
        }
        stepDownInsert(bits, 31, number, root);
    }
};

class Solution {
public:
    Trie t;

    int findMaximumXOR(vector<int>& nums) {
        for (auto& n : nums) {
            t.insert(n);
        }

        int maxResult = 0;

        for (auto& n : nums) {
            int bits[32] = { 0 };
            int input = n;
            int index = 0;
            while (input) {
                bits[index++] = input & 0x1;
                input >>= 1;
            }

            auto current = t.root;
            int result = 0;
            for (int i = 30; i >= 0; i--) {
                result <<= 1;
                if (bits[i] && current->next[0]) {
                    current = current->next[0];
                    result++;
                }
                else if (!bits[i] && current->next[1]) {
                    current = current->next[1];
                    result++;
                }
                else {
                    current = current->next[0] ? current->next[0] : current->next[1];
                }
            }

            maxResult = max(maxResult, result);
        }

        return maxResult;
    }
};
