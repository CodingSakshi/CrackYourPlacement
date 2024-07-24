// Problem Link: https://leetcode.com/problems/word-search/


class Solution {
public:
    // DFS helper function to check if the word can be formed starting from board[i][j]
    bool solve(vector<vector<char>>& board, string word, int i, int j, int c) {
        if(c == word.size()) return true;
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() ||   // coditions for checking out of bounds indexes
            board[i][j] != word[c] || // condition for checking the unequality of character in string
            board[i][j] == '#')   // condition for checking if the character is already explored
            return false;  

        // Marking the current cell as visited by setting it to '#'
        char temp = board[i][j];
        board[i][j] = '#';
        bool result = (solve(board, word, i+1, j, c+1) ||
                    solve(board, word, i-1, j, c+1) ||
                    solve(board, word, i, j+1, c+1) ||
                    solve(board, word, i, j-1, c+1));

        // Restoring the current cell's original value after exploration
        board[i][j] = temp;
        return result;  
    }

    bool exist(vector<vector<char>>& board, string word) {
        // Iterating over each cell in the grid as a potential starting point
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(solve(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
};