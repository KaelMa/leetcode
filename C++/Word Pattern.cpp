
// Word Pattern My Submissions Question Solution 
// Total Accepted: 10345 Total Submissions: 39446 Difficulty: Easy
// Given a pattern and a string str, find if str follows the same pattern.

// Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

// Examples:
// pattern = "abba", str = "dog cat cat dog" should return true.
// pattern = "abba", str = "dog cat cat fish" should return false.
// pattern = "aaaa", str = "dog cat cat dog" should return false.
// pattern = "abba", str = "dog dog dog dog" should return false.
// Notes:
// You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.

// Credits:
// Special thanks to @minglotus6 for adding this problem and creating all test cases


class Solution {
public:
    bool wordPattern(string pattern, string str) 
    {
        if(pattern.empty())
            return false;
        
        vector<string> strVec;
        int i = 0;
        while(i < str.size())
        {
            while(str[i] == ' ' && i<str.size())
                i++;
            string temp;
            while(str[i] !=' ' && i<str.size())
            {
                temp.push_back(str[i]);
                i++;
            }
            
            strVec.push_back(temp);
        }
        
        if(pattern.size() != strVec.size())
            return false;
        
        unordered_map<char,string> patMap;
        
        for(int i = 0 ; i<pattern.size();i++)
        {
            auto pos = patMap.find(pattern[i]);
            if(pos == patMap.end())
            {
                auto r = find_if(patMap.begin(),patMap.end(),
                [&](const unordered_map<char,string>::value_type& p){ return p.second.compare(strVec[i]) == 0; });
                
                if(r == patMap.end())
                {
                    patMap.insert({pattern[i],strVec[i]});
                }
                else
                    return false;
                
            }
            else
            {
                if(pos->second.compare(strVec[i]) != 0)
                    return false;
            }
        }
        
        return true;
        
        
        
        
    }
};