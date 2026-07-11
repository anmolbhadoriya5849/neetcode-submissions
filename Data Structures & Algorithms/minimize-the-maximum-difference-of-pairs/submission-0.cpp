class Solution {
public:

    bool check(int mid, vector<int>& nums, int p){
        int cnt = 0;

        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]-nums[i] <= mid){
                cnt++;
                i++;
            }
        }

        return cnt >= p;
    }

    int minimizeMax(vector<int>& nums, int p) {
        int low = 0;

        sort(nums.begin(),nums.end());

        int high = nums[nums.size()-1] - nums[0];

        while(low < high){
            int mid = low + (high - low) / 2;

            if(check(mid, nums, p)){
                high = mid;
            }
            else{
                low = mid+1;
            }
        }

        return low;
    }
};