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
    void search(TreeNode* root, int& my_max, int curr_depth){
        if(root->right != nullptr){search(root->right, my_max, curr_depth + 1);}
        if(root->left != nullptr){search(root->left, my_max, curr_depth + 1);}
        if(root->right == nullptr && root->left == nullptr){
            my_max = max(curr_depth, my_max);
        }
        return;
    }
    int maxDepth(TreeNode* root) {
        if(root == nullptr){return 0;}
        int my_max = INT_MIN;
        search(root, my_max, 1);
        return my_max;
    }
};
