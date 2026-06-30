class Solution {
public:

    int solve(vector<int>& piles, int k){
        int ans = 0;

        for(int i=0;i<piles.size();i++){
            ans += (piles[i] + k - 1) / k;
        }

        return ans;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int high = *std::max_element(piles.begin(), piles.end());
        int low = 1;
        int ans = INT_MAX;

        while(low<=high){
            int mid = low + (high-low)/2;

            int hour = solve(piles,mid);

            if(hour>h){
                low = mid + 1;
            }
            else if(hour<=h){
                high = mid - 1;
                ans = mid;
            }
        }
        return ans;
    }
};
