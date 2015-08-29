// Implement a trie with insert, search, and startsWith methods.

// Note:
// You may assume that all inputs are consist of lowercase letters a-z.


//My Solution
class TrieNode {
    
    public TrieNode[] child = new TrieNode[26];
    public boolean isWordExist = false;
    
    // Initialize your data structure here.
    public TrieNode() {
        
    }
}

public class Trie {
    private TrieNode root;

    public Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    public void insert(String word) 
    {
        if(word == null || word.length() == 0 )
        {
            return;
        }
        
        TrieNode current = root;
        
        for(int i =0; i< word.length();i++)
        {
            int c = word.charAt(i) - 97 ;
            
            if(current.child[c] == null)
            {
                current.child[c] = new TrieNode();
            }
            
            current = current.child[c];
            
        }
        
        current.isWordExist = true;
        
    }

    // Returns if the word is in the trie.
    public boolean search(String word) 
    {
        if(word == null || word.length() == 0 )
        {
            return false;
        }
        
        TrieNode current = root;
        
        for(int i =0 ;i< word.length();i++)
        {
            int c = word.charAt(i) - 97;
            
            if(current.child[c] == null)
                return false;
            
            else
            {
                current = current.child[c];
            }
        }
        
        if(current.isWordExist)
           return true;
        else
           return false;
        
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    public boolean startsWith(String prefix) 
    {
        if(prefix == null || prefix.length() == 0 )
        {
            return false;
        }
        
        TrieNode current = root;
        
        for(int i =0 ;i< prefix.length();i++)
        {
            int c = prefix.charAt(i) - 97;
            
            if(current.child[c] == null)
                return false;
            
            else
            {
                current = current.child[c];
            }
        }
        
        return true;
        
    }
}

// Your Trie object will be instantiated and called as such:
// Trie trie = new Trie();
// trie.insert("somestring");
// trie.search("key");

