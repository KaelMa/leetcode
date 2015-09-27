// Rotate Image

// You are given an n x n 2D matrix representing an image.

// Rotate the image by 90 degrees (clockwise).

// Follow up:
// Could you do this in-place?


//My solution
//by swap

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        int len = matrix.size();
        
        for(int i = 0; i< len-1; i++)
            for(int j = 0;j < len-1-i;j++)
            {
                swap(matrix[i][j],matrix[len-1-j][len-1-i]);
            }
            
        for(int i = 0;i<=len/2-1; i++)
            for(int j=0;j<len;j++)
            {
                swap(matrix[i][j],matrix[len-1-i][j]);
            }
    }
    
    void swap(int& a, int& b)
    {
        a =a^b;
        b =a^b;
        a =a^b;
    }
};