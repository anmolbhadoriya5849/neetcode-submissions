class Solution {
public:
    string convert(string s, int numRows) {

        if(numRows == 1) return s;
        
        vector<string> vec(numRows);

        int k = 0;

        bool down = true;

        for(int i=0;i<s.size();i++){
            vec[k] += s[i];

            if(down){
                k++;
                if(k == numRows){
                    down = false;
                    k = k-2;
                }
            }
            else{
                k--;
                if(k<0){
                    down = true;
                    k = k+2;
                }
            }
        }

        string ans = "";

        for(int i=0;i<numRows;i++){
            ans += vec[i];
        }

        return ans;
    }
};