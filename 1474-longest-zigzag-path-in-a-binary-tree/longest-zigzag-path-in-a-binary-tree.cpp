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
int ans;

    int longestZigZag(TreeNode* root) {
        ios::sync_with_stdio(0); cin.tie(0);
        ans = 0;
        longestZigZag(root->left, 0, 1);
        longestZigZag(root->right, 1, 1);
        return ans;
    }

    void longestZigZag(TreeNode* node, bool goLeft, int cnt) {
       if(node == nullptr) return;
       ans = max(ans, cnt);
       if(goLeft) {
        longestZigZag(node->left, !goLeft, cnt + 1);
        longestZigZag(node->right, goLeft, 1);
       } else {
        longestZigZag(node->right, !goLeft, cnt + 1);
        longestZigZag(node->left, goLeft, 1);
       }
    }
};