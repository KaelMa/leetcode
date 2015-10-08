// Contains Duplicate

// Given an array of integers, find if the array contains any duplicates. Your function should 

// return true if any value appears at least twice in the array, and it should return false if every element is distinct.


//My solution

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        if(nums.size() == 0 )
            return false;
        
        unordered_set<int> mark;
        
        for(int i:nums)
        {
            if(mark.find(i) == mark.end())
                mark.insert(i);
            else
                return true;
        }
        
        return false;
        
    }
};