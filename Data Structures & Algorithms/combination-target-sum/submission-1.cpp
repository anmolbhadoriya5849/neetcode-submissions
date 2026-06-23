class Solution {
public:

    vector<vector<int>> ans;

    void dfs(vector<int>& nums, int target, int sum, vector<int>& arr, int index) {
        if(sum > target) return;
        if(sum == target){
            ans.push_back(arr);
            return;
        }

        // choose
        for(int i=index;i<nums.size();i++){
            arr.push_back(nums[i]);
            dfs(nums,target,sum+nums[i],arr,i);
            arr.pop_back();
        }

    }


    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        
        vector<int> arr;
        dfs(nums, target, 0, arr, 0);

        return ans;
    }
};
