
class Trie {
public:
    struct Node
    {
        bool ends;
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
            return;
        }

        if (!current->next[word[index] - 'a']) {
            current->next[word[index] - 'a'] = new Node;
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

class WordDictionary {
public:
    Trie t;
    WordDictionary() {

    }

    void addWord(string word) {
        t.insert(word);
    }

    inline bool stepDownSearch(const string& word, int index, Trie::Node* current) {
        if (index >= word.size()) return current->ends;
        if (word[index] == '.') {
            for (int i = 0; i < 26; i++)
            {
                if (current->next[i] && stepDownSearch(word, index + 1, current->next[i])) return true;
            }
            return false;
        }

        if (current->next[word[index] - 'a']) return stepDownSearch(word, index + 1, current->next[word[index] - 'a']);
        return false;
    }

    bool search(string word) {
        return stepDownSearch(word, 0, t.root);
    }
};
