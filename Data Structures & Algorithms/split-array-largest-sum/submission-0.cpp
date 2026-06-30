class Solution {
public:

    bool solve(vector<int>& nums, int mid, int k){

        int currSum = 0;
        int cnt = 1;
        
        for(int i=0;i<nums.size();i++){

            if(nums[i] > mid) return false;

            if(currSum+nums[i]>mid || i == nums.size()){

                
                cnt++;
                currSum = nums[i];

                if(cnt > k) return false;
            }
            else{
                currSum += nums[i];
            }
        }

        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = nums[0];
        int high = nums[0];
        
        for(int i=1;i<nums.size();i++){
            low = max(low,nums[i]);
            high += nums[i];
        }

        int maxSum = INT_MIN;

        while(low<=high){
            int mid = low + (high-low)/2;

            bool check = solve(nums, mid, k);

            if(check){
                high = mid-1;
                maxSum = mid;
            }
            else{
                low = mid+1;
            }
        }

        return maxSum;
    }
};