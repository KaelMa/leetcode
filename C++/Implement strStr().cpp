// Implement strStr() My Submissions Question
// Total Accepted: 77168 Total Submissions: 333467 Difficulty: Easy
// Implement strStr().

// Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

// Subscribe to see which companies asked this question



//My solution
//KMP

class Solution {
public:
    int strStr(string haystack, string needle) 
    {
        int i = 0, j = 0;
        
        if(needle.size() == 0)
            return 0;
        
        int m = haystack.size();
        int n = needle.size();
        int next[n];
        getNext(needle,next);
        
        while((i < m) && (j < n))
        {
            if(j == -1 || haystack[i] == needle[j])
            {
                i++;
                j++;
            }
            else
            {
                j = next[j];
            }
        }
        
        if( j == needle.size())
            return i - j;
        else
            return -1;
    }
    
    void getNext(string pattern,int next[])
    {
        int l = pattern.size();
        next[0] = -1;
        
        int k;
        for(int j = 1; j< l; j++)
        {
            k = next[j-1];
            while(k >= 0)
            {
                if(pattern[k] == pattern[j-1])
                    break;
                else
                    k = next[k];
            }
            
            next[j] = k+1;
            
        }
        
    }
};