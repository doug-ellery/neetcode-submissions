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
    void in_order_transverse(TreeNode* root, vector<int>& my_list){
        if(root != nullptr){
            in_order_transverse(root->left, my_list);
            my_list.push_back(root->val);
            in_order_transverse(root->right, my_list);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> order;
        in_order_transverse(root, order);
        return order[k - 1];
    }
};
