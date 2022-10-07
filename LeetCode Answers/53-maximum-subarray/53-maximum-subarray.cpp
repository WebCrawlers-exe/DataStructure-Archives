class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int i,n = nums.size();
        int res = nums[0];
        int maxEnding = nums[0]; 
        
        for(i=1;i<n;i++)
        {
            maxEnding = max(maxEnding + nums[i] , nums[i]);
            res = max(res,maxEnding);
        }
        return res;
    }
};