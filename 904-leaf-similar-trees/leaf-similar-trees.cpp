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
    void leafValues(TreeNode * node , vector<int>&list){
        if(!node) return;
        if(!node->left && !node->right){
            list.push_back(node->val);
            return;
        }
        leafValues(node->left , list);
        leafValues(node->right , list);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> list_root1,list_root2;
        leafValues(root1,list_root1);
        leafValues(root2,list_root2);
        return list_root1 == list_root2;
    }
};