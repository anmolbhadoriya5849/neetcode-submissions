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
        bool left = false;

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
            if(left){
                reverse(temp.begin(),temp.end());
            }
            ans.push_back(temp);
            left = !left;
        }
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans;

        solve(root,ans);

        return ans;
    }
};