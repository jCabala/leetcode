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
    int goodNodes(TreeNode* root) {
        return getGoodNodes(root, -10e4);
    }

    int getGoodNodes(TreeNode* node, int maxVal) {
        if (node == nullptr) return 0;
        
        int res = 0;
        if (node->val >= maxVal) {
            res = 1;
            maxVal = node->val;
        }

        return res + 
        getGoodNodes(node->left, maxVal) + getGoodNodes(node->right, maxVal);
    }
};