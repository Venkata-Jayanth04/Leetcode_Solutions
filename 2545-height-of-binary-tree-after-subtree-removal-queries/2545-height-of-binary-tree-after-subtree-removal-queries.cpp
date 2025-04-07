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
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        unordered_map<int, int> depth, height;
        unordered_map<int, vector<int>> levelHeights;

        function<int(TreeNode*, int)> dfs = [&](TreeNode* node, int d) {
            if (!node) return -1;
            depth[node->val] = d;
            int leftHeight = dfs(node->left, d + 1);
            int rightHeight = dfs(node->right, d + 1);
            int h = max(leftHeight, rightHeight) + 1;
            height[node->val] = h;
            levelHeights[d].push_back(h);
            return h;
        };

        dfs(root, 0);

        for (auto& [d, heights] : levelHeights) {
            sort(heights.rbegin(), heights.rend());
        }

        vector<int> answer;
        int rootHeight = height[root->val];

        for (int q : queries) {
            int d = depth[q];
            int h = height[q];

            int newHeight;
            if (levelHeights[d].size() == 1) {
                newHeight = rootHeight - h - 1;
            } else if (levelHeights[d][0] == h) {
                newHeight = rootHeight - h + levelHeights[d][1];
            } else {
                newHeight = rootHeight;
            }

            answer.push_back(newHeight);
        }

        return answer;
    }
};