// Pascal's Triangle II

// Given an index k, return the kth row of the Pascal's triangle.

// For example, given k = 3,
// Return [1,3,3,1].

// Note:
// Could you optimize your algorithm to use only O(k) extra space?


//My solution

class Solution {
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> res;
        
        if(rowIndex < 0)
            return res;
        
        res.push_back(1);
        if(rowIndex == 0)
            return res;
            
        res.push_back(1);
        if(rowIndex == 1)
            return res;
        
        int pre,cur;
        for(int i = 2;i<= rowIndex; i++)
        {   
            pre = 1;
            int k = res.size();
            for(int j = 1;j<= k;j++)
            {
                if(j != res.size())
                {
                    cur = res[j];
                    res[j] = pre + cur;
                
                    pre = cur;
                }
                else
                {
                    res.push_back(1);
                }
            }
        }
        
        return res;
    }
};


//a better solution
// from right to left

vector<int> getRow(int k) {
    vector<int>answer(k+1,0);

    for(int i=0;i<=k;i++){
        answer[k]=1;
        for(int j=k-1;j>0;j--){
            answer[j] += answer[j-1];
        }
        answer[0]=1;
    }
    return answer;
}

