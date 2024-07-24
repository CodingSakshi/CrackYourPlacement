// Problem Link: https://leetcode.com/problems/word-search-ii/

// Approach1: (Will give TLE)
class Solution {
public:
    bool solve(vector<vector<char>>& board, string word, int i, int j, int c) {
        if(c == word.size()) return true;
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[c] || board[i][j] == '#') return false;

        char temp = board[i][j];
        board[i][j] = '#';
        bool result = (solve(board, word, i+1, j, c+1) || solve(board, word, i-1, j, c+1) || solve(board, word, i, j+1, c+1) || solve(board, word, i, j-1, c+1));  
        board[i][j] = temp;

        return result;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;

        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size();j++) {
                for(int k=0; k < words.size(); k++) {
                    cout << words[k] << ' ';
                    if(solve(board, words[k], i, j, 0)) {
                        ans.push_back(words[k]);
                        words.erase(words.begin() + k);
                    }
                    
                }
                for(auto it = words.begin(); it != words.end();) {
                    if(solve(board, *it, i, j, 0)) {
                        ans.push_back(*it);
                        it=words.erase(it);
                    }
                    else ++it;
                }
            }
        }

        return ans;
    }
};


// Appraoch2: Using trie Ds
class TrieNode {
public:
    bool isEnd;
    unordered_map<char, TrieNode*> children;
    TrieNode() {
        isEnd = false;
    }
};

class Solution {
public:
    TrieNode* root;

    Solution() {
        root = new TrieNode();
    }

    void insertWord(const string& word) {
        TrieNode* currentNode = root;
        for (char ch : word) {
            if (currentNode->children.find(ch) == currentNode->children.end()) {
                currentNode->children[ch] = new TrieNode();
            }
            currentNode = currentNode->children[ch];
        }
        currentNode->isEnd = true;
    }

    void searchWords(vector<vector<char>>& board, set<string>& foundWords, TrieNode* currentNode, int row, int col, string& currentWord) {
        if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || board[row][col]=='#') return;

        char currentChar = board[row][col];
        if (currentNode->children.find(currentChar) == currentNode->children.end()) return;

        currentWord.push_back(currentChar);
        currentNode = currentNode->children[currentChar];

        if (currentNode->isEnd) foundWords.insert(currentWord);

        char temp = board[row][col];
        board[row][col] = '#';
        searchWords(board, foundWords, currentNode, row + 1, col, currentWord);
        searchWords(board, foundWords, currentNode, row - 1, col, currentWord);
        searchWords(board, foundWords, currentNode, row, col + 1, currentWord);
        searchWords(board, foundWords, currentNode, row, col - 1, currentWord);
        board[row][col] = temp;

        currentWord.pop_back();
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (const string& word : words) {
            insertWord(word);
        }

        set<string> foundWords;
        string currentWord = "";
        int numRows = board.size();
        int numCols = board[0].size();

        for (int row = 0; row < numRows; ++row) {
            for (int col = 0; col < numCols; ++col) {
                searchWords(board, foundWords, root, row, col, currentWord);
            }
        }

        return vector<string>(foundWords.begin(), foundWords.end());
    }
};