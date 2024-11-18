//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
   bool isSafe(const vector<int>& board, int currRow,
                                      int currCol) {

    // Check all previously placed queens
    for(int i = 0; i < board.size(); ++i) {
        int placedRow = board[i];

        // Columns are 1-based
        int placedCol = i + 1;

        // Check if the queen is on the same diagonal
        if(abs(placedRow - currRow) == 
                          abs(placedCol - currCol)) {
            return false; // Not safe
        }
    }

    // Safe to place the queen
    return true; 
}

// Recursive function to generate all possible permutations
void nQueenUtil(int col, int n, vector<int>& board, 
  vector<vector<int>>& result, vector<bool>& visited) {

    // If all queens are placed, add into result
    if(col > n) {
        result.push_back(board);
        return;
    }

    // Try placing a queen in each row
    // of the current column
    for(int row = 1; row <= n; ++row) {

        // Check if the row is already used
        if(!visited[row]) {
            
            // Check if it's safe to place the queen
            if(isSafe(board, row, col)) {

                // Mark the row as used
                visited[row] = true; 

                // Place the queen
                board.push_back(row); 

                // Recur to place the next queen
                nQueenUtil(col + 1, n, board,
                             result, visited);

                // Backtrack: remove the queen
                board.pop_back(); 
                visited[row] = false; // Unmark row
            }
        }
    }
}

// Main function to find all distinct 
// result to the n-queens puzzle
vector<vector<int>> nQueen(int n) {
    vector<vector<int>> result; 

    // Current board configuration
    vector<int> board; 

    // Track used rows
    vector<bool> visited(n + 1, false); 

    // Start solving from the first column
    nQueenUtil(1, n, board, result, visited);
    return result; 
}

};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends