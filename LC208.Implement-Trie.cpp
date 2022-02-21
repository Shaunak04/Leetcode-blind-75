/* Problem-Statement:
A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
*/

class Trie 
{
private:
    // 2 data variables -> boolean LeafNode, Trie array children of size 26 
    bool is_leaf;
    Trie* children[26];
public:
    Trie()
    {
        this->is_leaf = false;
        for(int i=0;i<26;i++)
        {
            this->children[i] = NULL;
        }
    }
    
    void insert(string word) 
    {
        Trie* root = this;
        for( int i=0; i< word.length(); i++ )
        {
            int index = word[i] - 'a'; // 0-25
            if(root->children[index] == NULL)
            {
                root->children[index] = new Trie();
            }        
            root = root->children[index];
        }
        root->is_leaf = true;
    }
    
    bool search(string word) 
    {
        if(this==NULL) return false;
        
        Trie* root = this;
        for(int i=0; i<word.length();i++)
        {
            int index = word[i]-'a';
            root = root->children[index];
            if(root==NULL)
            {
                return false;
            }
        }
        return root->is_leaf;
    }
    
    bool startsWith(string prefix) 
    {
        if(this==NULL)
        {
            return false;
        }
        Trie* root=this;
        for(int i=0;i<prefix.length();i++)
        {
            int index = prefix[i]-'a';
            root = root->children[index];
            if(root==NULL) return false;
        }
        return true;
    }
};

// Time Complexity: O(n) for insertion, O(1) for searching
// Space Complexity: O(n*26) = O(n), n is number of words being inserted in the TRIE