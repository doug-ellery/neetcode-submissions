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
    int max_height(TreeNode* root){
        if(root == nullptr){return 0;}
        return max(1 + max_height(root->right), 1 + max_height(root->left));
    }

    

    void helper(bool& stat, TreeNode* root){
        if(root == nullptr){return;}
        if(abs(max_height(root->left) - max_height(root->right)) > 1){
            stat = false;
            return;
        }
        helper(stat, root->left);
        helper(stat, root->right);
    }
    
    bool isBalanced(TreeNode* root) {
        bool stat = true;
        helper(stat, root);
        return stat;
    }
};
