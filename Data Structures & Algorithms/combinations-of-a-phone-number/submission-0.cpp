class Solution {
public:

    vector<string> ans;

    void solve(string digits, unordered_map<char, string> mp, int index, string s){
        // base condition

        if(index == digits.size()){
            ans.push_back(s);
        }


        for(auto x : mp[digits[index]]){
            s.push_back(x);
            solve(digits, mp, index+1, s);
            s.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        unordered_map<char, string> mp;

        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        string s;

        solve(digits, mp, 0, s);

        return ans;
    }
};
