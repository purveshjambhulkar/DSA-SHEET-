//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
 
    // Function to find the number of islands.
    void isLandUtil(vector<vector<char>>& grid, int row, int col, vector<vector<bool>>& visited, int i, int j) {
        // Check if the current cell is within bounds and is land ('1') and not yet visited
        if (i < 0 || i >= row || j < 0 || j >= col || visited[i][j] || grid[i][j] == '0') {
            return;
        }

        // Mark the cell as visited
        visited[i][j] = true;

        // Recursive calls for all 8 directions
        isLandUtil(grid, row, col, visited, i + 1, j);     // Down
        isLandUtil(grid, row, col, visited, i - 1, j);     // Up
        isLandUtil(grid, row, col, visited, i + 1, j + 1); // Down-Right
        isLandUtil(grid, row, col, visited, i + 1, j - 1); // Down-Left
        isLandUtil(grid, row, col, visited, i, j + 1);     // Right
        isLandUtil(grid, row, col, visited, i, j - 1);     // Left
        isLandUtil(grid, row, col, visited, i - 1, j + 1); // Up-Right
        isLandUtil(grid, row, col, visited, i - 1, j - 1); // Up-Left
    }

    int numIslands(vector<vector<char>>& grid) {
        int numI = 0;
        int row = grid.size();
        int col = grid[0].size();

        // Initialize the visited array
        vector<vector<bool>> visited(row, vector<bool>(col, false));

        // Traverse through the grid to find all the islands
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                // If the current cell is land and not visited, it is the start of a new island
                if (grid[i][j] == '1' && !visited[i][j]) {
                    numI++;  // Increment the island count
                    // Call DFS to mark all cells of the island as visited
                    isLandUtil(grid, row, col, visited, i, j);
                }
            }
        }
        return numI;  // Return the total number of islands
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends