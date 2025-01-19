//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
 void floodFillUtil(vector<vector<char>>& mat, int x, int y, char prevV, char newV, int M, int N)
    {
        // Base cases
        if (x < 0 || x >= M || y < 0 || y >= N)
            return;
        if (mat[x][y] != prevV)
            return;

        // Replace the color at (x, y)
        mat[x][y] = newV;

        // Recur for north, east, south, and west
        floodFillUtil(mat, x + 1, y, prevV, newV, M, N);
        floodFillUtil(mat, x - 1, y, prevV, newV, M, N);
        floodFillUtil(mat, x, y + 1, prevV, newV, M, N);
        floodFillUtil(mat, x, y - 1, prevV, newV, M, N);
    }

    vector<vector<char>> fill(vector<vector<char>>& mat) {
        int M = mat.size();
        int N = mat[0].size();

        // Step 1: Replace all 'O' with '-'
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (mat[i][j] == 'O') {
                    mat[i][j] = '-';
                }
            }
        }

        // Call floodFill for all '-' lying on edges
        for (int i = 0; i < M; i++) {   // Left side
            if (mat[i][0] == '-') {
                floodFillUtil(mat, i, 0, '-', 'O', M, N);
            }
        }

        for (int i = 0; i < M; i++) {   // Right side
            if (mat[i][N - 1] == '-') {
                floodFillUtil(mat, i, N - 1, '-', 'O', M, N);
            }
        }

        for (int i = 0; i < N; i++) {   // Top side
            if (mat[0][i] == '-') {
                floodFillUtil(mat, 0, i, '-', 'O', M, N);
            }
        }

        for (int i = 0; i < N; i++) {   // Bottom side
            if (mat[M - 1][i] == '-') {
                floodFillUtil(mat, M - 1, i, '-', 'O', M, N);
            }
        }

        // Step 3: Replace all '-' with 'X'
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (mat[i][j] == '-') {
                    mat[i][j] = 'X';
                }
            }
        }

        return mat;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];

        Solution ob;
        vector<vector<char>> ans = ob.fill(mat);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends