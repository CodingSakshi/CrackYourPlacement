// Problem Link: 


class TrieNode {
    public:
    bool isEnd;
    map<char, TrieNode*> children;

    TrieNode() {
        isEnd = false;
    }
};

class Trie {
    TrieNode *root;

    public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *temp = root;
        for(auto i : word) {
            if(temp->children.find(i) == temp->children.end()) {
                temp->children[i] = new TrieNode;
            }
            temp=temp->children[i];
        }
        temp->isEnd=true;
    }
    
    bool search(string word) {
        TrieNode *temp = root;
        for(auto i : word) {
            if(temp->children.find(i) == temp->children.end()) {
                return false;
            }
            temp=temp->children[i];
        }
        return temp->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode *temp = root;
        for(auto i : prefix) {
            if(temp->children.find(i) == temp->children.end()) {
                return false;
            }
            temp=temp->children[i];
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