class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        for (int i = 0; i<strs.size();i++){
            int size = strs[i].size();
            ans += to_string(size) + '#' + strs[i];
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;

        string s1 = "";
        int j = 0;


        while(j < s.size()){

            string key = "";
            while(s[j]!='#'){
                key += s[j];
                j++;
            }
            int num = stoi(key);
            j++;
            num += j;
            while(j < num){
                s1 += s[j];
                j++;
            }
            ans.push_back(s1);
            s1 = "";
        }

        return ans;
    }
};
