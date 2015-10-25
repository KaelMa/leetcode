// Isomorphic Strings My Submissions Question Solution 
// Total Accepted: 32941 Total Submissions: 126392 Difficulty: Easy
// Given two strings s and t, determine if they are isomorphic.

// Two strings are isomorphic if the characters in s can be replaced to get t.

// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

// For example,
// Given "egg", "add", return true.

// Given "foo", "bar", return false.

// Given "paper", "title", return true.

// Note:
// You may assume both s and t have the same length.


//My solution

class Solution {
public:
    bool isIsomorphic(string s, string t) 
    {
        if(s.empty() && t.empty())
            return true;
        
        if(s.size() != t.size())
            return false;
        
        unordered_map<char,char> sMap;
        
        for(int i = 0; i< s.size(); i++)
        {
            if(sMap.find(s[i]) != sMap.end())
            {
                if(sMap[s[i]] != t[i])
                    return false;
            }
            else
            {
                auto pos = find_if(sMap.begin(),sMap.end(),
                           [&](const unordered_map<char,char>::value_type& p)
                           {
                               return p.second == t[i];
                           });
                if(pos == sMap.end())
                {
                    sMap.insert({s[i],t[i]});
                }
                else
                    return false;
            }
        }
        
        return true;
        
    }
};