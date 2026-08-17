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
    void helper(bool& stat, TreeNode* p, TreeNode* q){
        if(p == nullptr && q == nullptr){return;}
        if(p != nullptr && q != nullptr){
            if(p->val != q->val){
                stat = false;
                return;
            }
            helper(stat, p->left, q->left);
            helper(stat, p->right, q->right);
        }
        else{
            stat = false;
            return;
        }
    }

    void find_subtree(bool& is_subtree, TreeNode* root, TreeNode* subRoot){
        if(root == nullptr){
            return;
        }
        bool stat = true;
        helper(stat, root, subRoot);
        if(stat){
            is_subtree = true;
            return;
        }
        find_subtree(is_subtree, root->left, subRoot);
        find_subtree(is_subtree, root->right, subRoot);
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
       bool is_subtree = false;
       find_subtree(is_subtree, root, subRoot);
       return is_subtree;
    }
};
