// Move Zeroes

// Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

// For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

// Note:
// You must do this in-place without making a copy of the array.
// Minimize the total number of operations.


//My solution

class Solution {
public:
    void moveZeroes(vector<int>& nums)
    {
        if(nums.size() == 0)
            return;
        
        auto ite = nums.begin();
        
        auto j = nums.end()-1;
        while(ite != j)
        {
            if(*ite == 0)
            {
                ite = nums.erase(ite);
                nums.push_back(0);
                j--;
            }
            else
            {
                ite++;
            }
            
        }
        
    }
};


//a better solution

class Solution{
public:
	void moveZeroes(vector<int>& nums)
	{
		if(nums.size() == 0)
			return;

		for(auto i=nums.begin(),j =i; i !=nums.end(); i++)
		{
			if(*i ! = nullptr)
				std::swap(*i,*j++);
		}


	}
}