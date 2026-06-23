class Solution {
public:

    vector<vector<int>> ans;

    void dfs(vector<int>& nums, vector<int>& arr, vector<bool>& visited) {

        if(arr.size()==nums.size()){
            ans.push_back(arr);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(visited[i]) continue;
            if(i>0 && nums[i] == nums[i-1] && !visited[i-1]) continue;
            arr.push_back(nums[i]);
            visited[i] = true;
            dfs(nums, arr, visited);
            arr.pop_back();
           visited[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> arr;
        sort(nums.begin(), nums.end());
        vector<bool> visited(nums.size(), false);
        dfs(nums,arr,visited);

        return ans;
    }
};