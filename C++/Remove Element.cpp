// Remove Element

// Given an array and a value, remove all instances of that value in place and return the new length.

// The order of elements can be changed. It doesn't matter what you leave beyond the new length.



//My solution

class Solution {
public:
    int removeElement(vector<int>& nums, int val)
    {
        if(nums.size() == 0)
            return 0;
        
        sort(nums.begin(),nums.end());
        
        vector<int>::iterator m;
        int n = 0;
        for(auto ite = nums.begin(); ite < nums.end(); ite++)
        {
            if(*ite == val)
            {
                m = ite;
                while(*ite == val && ite < nums.end())
                {
                    n++;
                    ite++;
                }
            }
            
        }
        
        nums.erase(m,m+n);
        
        return nums.size();
        
    }
};

//a better solution

class Solution
{
public:
	int removeElement(vector<int>& nums,int val)
	{
		if(nums.size() == 0)
			return 0;

		int j = 0;
		for(int i = 0; i< nums.size(); i++)
		{
			if(nums[i] != val)
				nums[j++] = nums[i];
		}

		return j;
	}
}