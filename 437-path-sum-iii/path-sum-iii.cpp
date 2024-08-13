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
    int pathSum(TreeNode* root, int targetSum) {
        ios::sync_with_stdio(0); cin.tie(0);
        vector<long long> sums = {0};
        return pathSum(root, targetSum, &sums);
    }

    int pathSum(TreeNode* node, int targetSum, vector<long long>* prevSums) {
        if(node == nullptr) return 0;

        //cout << "\nI am a node with value: " << node->val << "\n";

        long long curSum = node->val + prevSums->at(prevSums->size() - 1);
        int ans = 0;
        for(auto u: *prevSums) {
            //cout << u << " ";
            if (curSum - u == targetSum) {
                ans++;
            }
        }

        prevSums->push_back(curSum);
        /*DEBUG for(auto u: *prevSums) {
            cout << u << " ";
        }*/
        ans += pathSum(node->left, targetSum, prevSums);
        ans += pathSum(node->right, targetSum, prevSums);
        prevSums->pop_back();

        return ans;
    }
};