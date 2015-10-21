// Contains Duplicate II

// Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k.


//My Solution

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        if(nums.size() == 0)
            return false;
        
        unordered_set<int> s;
        if(nums.size() <= k)
        {
            for(int n:nums)
            {
                if(s.find(n) == s.end())
                {
                    s.insert(n);
                }
                else
                {
                    return true;
                }
                
            }
        }
        else
        {
            for(int i = 0; i<= k;i++)
            {
                if(s.find(nums[i]) == s.end())
                {
                    s.insert(nums[i]);
                }
                else
                {
                    return true;
                }
            }
            int j = k+1;
            while(j < nums.size())
            {
                s.erase(nums[j-k-1]);
                
                if(s.find(nums[j]) == s.end())
                {
                    s.insert(nums[j]);
                }
                else
                {
                    return true;
                }
                j++;
            }
            
        }
        
        return false;
        
    }
};
