//first i tried nums[i] == nums[i-1] approach but then i realized it 
// can be done only on when array is sorted

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {

        unordered_map<int,int> mp;

        for (int i=0; i<nums.size(); i++) {
            mp[nums[i]]++;
        }

        for (int i=0; i<nums.size(); i++){
            if(mp[nums[i]] > 1){
                return true;
            }
        }

        return false;
    }
};