class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
            int a = 0;
            
    int row = matrix.size();
    int col = matrix[0].size();
    int start_row = 0 ;
    int end_col = col-1;
    int end_row = row - 1;
    int start_col = 0;

    vector<int> ans;

    while (a < row*col)
    {
       for (int i = start_col ;a < row*col && i <= end_col; i++)
       {
          ans.push_back(matrix[start_row][i]);
          a++;
       }

       start_row++;

       for(int i = start_row ;a < row*col && i <= end_row ; i++){
        ans.push_back(matrix[i][end_col]);
        a++;
       } 

       end_col--;

       for(int i = end_col ;a < row*col && i >= start_col ; i-- ){
        ans.push_back(matrix[end_row][i]);
        a++;
       }

       end_row--;

       for(int i = end_row ; a < row*col && i >= start_row ;i--){
        ans.push_back(matrix[i][start_col]);
        a++;
       } 

       start_col++;


       
    }
    return ans;

        
        
    }
};


