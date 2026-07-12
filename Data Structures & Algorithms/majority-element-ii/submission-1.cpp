class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int maj1 = 0;
        int maj2 = 0;
        int cnt1 = 0;
        int cnt2 = 0;

        int n = nums.size();

        for(int i=0;i<n;i++){
            if(maj1 == nums[i]){
                cnt1++;
            }
            else if(maj2 == nums[i]){
                cnt2++;
            }
            else if(cnt1 == 0){
                maj1 = nums[i];
                cnt1++;
            }
            else if(cnt2 == 0){
                maj2 = nums[i];
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }

        int freq1 = 0;
        int freq2 = 0;

        vector<int> ans;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==maj1){
                freq1++;
            }
            else if(nums[i]==maj2){
                freq2++;
            }
        }
        if(freq1 > (n/3)) ans.push_back(maj1);
        if(freq2 > (n/3)) ans.push_back(maj2);

        return ans;
    }


};