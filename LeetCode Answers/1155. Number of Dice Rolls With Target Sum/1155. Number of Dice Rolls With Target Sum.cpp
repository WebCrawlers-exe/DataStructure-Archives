class Solution {
public:
    long long MOD = 1e9+7;
    
    long long solve(int dice, int faces, int target, vector<vector<int>> &dp)
    {
		// not possible to reach target
        if(target < 0)
            return 0;
        
		// no dice available
        if(dice == 0 and target != 0)
            return 0;
        
		// not possible
        if(target == 0 and dice != 0)
            return 0;
        
        if(target == 0 and dice == 0)
            return 1;
        
		// checking pre calculated answer
        if(dp[dice][target] != -1)
            return dp[dice][target];
        
        long long ans = 0;
        
		// trying all possible ways
        for(int i=1; i<=faces; i++)
            ans += solve(dice-1, faces, target-i, dp);
        
        return dp[dice][target] = ans%MOD;
    }
    
    int numRollsToTarget(int n, int k, int target) {
        
        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        
        return solve(n, k, target, dp);
    }
};