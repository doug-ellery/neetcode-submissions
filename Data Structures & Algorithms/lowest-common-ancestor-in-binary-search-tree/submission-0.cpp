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
    void helper(TreeNode*& lca, TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == nullptr){return;}
        if(root->val >= p->val && root->val <= q->val){
            lca = root;
            return;
        }
        if(root->val < p->val){
            helper(lca, root->right, p, q);
        }
        else{
            helper(lca, root->left, p, q);
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* lca = nullptr;
        if(p->val > q->val){
            TreeNode* temp = p;
            p = q;
            q = temp;
        }
        helper(lca, root, p, q);
        return lca;
    }
};
