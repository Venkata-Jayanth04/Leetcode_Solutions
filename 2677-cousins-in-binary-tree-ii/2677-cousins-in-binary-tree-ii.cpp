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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (!root) return root;

        queue<TreeNode*> q;
        q.push(root);
        root->val = 0;

        while (!q.empty()) {
            int levelSize = q.size();
            int totalSum = 0;
            vector<TreeNode*> levelNodes;

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                levelNodes.push_back(node);

                if (node->left) totalSum += node->left->val;
                if (node->right) totalSum += node->right->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            for (TreeNode* node : levelNodes) {
                int siblingSum = 0;

                if (node->left) siblingSum += node->left->val;
                if (node->right) siblingSum += node->right->val;

                if (node->left) node->left->val = totalSum - siblingSum;
                if (node->right) node->right->val = totalSum - siblingSum;
            }
        }

        return root;
    }
};