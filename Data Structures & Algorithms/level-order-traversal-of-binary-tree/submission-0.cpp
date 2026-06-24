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

    void solve(TreeNode* root, vector<vector<int>>& ans){
        
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();

            vector<int> temp;
            for(int i=0;i<size;i++){
                TreeNode* element = q.front();
                q.pop();
                temp.push_back(element->val);
                if(element->left) q.push(element->left);
                if(element->right) q.push(element->right);
            }
            ans.push_back(temp);
        }
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        solve(root, ans);

        return ans;
    }
};
