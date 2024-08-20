//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> antiDiagonalPattern(vector<vector<int>> matrix) 
    {
        // Code here
        vector<int> result;
        int n = matrix.size();
        for(int i = 0 ; i < n ; i++ ){
            int row = 0;
            int col = i;
            
            while(row < n && col >= 0){
                result.push_back(matrix[row][col]);
                row++;
                col--;
            }
        }
        
        for(int i = 1; i < n ;i++){
            int row = i;
            int col = n-1;
              while(row < n && col >= 0){
                result.push_back(matrix[row][col]);
                row++;
                col--;
            }
            
            }
            
            return result;
    }
    
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix;
        matrix.resize(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> ans = ob.antiDiagonalPattern(matrix);
        for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends