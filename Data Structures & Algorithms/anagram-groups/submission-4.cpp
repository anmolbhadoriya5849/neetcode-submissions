class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        if(strs.size()==0 || strs.size()==1){
            ans.push_back(strs);
            return ans;
        }

        unordered_map<string,vector<string>> mp;


        for (int i=0;i<strs.size();i++){
            vector<int> s(26,0);
            for (int j=0;j<strs[i].size();j++){
                int idx = strs[i][j] - 'a';
                s[idx] += 1; 
            }
            string ss="";
            for(int k=0;k<26;k++){
                ss += to_string(s[k]) + '#';
            }

            mp[ss].push_back(strs[i]);


        }

        for (auto x : mp){
            ans.push_back(x.second);
        }

        return ans;

    }
};
