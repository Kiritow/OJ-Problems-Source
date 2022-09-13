
class Trie {
public:
    struct Node
    {
        bool ends;
        string word;
        Node* next[26];

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

    inline void stepDownInsert(const string& word, int index, Node* current) {
        if (index >= word.size()) {
            current->ends = true;
            current->word = word;
            return;
        }

        if (!current->next[word[index] - 'a']) {
            auto n = new Node;
            current->next[word[index] - 'a'] = n;
        }
        stepDownInsert(word, index + 1, current->next[word[index] - 'a']);
    }

    void insert(string word) {
        stepDownInsert(word, 0, root);
    }

    inline bool stepDownSearch(const string& word, int index, Node* current) {
        if (index >= word.size()) return current->ends;
        if (current->next[word[index] - 'a']) return stepDownSearch(word, index + 1, current->next[word[index] - 'a']);
        return false;
    }

    bool search(string word) {
        return stepDownSearch(word, 0, root);
    }

    inline bool stepDownPrefix(const string& word, int index, Node* current) {
        if (index >= word.size()) return true;
        if (current->next[word[index] - 'a']) return stepDownPrefix(word, index + 1, current->next[word[index] - 'a']);
        return false;
    }

    bool startsWith(string prefix) {
        return stepDownPrefix(prefix, 0, root);
    }
};

class Solution {
public:
    Trie t;

    void stepDownFind(vector<vector<char>>& board, vector<vector<bool>>& visited, unordered_set<string>& found, int line, int col, Trie::Node* current) {
        if (current->ends) {
            found.insert(current->word);
        }

        // go up
        if (line > 0 && !visited[line - 1][col] && current->next[board[line-1][col] - 'a']) {
            visited[line - 1][col] = true;
            stepDownFind(board, visited, found, line - 1, col, current->next[board[line - 1][col] - 'a']);
            visited[line - 1][col] = false;
        }
        // go down
        if (line < board.size() - 1 && !visited[line + 1][col] && current->next[board[line + 1][col] - 'a']) {
            visited[line + 1][col] = true;
            stepDownFind(board, visited, found, line + 1, col, current->next[board[line + 1][col] - 'a']);
            visited[line + 1][col] = false;
        }
        // go left
        if (col > 0 && !visited[line][col - 1] && current->next[board[line][col - 1] - 'a']) {
            visited[line][col - 1] = true;
            stepDownFind(board, visited, found, line, col - 1, current->next[board[line][col - 1] - 'a']);
            visited[line][col - 1] = false;
        }
        // go right
        if (col < board[line].size() - 1 && !visited[line][col + 1] && current->next[board[line][col + 1] - 'a']) {
            visited[line][col + 1] = true;
            stepDownFind(board, visited, found, line, col + 1, current->next[board[line][col + 1] - 'a']);
            visited[line][col + 1] = false;
        }
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (auto& word : words) {
            t.insert(word);
        }

        vector<vector<bool>> visited;
        for (int i = 0; i < board.size(); i++)
        {
            visited.emplace_back(board[i].size(), false);
        }

        unordered_set<string> found;

        for (int line = 0; line < board.size(); line++) {
            for (int col = 0; col < board[line].size(); col++) {
                if (t.root->next[board[line][col] - 'a']) {
                    visited[line][col] = true;
                    stepDownFind(board, visited, found, line, col, t.root->next[board[line][col] - 'a']);
                    visited[line][col] = false;
                }
            }
        }

        return vector<string>(found.begin(), found.end());
    }
};
