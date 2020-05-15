class Trie {
    /** Initialize your data structure here. */
    private:
        static const int ALPHABET_SIZE = 26;
    
        struct TrieNode
        {
            struct TrieNode *children[ALPHABET_SIZE];
            // isEndOfWord is true if the node represents end of a word
            bool isEndOfWord;
            
            public: TrieNode(){
                isEndOfWord = false;
                for(int i = 0; i < ALPHABET_SIZE; i += 1){
                    children[i] = NULL;
                }
            }
        };
    
        TrieNode *root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        
        struct TrieNode *tempNode = root; 
  
        for(int i = 0; i < word.size(); i += 1) 
        { 
            int index = word[i] - 'a'; 
            if(!tempNode->children[index]) 
                tempNode->children[index] = new TrieNode(); 
  
            tempNode = tempNode->children[index]; 
        } 
  
        // Mark last node as leaf by making isEndOfWord as true 
        tempNode->isEndOfWord = true;
        
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        struct TrieNode *tempNode = root; 
  
        for(int i = 0; i < word.size(); i += 1) 
        { 
            int index = word[i] - 'a'; 
            if(!tempNode->children[index]) 
                return false; 
  
            tempNode = tempNode->children[index]; 
        } 
  
        return (tempNode != NULL && tempNode->isEndOfWord);
        
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        struct TrieNode *tempNode = root;
        
        for(int i = 0; i < prefix.size(); i += 1) 
        { 
            int index = prefix[i] - 'a'; 
            if(!tempNode->children[index]) 
                return false; 
  
            tempNode = tempNode->children[index]; 
        } 
        
        return true;
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */