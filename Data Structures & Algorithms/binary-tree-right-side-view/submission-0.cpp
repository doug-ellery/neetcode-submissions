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
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr){return {};}
        queue<pair<TreeNode*,int>> bfs_queue;
        vector<int> right_ones;
        bfs_queue.push({root, 0});
        while(!bfs_queue.empty()){
            TreeNode* curr_node = bfs_queue.front().first;
            int curr_level = bfs_queue.front().second;
            bfs_queue.pop();
            if(curr_level >= right_ones.size()){
                right_ones.push_back(curr_node->val);
            }
            if(curr_node->right != nullptr){
                bfs_queue.push({curr_node->right, curr_level + 1});
            }
            if(curr_node->left != nullptr){
                bfs_queue.push({curr_node->left, curr_level + 1});
            }
        }
        return right_ones;
    }
};
