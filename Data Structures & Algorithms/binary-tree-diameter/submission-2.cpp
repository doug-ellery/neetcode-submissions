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
    int max_depth(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        return 1 + max(max_depth(root->left), max_depth(root->right));
    }
    void answer(TreeNode* root, int& my_max){
        if(root->right != nullptr && root->left != nullptr){
            my_max = max(my_max, max_depth(root->left) + max_depth(root->right));
            answer(root->right, my_max);
            answer(root->left, my_max);
        }
        else if(root->right != nullptr){
            my_max = max(my_max, max_depth(root->right));
            answer(root->right, my_max);
        }
        else if(root->left != nullptr){
            my_max = max(my_max, max_depth(root->left));
            answer(root->left, my_max);
        }
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr){return 0;}
        int my_max = 0;
        answer(root, my_max);
        return my_max;
    }
};
