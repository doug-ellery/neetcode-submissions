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
    void flip_flop(TreeNode* root){
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        if(root->left != nullptr){flip_flop(root->left);}
        if(root->right != nullptr){flip_flop(root->right);}
        return;
    }
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr){return nullptr;}
        flip_flop(root);
        return root;
    }
};
