class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeros = 0;
        int ones = 0;
        int twos = 0;
        
        int itr = 0;
        
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] == 0) zeros++;
            if(nums[i] == 1) ones++;
            if(nums[i] == 2) twos++;
        }
        
        for(itr=0; itr<zeros; itr++)
            nums[itr] = 0;
        
        if(ones > 0){
        for(itr=zeros; itr<zeros+ones; itr++)
            nums[itr] = 1;
        }
        
        if(twos > 0){
        for(itr=zeros+ones; itr<zeros+ones+twos; itr++)
            nums[itr] = 2;
        }
        
        
    }
};