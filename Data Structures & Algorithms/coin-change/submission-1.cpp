class Solution {
public:

    int solve(vector<int>& coins, int amount, vector<int>& dp){

        if(amount < 0) return -1;

        if(amount == 0) return 0;

        if(dp[amount] != 1e9)
            return dp[amount];

        int ans = INT_MAX;

        for(int coin : coins){

            int res = solve(coins, amount - coin, dp);

            if(res != -1){
                ans = min(ans, 1 + res);
            }
        }

        if(ans == INT_MAX)
            return dp[amount] = -1;

        return dp[amount] = ans;
    }

    int coinChange(vector<int>& coins, int amount) {

        vector<int> dp(amount + 1, 1e9);

        return solve(coins, amount, dp);
    }
};