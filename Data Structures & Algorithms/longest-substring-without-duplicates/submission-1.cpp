class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
        unordered_set<int> st;
        int max_len = 0;

        for(int i=0;i<s.size();i++){
            if(st.count(s[i])){
                max_len = max(max_len, int(st.size()));
                st.clear();
                int j = i - 1;
                while (j >= 0 && s[j] != s[i]) {
                    st.insert(s[j]);
                    j--;
                }
            }
            st.insert(s[i]);
        }

        return max(max_len, int(st.size()));
    }
};
