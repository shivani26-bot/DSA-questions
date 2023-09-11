/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
         if (!root) return nullptr;

    Node* temp = root;
    queue<Node*> q;
    q.push(temp);

    while (!q.empty()) {
        int size = q.size();
        Node* prev = nullptr; // Track the previous node at the same level.

        for (int i = 0; i < size; i++) {
            Node* curr = q.front();
            q.pop();

            // Connect the current node to the previous node.
            if (prev) {
                prev->next = curr;
            }

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);

            prev = curr;
        }
    }

    return root;
    }
};