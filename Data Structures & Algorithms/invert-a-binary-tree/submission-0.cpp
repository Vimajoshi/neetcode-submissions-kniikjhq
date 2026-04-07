/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }

        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            // Get the node from the front of the queue
            TreeNode* current = q.front();
            q.pop();

            // Swap its children
            std::swap(current->left, current->right);

            // Add the children to the queue if they exist
            // (Note: we add the *new* left and *new* right)
            if (current->left != nullptr) {
                q.push(current->left);
            }
            if (current->right != nullptr) {
                q.push(current->right);
            }
        }

        return root;
    }
};
