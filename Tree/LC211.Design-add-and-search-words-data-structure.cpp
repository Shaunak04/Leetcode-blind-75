/* Problem Statement:
Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:

WordDictionary() Initializes the object.
void addWord(word) Adds word to the data structure, it can be matched later.
bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. 
Word may contain dots '.' where dots can be matched with any letter.
*/

class WordDictionary {
private:
    class Trie
    {
        public:
            Trie* children[26];
            bool is_leaf = false;
    };
    Trie* root;
    
public:
    
    WordDictionary() 
    {
        root = new Trie();
    }
    
    void addWord(string word) 
    {
        Trie* curr = root;   
        for( int i=0; i< word.length(); i++ )
        {
            int index = word[i] - 'a';
            if(curr->children[index] == NULL)
            {
                curr->children[index] = new Trie();
            }        
            curr = curr->children[index];
        }
        curr->is_leaf = true;
        return;
    }

    
    bool search(string word, Trie* tempRoot = NULL) 
    {
        Trie* curr = nullptr;
        if(!tempRoot)
        {
            curr = root;
        }
        else
        {
            curr = tempRoot;
        }
        for(int i=0; i<word.size(); i++)
        {
            char currentChar = word[i];
            if(currentChar=='.')
            {
                for(int j=0; j<26; j++)
                {
                    if(curr->children[j]!=nullptr && search(word.substr(i+1, word.size()-i), curr->children[j]))
                    {
                        return true;
                    }
                }
                return false;
            }
            else
            {
                int index = currentChar-'a';
                if(curr->children[index]==nullptr) return false;
                curr = curr->children[index];
            }
        }
        return curr->is_leaf;
    }
};

// Time Complexity: 
// Space Complexity: 