class Solution {
public:

    int solve(vector<int>& coins, int amount, vector<vector<int>>& dp, int index){

        if(amount < 0) return 0;

        if(amount == 0) return 1;

        if(dp[amount][index] != 0)
            return dp[amount][index];

        int ans;

        for(int i=index; i<coins.size(); i++){

            ans += solve(coins, amount - coins[i], dp, i);

        }

        return dp[amount][index] = ans;
    }



    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(amount+1, vector<int>(coins.size(), 0));

        return solve(coins, amount, dp, 0);
    }
};
