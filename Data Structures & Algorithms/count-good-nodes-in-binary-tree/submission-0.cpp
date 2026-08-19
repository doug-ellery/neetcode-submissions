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
    int goodNodes(TreeNode* root) {
        int good_nodes = 0;
        stack<pair<TreeNode*, int>> dfs_stack;
        dfs_stack.push({root, INT_MIN});
        while(!dfs_stack.empty()){
            TreeNode* curr_node = dfs_stack.top().first;
            int curr_max = dfs_stack.top().second;
            dfs_stack.pop();
            if(curr_node->val >= curr_max){
                curr_max = curr_node->val;
                good_nodes++;
            }
            if(curr_node->left != nullptr){
                dfs_stack.push({curr_node->left, curr_max});
            }
            if(curr_node->right != nullptr){
                dfs_stack.push({curr_node->right, curr_max});
            }
        }
        return good_nodes;
    }
};
