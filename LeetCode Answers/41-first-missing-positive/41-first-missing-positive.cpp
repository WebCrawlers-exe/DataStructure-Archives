class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int min=1;
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++)
        {
            if(min==nums[i])
            {
                min++;
            }
        }
        return min;
    }
};