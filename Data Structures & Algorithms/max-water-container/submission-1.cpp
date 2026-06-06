class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int i = 0;
        int j = n-1;
        int max_area = -1;

        while(i<j){
            int curr = (min(heights[i],heights[j])) * (j-i);
            max_area = max(max_area,curr);

            if(heights[i]>heights[j]) j--;
            else i++;
        }

        return max_area;
    }
};
