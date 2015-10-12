// Nim Game

// You are playing the following Nim Game with your friend: There is a heap of stones on the table, each time one of you take turns to remove 1 to 3 stones. The one who removes the last stone will be the winner. You will take the first turn to remove the stones.

// Both of you are very clever and have optimal strategies for the game. Write a function to determine whether you can win the game given the number of stones in the heap.

// For example, if there are 4 stones in the heap, then you will never win the game: no matter 1, 2, or 3 stones you remove, the last stone will always be removed by your friend



//My solution

class Solution {
public:

    bool canWinNim(int n)
    {
        return !(n%4 == 0);
    }



    //dp- out of time 
     //f(n-1) && f(n-2) && f(n-3) == false
    // bool canWinNim(int n) 
    // {
    //     if(n <= 0)
    //         return false;
        
    //     if(n <=3)
    //         return true;
            
    //     vector<bool> f(n);
    //     f[0] = true, f[1] = true, f[2] = true;
        
    //     for(int i = 4; i<= n ; i++)
    //     {
    //         f[i] = !(f[i-1] && f[i-2] && f[i-3]);
    //     }
        
    //     return f[n-1];
        
    // }
};