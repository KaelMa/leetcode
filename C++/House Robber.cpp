// House Robber

// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.



//My solution
//dp

class Solution {
public:
    int rob(vector<int>& nums) 
    {
        int i = nums.size();
        
        if( i == 0 )
            return 0;
        
        if(i == 1)
            return nums[0];
        
        if(i == 2)
            return max(nums[0],nums[1]);
            
        
        vector<int> f(i);
        
        f[0] = nums[0];
        f[1] = max(nums[0],nums[1]);
        
        for(int k = 2;k < i; k++)
        {
            f[k] = max(f[k-2]+nums[k],f[k-1]);
        }
        
        return f[i-1];
        
    }
};