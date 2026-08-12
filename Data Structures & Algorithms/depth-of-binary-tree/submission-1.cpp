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
    int get_max(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        return 1 + max(get_max(root->right), get_max(root->left));
    }
    int maxDepth(TreeNode* root) {
        if(root == nullptr){return 0;}
        return get_max(root);
    }
};
