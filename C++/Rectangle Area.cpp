Rectangle Area

Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

Rectangle Area
Assume that the total area is never beyond the maximum possible value of int.

Credits:
Special thanks to @mithmatt for adding this problem, creating the above image and all test cases.


//My solution

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) 
    {
        int width,height;
        
        if(E > C || G < A)
            width = 0;
        else
        {
            vector<int> temp{A,C,E,G};
            std::sort(temp.begin(),temp.end());
            width = temp[2] - temp[1];
        }
        
        if(B > H || D < F)
            height = 0;
        else
        {
            vector<int> temp{B,D,F,H};
            std::sort(temp.begin(),temp.end());
            height = temp[2] - temp[1];
        }
        
        int innerRect = width*height;
        
        int res = (C-A)*(D-B) + (G-E)*(H-F) - innerRect;
        
        return res;

        
    }
};