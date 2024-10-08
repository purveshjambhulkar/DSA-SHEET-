class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

      

        int row = matrix.size();
        int col = matrix[0].size();

        vector<vector<int>> arr;
        

        for(int i = 0 ; i < col ; i++){

            vector<int> newrow;

            for(int j = row - 1 ; j >= 0 ; j--){
                newrow.push_back(matrix[j][i]);

            }
            arr.push_back(newrow);
        }

        matrix = arr;

        
    }
};