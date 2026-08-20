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
    struct dfs_node{
        TreeNode* node;
        pair<int,int> range;
        dfs_node(TreeNode* nd, pair<int,int> rg) : node(nd), range(rg){}
    };
    bool isValidBST(TreeNode* root) {
        stack<dfs_node> dfs_stack;
        dfs_stack.push(dfs_node(root, {INT_MIN,INT_MAX}));
        while(!dfs_stack.empty()){
            TreeNode* curr_node = dfs_stack.top().node;
            pair<int,int> range = dfs_stack.top().range;
            dfs_stack.pop();
            if(curr_node->val <= range.first || curr_node->val >= range.second){
                return false;
            }
            if(curr_node->left != nullptr){
                dfs_stack.push(dfs_node(curr_node->left, {range.first, curr_node->val}));
            }
            if(curr_node->right != nullptr){
                dfs_stack.push(dfs_node(curr_node->right, {curr_node->val, range.second}));
            }
        }
        return true;
    }
};
