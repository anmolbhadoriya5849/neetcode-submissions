class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        vector<pair<int,int>> p;
        vector<int> ans;

        for (int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }

        for(auto x : mp){
            int number = x.first;
            int frequency = x.second;

            p.push_back({frequency,number});
        }

        sort(p.begin(), p.end(), greater<pair<int,int>>());

        for(int i=0;i<k;i++){
            ans.push_back(p[i].second);
        }

        return ans;
    }
};
