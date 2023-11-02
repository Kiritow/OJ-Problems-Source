
class Solution {
public:
    Node* processLevel(Node* leftMost) {
        Node* nextLevelLeftMost = nullptr;
        Node* nextLevelNext = nullptr;
        for (Node* current = leftMost; current != nullptr; current = current->next) {
            if (current->left && current->right) {
                current->left->next = current->right;
                if (!nextLevelLeftMost) {
                    nextLevelLeftMost = current->left;
                    nextLevelNext = current->right;
                }
                else {
                    nextLevelNext->next = current->left;
                    nextLevelNext = current->right;
                }
            }
            else if (current->left) {
                if (!nextLevelLeftMost) {
                    nextLevelLeftMost = current->left;
                    nextLevelNext = current->left;
                }
                else {
                    nextLevelNext->next = current->left;
                    nextLevelNext = current->left;
                }
            }
            else if (current->right) {
                if (!nextLevelLeftMost) {
                    nextLevelLeftMost = current->right;
                    nextLevelNext = current->right;
                }
                else {
                    nextLevelNext->next = current->right;
                    nextLevelNext = current->right;
                }
            }
        }

        return nextLevelLeftMost;
    }

    Node* connect(Node* root) {
        Node* nextLevelEntry = root;
        while (nextLevelEntry) {
            nextLevelEntry = processLevel(nextLevelEntry);
        }
        return root;
    }
};
