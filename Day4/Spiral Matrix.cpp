// Problem Link: https://leetcode.com/problems/spiral-matrix/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> ans;
        
        int firstRow = 0;
        int lastRow = row-1;
        int firstCol = 0;
        int lastCol = col-1;
        int n = row*col;
        int count = 0;
        while(count < n)
        {
            //for first row
            for(int i = firstCol; count < n && i <= lastCol; i++)
            {
                ans.push_back(matrix[firstRow][i]);
                count++;
            }
            firstRow++;
            //for last col
            for(int i = firstRow; count < n && i <= lastRow; i++)
            {
                ans.push_back(matrix[i][lastCol]);
                count++;
            }
            lastCol--;
            //for last row
            for(int i = lastCol; count < n && i >= firstCol; i--)
            {
                ans.push_back(matrix[lastRow][i]);
                count++;
            }
            lastRow--;
            //for first col
            for(int i = lastRow; count < n && i >= firstRow; i--)
            {
                ans.push_back(matrix[i][firstCol]);
                count++;
            }
            firstCol++;
            
        }

        return ans;
    }
};