// Problem Link: https://leetcode.com/problems/game-of-life/


class Solution {
public:
    void gameOfLife(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int count = 0;

        //First two loop is used for traversing each element
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                count  = 0;
                //Below two loop is used to iterate neighbouring elements
                for(int x = max(0, i-1); x <= min(rows-1, i+1); x++)
                {
                    for(int y = max(0, j-1); y <= min(cols -1, j+1); y++)
                    {
                        if((x!= i || y !=j) && matrix[x][y] % 2 == 1) count++;
                    }    
                }

                if(matrix[i][j] % 2 != 1 && count == 3) matrix[i][j]+=2;
                else if(matrix[i][j] % 2 == 1)
                {
                    //if(count < 2) matrix[i][j]=0;
                    //if(count > 3) matrix[i][j]=0;
                    if(count == 2 || count == 3) matrix[i][j]+=2;
                } 
                else matrix[i][j] = matrix[i][j]; 
                cout<<matrix[i][j]<<endl;             
            }
        }
        cout<<endl<<endl;
       // matrix = m;
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(matrix[i][j] == 1 || matrix[i][j] == 0) matrix[i][j] = 0;
                if(matrix[i][j] == 2 || matrix[i][j] == 3) matrix[i][j] = 1;

            }
        }
    }
};



