class Solution {
public:

    int ans = 0;

    void check(int i, int j, string s){

        while(i>=0 && j<s.size()){
            if(s[i] == s[j]){
                ans++;
            }
            else{
                break;
            }
            i--;
            j++;
        }
    }

    int countSubstrings(string s) {
        int n = s.size();

        for(int i=0;i<n;i++){
            check(i,i,s);
        }

        for(int i=0;i<n-1;i++){
            check(i,i+1,s);
        }

        return ans;
    }
};
