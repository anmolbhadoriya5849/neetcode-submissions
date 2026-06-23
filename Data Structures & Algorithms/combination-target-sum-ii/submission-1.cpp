class Solution {
public:

    vector<vector<int>> ans;

    void dfs(vector<int>& nums, int target, vector<int>& arr, int sum, int index) {
        if(sum > target) return;
        if(sum == target){
            ans.push_back(arr);
            return;
        }

        //loop
        for(int i=index;i<nums.size();i++){
            if(i > index && nums[i] == nums[i-1]) continue;
            arr.push_back(nums[i]);
            dfs(nums, target, arr, sum+nums[i], i+1);
            arr.pop_back();
        };
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector<int> arr;
        sort(candidates.begin(),candidates.end());

        dfs(candidates, target, arr, 0, 0);

        return ans;
    }
};
