class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(mid+1<=high && nums[mid] == nums[mid+1]){
                if((high-mid+1) % 2 == 0){
                    high = mid-1;
                    cout<<high<<endl;
                }
                else{
                    low = mid+2;
                }
            }
            else if(mid-1 >= low && nums[mid] == nums[mid-1]){
                if((mid-low) % 2 == 0){
                    high = mid-2;
                }
                else{
                    low = mid+1;
                }
            }
            else return nums[mid];
        }
    }
};